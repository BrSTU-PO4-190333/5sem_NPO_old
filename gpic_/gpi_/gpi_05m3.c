/*
     Упражнение 5 (fio_05m3). Работа с массивами в нескольких циклах
     Аналогично упражнению 4, но за 3 прохода по массиву (ввести, рассчитать 
стоимость, вывод на консоль).
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
char	gpi_n[10][100];     /* Наименование */
int		gpi_c[100];			/* Цена */
int		gpi_k[100];			/* Количество */
int		gpi_s[100];			/* Стоимость */

int     gpi_i;

/* ------------------------------------------------ */	
	
	system ("chcp 866");
	
    printf (" =Галанин П. И.=          =gpi_05m3= \n");
    printf (" Упражнение 5 (fio_05m3). Работа с массивами в нескольких циклах \n \n");

    /* Первый цикл */
    gpi_i = 0;
    while (gpi_i < 100)
        {
        printf (" gpi_04m Название материала ");
        scanf ("%s", gpi_n[gpi_i]);
        
        if (gpi_n[gpi_i][0] == '*')
            {
            printf (" \n");
            break;
            }
        
        printf (" gpi_04m Цена ");
        scanf ("%d", &gpi_c[gpi_i]);
        
        printf (" gpi_04m Количество ");
        scanf ("%d", &gpi_k[gpi_i]);
    
        printf(" \n");
        ++gpi_i;
        }
    
    /* Второй цикл */
    gpi_i = 0;
    while (1 == 1)
        {
        if (gpi_n[gpi_i][0] == '*')
            break;

        gpi_s[gpi_i] = gpi_c[gpi_i] * gpi_k[gpi_i];
        ++gpi_i;    
        }
        
    /* Третий цикл */
    printf (" \n gpi_04m | %10s | %10s | %10s | %10s | \n",
        " Название ",
        "   Цена   ",
        "Количество",
        "Стоимость "
        );
    printf (" gpi_04m | %10s | %10s | %10s | %10s | \n",
        "----------",
        "----------",
        "----------",
        "----------"
        );
    gpi_i = 0;
    while (1 == 1)
        {
        if (gpi_n[gpi_i][0] == '*')
            break;
            
        printf (" gpi_04m | %10s | %10d | %10d | %10d | \n",
            gpi_n[gpi_i], gpi_c[gpi_i], gpi_k[gpi_i], gpi_s[gpi_i]
            );
        ++gpi_i;
        }
    printf(" \n");

    printf (" Нажмите любую кнопку... \n");
    getch ();

	return (0);
	}
