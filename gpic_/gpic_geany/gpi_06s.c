/*
     Упражнение 6 (fio_06s). Объявление структур
     Аналогично упражнению 2 и на  базе его исходника, но переменные объявить 
как элемент структуры.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct gpi_str
    {
	char	gpi_n[10];          /* Наименование */
	int		gpi_c;				/* Цена */
	int		gpi_k;				/* Количество */
	int		gpi_s;				/* Стоимость */
    };

int main()
{ 
struct gpi_str gpi_str[1];

/* ------------------------------------------------ */	
	
	system("chcp 866");
	
    printf(" =Галанин П. И.=          =gpi_06s= \n");
    printf(" Упражнение 6 (gpi_06s). Объявление структур \n \n");

	printf (" gpi_06s Название материала ");
	scanf ("%s", gpi_str->gpi_n);
    
    printf (" gpi_06s Цена ");
	scanf ("%d", &gpi_str->gpi_c);
    
    printf (" gpi_06s Количество ");
	scanf ("%d", &gpi_str->gpi_k);
    
    gpi_str->gpi_s = gpi_str->gpi_c * gpi_str->gpi_k;
    
	printf (" gpi_06s Материал \"%s\" стоимость = цена * количество = %d * %d = %d \n \n",
		gpi_str->gpi_n,
        gpi_str->gpi_c,
        gpi_str->gpi_k,
        gpi_str->gpi_s
		);
	
	printf (" Нажмите любую кнопку... \n");
    getch ();

	return (0);
	}
