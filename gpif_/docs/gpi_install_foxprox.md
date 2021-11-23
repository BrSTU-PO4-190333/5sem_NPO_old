## Установка foxprox

[На главную](../README.md)

1. В свою папку `fiof_` копируем файл `U:/VT&PM/EU_EI/PIN/arm_f26/ARJ.EXE`.
1. В свою папку `fiof_` копируем файл `U:/VT&PM/EU_EI/PIN/arm_f26/F.ARJ`.
1. В свою папку `fiof_` копируем файл `U:/VT&PM/EU_EI/PIN/arm_f26/F.A01`.
1. В свою папку `fiof_` копируем файл `U:/VT&PM/EU_EI/PIN/arm_f26/F.A02`.
1. Открываем `DOSBox`.
1. Прописываем команды в `DOSBox`:
    ```bash
    mount d: d:\
    d:
    cd GPI_NPO5     # лутше такую папку не иметь, а хранить fiof_ в корне диска
    cd GPIF_        # лутше такую папку не иметь, а хранить fiof_ в корне диска
    cd FIOF_        # вот та папка fiof_
    arj x F -v      # где F - это наш архив F.ARJ, arj - это ARJ.EXE
    n
    n
    y
    y
    foxprox
    ```
    
    ![](gpi_install_foxprox.png)

    ![](gpi_install_foxprox2.png)

    ![](gpi_install_foxprox3.png)

    ![](gpi_install_foxprox4.png)

    ![](gpi_install_foxprox5.png)

    ![](gpi_install_foxprox6.png)

1. При открытии `foxprox` жмем на кнопку `< Cancel >`.

    ![](gpi_install_foxprox7.png)
1. Работаем в `foxprox`.

    ![](gpi_install_foxprox8.png)
