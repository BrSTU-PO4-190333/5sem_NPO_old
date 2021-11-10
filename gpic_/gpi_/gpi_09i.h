#ifndef _GPI_09I_H_
    #define _GPI_09I_H_
    
    #define gpi_Product_length 100
    struct gpi_Product
        {
        char	gpi_n[10];          /* Наименование */
        int		gpi_c;				/* Цена */
        int		gpi_k;				/* Количество */
        int		gpi_s;				/* Стоимость */
        };
#endif
