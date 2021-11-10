## Установка программ

1. Устанавливаем [DOSBox](https://www.dosbox.com/).
1. Копируем `U:/VT&PM/EU_EI/PIN/arm_f26/F.ARJ/*` в `r:/fiof_/foxpro`.

---

## Руссификация DOSBOX на Windows

1. Открываем пуск
1. Открываем папку `DOSBox@`, затем папку `DOSBox @ Options` (где значок `@` - это версия).
1. Меняем строку в файле `dosbox@.conf` (где значок `@` - это версия):
    ```conf
    [dos]
    #keyboardlayout=auto
    keyboardlayout=ru
    ```

Теперь в проекте `ASBF0422` работает русский текст.

---

## Автоматический старт foxpro, когда открываем DOSBOX

1. Открываем пуск
1. Открываем папку `DOSBox@`, затем папку `DOSBox @ Options` (где значок `@` - это версия).
1. Меняем строку в файле `dosbox@.conf` (где значок `@` - это версия):
    ```conf
    [autoexec]
    mount r: r:\
    r:
    cd FPD26
    foxpro
    ```
