## Task

**БК** (BD) - Базовый Каталог (Base Directory).

```conf
BD=U:/VT&PM/EU_EI/PIN
```

```yml
volumes:
    - ./../fioc_/ikgMtc.c:${BD}/ikgMtc.TXL  # task
```

Read [the task](ikgMtc.c) (in the encoding `CP 866`).

- [x] [gpi_01h](gpi_01h.c) - Создание простейшей программы.
- [x] [gpi_02op](gpi_02op.c) - Объявление переменных.
- [x] [gpi_03c](gpi_03c.c) - Работа в цикле.
- [x] [gpi_04m](gpi_04m.c) - Работа с массивами в цикле.
- [ ] [gpi_05m3](gpi_05m3.c) - Работа с массивами в нескольких циклах.
- [x] [gpi_06s](gpi_06s.c) - Объявление структур.
- [ ] [gpi_07ms](gpi_07ms.c) - Работа с массивом структур в цикле.
- [ ] [gpi_08d](gpi_08d.c) - Использование #define.
- [ ] [gpi_09i](gpi_09i.c) - Использование #include пользователя.
- [ ] [gpi_10fn](gpi_10fn.c) - Использование функции пользователя.
- [ ] [gpi_11f](gpi_11f.c) - Фильтр по условию.
- [ ] [gpi_12fw](gpi_12fw.c) - Вывод в файл.
- [ ] [gpi_13fr](gpi_13fr.c) - Чтение файла.
- [ ] [gpi_14fc](gpi_14fr.c) - Копирование файла.
- [ ] [gpi_15fp](gpi_15fp.c) - Позиционирование в файле.
- [ ] [gpi_16fp](gpi_16fp.c) - Реализация проекта.

## How to install

1. Download the compiler [MinGW](https://sourceforge.net/projects/mingw/)
1. In the installer (MinGW), select the items:
    - [x] mingw-developer-toolkit
    - [x] mingw32-base
    - [ ] mingw32-gcc-ada
    - [ ] mingw32-gcc-fortan
    - [x] mingw32-gcc-g++
    - [ ] mingw32-gcc-objc
    - [x] msys-base
1. Download the program [Geany](https://geany.org/)

## Opening the project

1. Press the button `File`.
1. Press the button `Open`.
1. Go to the `fioc_` folder.
1. Press the keys `Ctrl` + `A`.
1. Press the button `Open`.

> ## Read the task through the program Geany
>
> 1. Opening the file `ikgMtc.c`.
> 1. Press the button `File`.
> 1. Press the button `Reload As`.
> 1. Press the button `East European`.
> 1. Press the button `Cyrillic/Russian (CP866)`.
> 1. Read the file `ikgMtc.c`, and we do laboratory work.

## How to compile a project

1. Open the project in `Geany`.
1. Open the file `*.c`.
1. Press the button `Compile`.
1. Press the button `Build`.
1. Press the button `Execute`.
