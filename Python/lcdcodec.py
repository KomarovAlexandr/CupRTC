lcdCyrillic = {
    "А": 0x41,
    "Б": 0xA0,
    "В": 0x42,
    "Г": 0xA1,
    "Д": 0xE0,
    "Е": 0x45,
    "Ё": 0xA2,

    "Ж": 0xA3,
    "З": 0xA4,
    "И": 0xA5,
    "Й": 0xA6,
    "К": 0x4B,
    "Л": 0xA7,
    "М": 0x4D,

    "Н": 0x48,
    "О": 0x4F,
    "П": 0xA8,
    "Р": 0x50,
    "С": 0x43,
    "Т": 0x54,
    "У": 0xA9,

    "Ф": 0xAA,
    "Х": 0x58,
    "Ц": 0xE1,
    "Ч": 0xAB,
    "Ш": 0xAC,
    "Щ": 0xE2,
    "Ъ": 0xAD,

    "Ы": 0xAE,
    "Ь": 0x62,
    "Э": 0xAF,
    "Ю": 0xB0,
    "Я": 0xB1,

    "а": 0x61,
    "б": 0xB2,
    "в": 0xB3,
    "г": 0xB4,
    "д": 0xE3,
    "е": 0x65,
    "ё": 0xB5,

    "ж": 0xB6,
    "з": 0xB7,
    "и": 0xB8,
    "й": 0xB9,
    "к": 0xBA,
    "л": 0xBB,
    "м": 0xBC,

    "н": 0xBD,
    "о": 0x6F,
    "п": 0xBE,
    "р": 0x70,
    "с": 0x63,
    "т": 0xBF,
    "у": 0x79,

    "ф": 0xE4,
    "х": 0x78,
    "ц": 0xE5,
    "ч": 0xC0,
    "ш": 0xC1,
    "щ": 0xE6,
    "ъ": 0xC2,

    "ы": 0xC3,
    "ь": 0xC4,
    "э": 0xC5,
    "ю": 0xC6,
    "я": 0xC7
}


def lcdDecode(text):
    out = b''
    for c in text:
        if lcdCyrillic.get(c) is not None:  # кириллица
            out += bytes([lcdCyrillic[c]])
        else:  # латиница
            out += bytes(c, "utf-8")
    return out


if __name__ == '__main__':
    print(lcdDecode("Adfsdфыафыс ффы"))
    print(lcdDecode("АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдеёжзийклмнопрстуфхцчшщъыьэюя"))
