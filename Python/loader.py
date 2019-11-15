#!/usr/bin/env python3
# -*- coding: utf-8 -*-
import time
import json
from urtx.urtxserial import SerialUrtx
import lcdcodec
import sys
import getopt
import threading
import tqdm

configFilePath = 'conf.json'       # путь до файла конфигурации
speexFilePath = 'audio.wav'        # путь до speex файла
speexFileHeadSize = 0     # размер заголовка спиксового файла в байтах
portPath = "COM3"   # порт и
baud = 19200                 # боды по умолчанию
textCodec = "utf-8"


""" чтение опций с коммандной строки """
try:
    opts, _ = getopt.getopt(sys.argv[1:], "hc:s:p:b:t:", ["help", "configfile=", "speexfile=", "port=", "baudrate=", "textcodec="])
    for opt, arg in opts:
        if (opt == '-h') or (opt == "--help"):
            print("Используйте: \n", sys.argv[0] + """ -c <configfilepath> -s <speexfilepath> \n\t -p <port> -b <baudrate> \n\t"""
                                                   """ --configfile=<configfilepath> --speexfile=<speexfilepath> \n\t"""
                                                   """ --port=<port> --baudrate=<baudrate>""")
            sys.exit(0)
        elif (opt == '-c') or (opt == "--configfile"):
            configFilePath = arg
        elif (opt == '-s') or (opt == "--speexfile"):
            speexFilePath = arg
        elif (opt == '-p') or (opt == "--port"):
            portPath = arg
        elif (opt == '-b') or (opt == "--baudrate"):
            baud = arg
        elif (opt == '-t') or (opt == "--textcodec"):
            baud = arg
except getopt.GetoptError:
    print("Используйте: \n", sys.argv[0] + " --help")
    sys.exit(2)

if configFilePath is None:
    print("Не был указан конфигурационный файл, используйте: \n ",
          sys.argv[0] + " -c <configfilepath> -s <speexfilepath>")
    sys.exit(2)

if speexFilePath is None:
    print("Не был указан speex файл, используйте: \n", sys.argv[0] + " -c <configfilepath> -s <speexfilepath>")
    sys.exit(2)

""" Проверка наличия файлов """
data = {}
try:
    with open(configFilePath, "r", encoding='utf-8') as file:
        data.update(json.load(file))
except FileNotFoundError:
    print(configFilePath, ": такого файла не найдено")
    sys.exit(2)

try:
    with open(speexFilePath, 'rb') as file:
        file.seek(speexFileHeadSize)
        data.update({"speex": file.read()})
except FileNotFoundError:
    print(speexFilePath, ": такого файла не найдено")
    sys.exit(2)


ser = SerialUrtx()

ack = threading.Event()     # блокировщик основного потока
ackCode = None      # код ошибки, приходящий с платы


def loadPackage(desc, data):
    """ загружает данные, пока не придет подтверждение с платы """
    global ackCode
    while True:
        ser.sendPackage(desc, data)     # отправляем пакет и ждем
        ack.wait()  # ждем, пока не придет ответ
        ack.clear()     # снимаем флаг
        if ackCode == 0:    # если пришел 0 - сообщение доставлено
            break
        elif ackCode == 1:  # если пришла 1 - сообщение не доставлено
            continue


def recvFeedBack(data):
    """ обратная связь с платы  """
    global ackCode
    ackCode = data[0]
    ack.set()


def splitSpeex(s, tokensize=20):
    """ разбиваем строку на токены по 20 символов, лишнее выбрасываем """
    return list(map(lambda a: bytes(a), zip(*[iter(s)]*tokensize)))


ser.subscribe(4, recvFeedBack)      # подключаемся к обработчику
ser.connect(portPath, baud)   # подключаемся к порту
ser.start()

if data.get("state"):
    print("\nstate send...")
    time.sleep(0.1)
    pbar = tqdm.tqdm(total=1)
    loadPackage(1, (data["state"],))
    pbar.update(1)
    pbar.close()

if data.get("texts"):
    print("\ntexts send...")
    time.sleep(0.1)
    pbar = tqdm.tqdm(total=len(data["texts"]))
    for idx, text in enumerate(data["texts"]):
        btext = lcdcodec.lcdDecode(text)
        if len(btext) > 99:
            raise ValueError("Длина строки: " + text + "слишком большая")
        else:
            btext = btext + b'\n'
            btext = btext.ljust(100, b'\x00')
            loadPackage(2, bytes([idx]) + btext)
            pbar.update(1)
    pbar.close()

data["speex"] = splitSpeex(data["speex"], tokensize=20)

print("\nspeex send...")
time.sleep(0.1)
pbar = tqdm.tqdm(total=len(data["speex"]))
for token in data["speex"]:
    loadPackage(3, token)
    pbar.update(1)

pbar.close()

print("\nwaiting disconnection...")
loadPackage(4, (0, ))   # сообщение об окончании связи
print("done!")
time.sleep(1)
ser.exit()
