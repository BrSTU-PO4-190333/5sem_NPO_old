## Убрать кракозябры в DOSBox

[На главную](../README.md)

1. Заходим в папку с `DOSBox` и запускаем `DOSBox 0.74-3 Options.bat`.
1. Откроется текстовый файл.
1. Ищем строки
    ```
    [dos]
    keyboardlayout=auto
    ```

    Заменяем `auto` на `ru`
    ```
    [dos]
    #keyboardlayout=auto
    keyboardlayout=ru
    ```
1. Открываем DOSBox.
1. Прописываем команды в `DOSBox`:
    ```bash
    mount r: r:\
    r:
    cd FIOF_            # Вот та папка fiof_
    foxprox
    ```
1. При открытии `foxprox` жмем на кнопку `< Cancel >`.
1. Теперь в `foxprox` в проекте `ABSF0422` нет кракозябр.
1. Работаем в `foxprox`.
