## Установка программ

### Установка DOSBox

Устанавливаем [DOSBox](https://www.dosbox.com/).

### Установка foxprox
1. Копируем `U:/VT&PM/EU_EI/PIN/arm_f26/ARJ.EXE` в `r:/gpif_/`.
1. Копируем `U:/VT&PM/EU_EI/PIN/arm_f26/А.ARJ` в `r:/gpif_/`.
1. Копируем `U:/VT&PM/EU_EI/PIN/arm_f26/А.A01` в `r:/gpif_/`.
1. Копируем `U:/VT&PM/EU_EI/PIN/arm_f26/А.A02` в `r:/gpif_/`.
1. Открываем DOSBox
    ```
    mount r: r:\
    r:
    cd gpif_

    arj x f -v
    n
    n
    y
    y
    ```
1. Закрываем DOSBox и отрываем DOSBox
    ```
    mount r: r:\
    r:
    cd gpif_

    foxprox
    ```
---

## Руссификация DOSBOX на Windows

1. Открываем пуск.
1. Открываем папку `DOSBox@`, затем папку `DOSBox @ Options` (где значок `@` - это версия).
1. Меняем строку в файле `dosbox@.conf` (где значок `@` - это версия):
    ```conf
    [dos]
    #keyboardlayout=auto
    keyboardlayout=ru
    ```

Теперь в проекте `ASBF0422` отображается русский текст вместо кракозябр.
Но покачто русский ввод не доступен (не работает `Alt` + `Shift`), так как нужно установить драйвера.

---

## Автоматический старт foxpro, когда открываем DOSBOX

1. Открываем пуск.
1. Открываем папку `DOSBox@`, затем папку `DOSBox @ Options` (где значок `@` - это версия).
1. Меняем строку в файле `dosbox@.conf` (где значок `@` - это версия):
    ```conf
    [autoexec]
    mount r: r:\
    r:
    cd FPD26
    foxpro
    ```

---

## Переименование проекта `ASBF0422`

### Переименовываем файлы `ASBF_*` на `GPIF_*`.

1. Разархивируем `ASBF0422.ARJ` в папку `GPIF_`.
1. В папке `r:/gpif_/GPIF_` запускаем команду `python3 ../gpi_autorename.py`.
Этот скрипт переименует автоматически файлы

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

### Переименовываем русские символы `=Фамилия И. О.=`, используя foxpro скрины

...

---

## Установка драйвера для ввода русских букв

...
