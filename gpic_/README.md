## Установка программ

1. Скачиваем компилятор [MinGW](https://sourceforge.net/projects/mingw/)
1. В компиляторе (MinGW) выбираем галочки при установке:
    - [x] mingw-developer-toolkit
    - [x] mingw32-base
    - [ ] mingw32-gcc-ada
    - [ ] mingw32-gcc-fortan
    - [x] mingw32-gcc-g++
    - [ ] mingw32-gcc-objc
    - [x] msys-base
1. Скачиваем редактор кода [Geany](https://geany.org/)
1. Здание скопировал из `U:/VT&PM/EU_EI/PIN/ikg_/ikgMtc.TXL` в файл `r:/gpic_/ikgMtc_cp866.txt`.

---

## Задание

- Прочесть [задание (в кодировке cp866)](ikgMtc_cp866.txt).
- прочесть [задание (в кодировке utf8)](ikgMtc_utf8.txt).

---

## Что надо

- [x] [gpi_01h.c](gpi_/gpi_01h.c) -
    Создание простейшей программы.
- [x] [gpi_02op.c](gpi_/gpi_02op.c) -
    Объявление переменных.
- [x] [gpi_03c.c](gpi_/gpi_03c.c) -
    Работа в цикле.
- [x] [gpi_04m.c](gpi_/gpi_04m.c) -
    Работа с массивами в цикле.
- [x] [gpi_05m3.c](gpi_/gpi_05m3.c) -
    Работа с массивами в нескольких циклах.
- [x] [gpi_06s.c](gpi_/gpi_06s.c) -
    Объявление структур.
- [ ] [gpi_07ms.c](gpi_/gpi_07ms.c) -
    Работа с массивом структур в цикле.
- [ ] [gpi_08d.c](gpi_/gpi_08d.c) -
    Использование `#define`.
- [ ] [gpi_09i.c](gpi_/gpi_09i.c), [gpi_09i.h](gpi_/gpi_09i.h) -
    Использование `#include` пользователя.
- [ ] [gpi_10fn.c](gpi_/gpi_10fn.c) -
    Использование функции пользователя.
- [ ] [gpi_11f.c](gpi_/gpi_11f.c) -
    Фильтр по условию.
- [ ] [gpi_12fw.c](gpi_/gpi_12fw.c), [gpi_12xx](gpi_/gpi_12xx) -
    Вывод в файл.
- [ ] [gpi_13fr.c](gpi_/gpi_13fr.c) -
    Чтение файла.
- [ ] [gpi_14fc.c](gpi_/gpi_14fc.c), [gpi_14xx](gpi_/gpi_14xx) -
    Копирование файла.
- [ ] [gpi_15fp.c](gpi_/gpi_15fp.c) - Позиционирование в файле.
- [ ] [gpi_16fp.c](gpi_/gpi_16fp.c) - Реализация проекта.

---

## Отрываем проект в `Geany`

1. Жмем `File` > `Open`.
1. Выбираем `r:/gpic_/gpi_`.
1. Зажимаем `Ctrl` + `A`, для того, чтобы выбрать все файлы.
1. Жмем кнопку `Open`.

---

## Открываем файл в русской кодировке в `Geany`

1. Жмем `File`.
1. Жмем `Reload As`.
1. Жмем `East European`.
1. Жмем `Cyrillic/Russian (CP866)`.

---

## Компилируем файл `*.c` в `Geany`

1. Нужно, чтобы файл `*.c` был открыт для редактирования в `Geany`.
1. Жмем `Compile`.
1. Жмем `Build`.
1. Жмем `Execute`.
