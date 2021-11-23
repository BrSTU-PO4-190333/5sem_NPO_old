## Меню

- [Установка DOSBox](docs/gpi_install_dosbox.md)
- [Установка FoxProx](docs/gpi_install_foxprox.md)
- [Читаем задание по foxprox](docs/gpi_read_task.md)
- [Копирование проекта ASBF0422](docs/gpi_open_foxprox_project.md)
- [Убрать кракозябры в DOSBox](docs/gpi_rus_dosbox.md)
- [Переключаться на русскую клавиатуру в DOSBox](docs/gpi_rus_keyboard_dosbox.md)
- [Автостарт foxprox из DOSBox](docs/gpi_autostart_foxprox_in_dosbox.md)

---

## Переименование проекта `ASBF0422`

### Переименовываем файлы
1. Открываем DOSBox
    ```
    mount r: r:\
    r:
    cd gpif_\FIOF_
    ```
1. Разархивируем `ASBF0422.ARJ`
    ```
    ..\arm_f26\arj x ASBF0422 -v
    ```
1. Запускаем python скрипт,
    который переменует `ASBF_*` файлы на `FIOF_*`
    (поменять `FIOF_` можно в коде python)
    ```
    r:
    cd r:\gpif_\FIOF_
    python gpi_autorename.py
    ```

### Переименование переменных в файлах через notepad++

1. Скачиваем и устанавливаем [notepad++](https://notepad-plus-plus.org/)
1. Жмем `Files` > `Find in Files`
1. Выбираем `Directory: \/ ...` нашу папку `r:/gpif_/GPIF_`
1. Заполняю поле `Find what:` значение `ASB`
1. Заполняю поле `Replace with:` значением `GPI`
1. Ставлю галочку `Match case`
1. Кликаем на кнопку `Replace in files`
1. Заполняю поле `Find what:` значение `Asb`
1. Заполняю поле `Replace with:` значением `Gpi`
1. Кликаем на кнопку `Replace in files`
1. Заполняю поле `Find what:` значение `Asb`
1. Заполняю поле `Replace with:` значением `Gpi`
1. Кликаем на кнопку `Replace in files`

### Переименовываем скрины

1. Запускаем DOSBox и foxprox
    ```
    mount r: r:\
    r:
    cd gpif_\foxprox
    foxprox
    ```
1. Жмем `< Cancel >`.
1. Жмем `File`.
1. Жмем `Open...`.
1. Вместо `Database type` выбираем `Screen type`.
1. В окне Open жмем `[..]`.
1. В окне Open жмем `[GPIF_]`.
1. В окне Open жмем `[GPIF_*.SCX]`.
1. Жмем два раза на `=Фамилия И. О.=`
1. Жмем `< Cancel >`
1. С помощью `Shift` + `<---` выделяем `Фамилия И. О.` и пишем свою.
1. Если пишет на английском и нужен русский, то жмем `Alt` + `Правый Shift`.
    Если пишет на русском и нужен английский, то жмем `Alt` + `Левый Shift`.
1. Как поменяли `Фамилия И. О.` жмём `Program`
1. Жмем `Generate...`.
1. Жмем `о   Yes   п`.
1. Жмем `о Generate п`.
1. Жмем `<   Yes   >`.
1. Проверяем. Жмём `Program`.
1. Жмём `Do...`.
1. Жмём на переименованный `GPIF_*.SPR`.
