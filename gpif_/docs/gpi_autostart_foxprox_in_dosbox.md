## Автостарт foxprox из DOSBox

[На главную](../README.md)

1. Заходим в папку с `DOSBox` и запускаем `DOSBox 0.74-3 Options.bat`.
1. Откроется текстовый файл.
1. Ищем строки
    ```
    [autoexec]
    ```

    Прописываем
    ```
    [autoexec]
    mount r: r:\
    r:
    cd GPIF_
    foxprox
    ```
1. Открываем DOSBox.
1. Автоматически выполняются команды - и запустился foxprox.
1. При открытии `foxprox` жмем на кнопку `< Cancel >`.
1. Работаем в `foxprox`.
