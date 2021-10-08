/*
     Упражнение 3 (fio_03c). Работа в цикле
     Вышеуказанные переменные вводить с консоли и выволить на консоль пока 
не будет введена в названии материала первая *
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void gpi__set_gpi_n(char* gpi_n);
void gpi__set_gpi_c(int* gpi_c);
void gpi__set_gpi_k(int* gpi_k);
void gpi__set_gpi_s(int* gpi_s, int gpi_c, int gpi_k);	
void gpi__print_info(const char* gpi_n, int gpi_c, int gpi_k, int gpi_s);

int main()
	{
	char	gpi_n[10];			/* Наименование */
	int		gpi_c;				/* Цена */
	int		gpi_k;				/* Количество */
	int		gpi_s;				/* Стоимость */

	/* --------------------------------------------------------- */	
	
	system("chcp 866");
	
	printf(" =Галанин П.И.=     =gpi_03c= \n");
	printf(" Упражнение 3 (fio_03c). Работа в цикле \n \n");

	while(1)
		{
		printf(" { \n");
		
		gpi__set_gpi_n(gpi_n);
	
		if (gpi_n[0] == '*')
			{
			printf(" Выход из цикла \n");
			printf(" } \n \n");
			break;
			}
			
		gpi__set_gpi_c(&gpi_c);
		gpi__set_gpi_k(&gpi_k);
		gpi__set_gpi_s(&gpi_s, gpi_c, gpi_k);
		gpi__print_info(gpi_n, gpi_c, gpi_k, gpi_s);
			
		printf(" } \n \n");
		}

	printf(" \n press any key \n");
	getch();

	return(0);
	}

void gpi__set_gpi_n(char* gpi_n)
	{
	printf(" gpi_02op Название материала ");
	scanf("%s", gpi_n);
	}
	
void gpi__set_gpi_c(int* gpi_c)
	{
	printf(" gpi_02op Цена ");
	scanf("%d", gpi_c);
	}
	
void gpi__set_gpi_k(int* gpi_k)
	{
	printf(" gpi_02op Количество ");
	scanf("%d", gpi_k);
	}
	
void gpi__set_gpi_s(int* gpi_s, int gpi_c, int gpi_k)
	{
	(*gpi_s) = gpi_c * gpi_k;
	}
	
void gpi__print_info(const char* gpi_n, int gpi_c, int gpi_k, int gpi_s)
	{
	printf("\n Материал \"%s\" стоимость = цена * количество = %d * %d = %d \n",
		gpi_n, gpi_c, gpi_k, gpi_s
		);
	}
