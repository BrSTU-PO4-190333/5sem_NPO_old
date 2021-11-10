/*
     Упражнение 3 (fio_03c). Работа в цикле
     Вышеуказанные переменные вводить с консоли и выволить на консоль пока 
не будет введена в названии материала первая *
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
char	gpi_n[10];          /* Наименование */
int		gpi_c;				/* Цена */
int		gpi_k;				/* Количество */
int		gpi_s;				/* Стоимость */

/* ------------------------------------------------ */	
	
	system ("chcp 866");
	
    printf (" =Галанин П. И.=          =gpi_03c= \n");
    printf (" Упражнение 3 (fio_03c). Работа в цикле \n \n");

    while(1 == 1)
        {
//        printf(" { \n");
        
        printf (" gpi_02op Название материала ");
        scanf ("%s", gpi_n);
        
        if (gpi_n[0] == '*')
            {
            printf (" \n");
            break;
            }
        
        printf (" gpi_02op Цена ");
        scanf ("%d", &gpi_c);
        
        printf (" gpi_02op Количество ");
        scanf ("%d", &gpi_k);
        
        gpi_s = gpi_c * gpi_k;
        
        printf (" gpi_02op Материал \"%s\" стоимость = цена * количество = %d * %d = %d \n",
            gpi_n, gpi_c, gpi_k, gpi_s
            );

//        printf (" } \n \n");
        printf (" \n");
        }

	printf (" Нажмите любую кнопку... \n");
    getch ();

	return(0);
	}

