## Отркытие чужого проекта в foxprox

[На главную](../README.md)

1. В свою папку `fiof_` копируем файл `U:/VT&PM/EU_EI/PIN/bdd/ASB0F0422.ARJ`.
1. Прописываем команды в `DOSBox`:
    ```bash
    mount r: r:\
    r:
    cd FIOF_            # Вот та папка fiof_
    arj x ASB0F0422 -v  # Тут мы разархировали, где F - это наш архив ASB0F0422.ARJ, arj - это ARJ.EXE. 
    foxprox
    ```
1. При открытии `foxprox` жмем на кнопку `< Cancel >`.
1. Работаем в `foxprox`.
