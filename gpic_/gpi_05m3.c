/*
     Упражнение 4 (fio_04m). Работа с массивами в цикле
     Для вышеуказанных переменных объявить массивы на 100 элементов и отработать 
за один проход ввод с консоли в массив, вычисление стоимости и вывод на консоль 
из массива пока не будет введена в названии материала первая *
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void gpi__set_gpi_n(char* gpi_n);
void gpi__set_gpi_c(int* gpi_c);
void gpi__set_gpi_k(int* gpi_k);
void gpi__set_gpi_s(int* gpi_s, int gpi_c, int gpi_k);
void gpi__print_info(const char* gpi_n, int gpi_c, int gpi_k, int gpi_s);
void gpi__print_table(
	const int	gpi_arr_length,
	const char	(*gpi_n)[100],
	const int* 	gpi_c,
	const int* 	gpi_k,
	const int* 	gpi_s
	);

int main()
	{
	const int	gpi_arr_length = 100;	/* Длина массива */
	char		gpi_n[10][100];			/* Наименование */
	int			gpi_c[100];				/* Цена */
	int			gpi_k[100];				/* Количество */
	int			gpi_s[100];				/* Стоимость */

	/* --------------------------------------------------------- */	
	
	system("chcp 866");
	
	printf(" =Галанин П.И.=     =gpi_04m= \n");
	printf(" Упражнение 4 (fio_04m). Работа с массивами в цикле \n \n");

	int gpi_i = 0;
	while(gpi_i < gpi_arr_length)
		{ /* cycle 1 */
		printf(" { id %d \n", gpi_i);
		
		gpi__set_gpi_n(gpi_n[gpi_i]);
	
		if ((gpi_n[gpi_i])[0] == '*')
			{
			printf(" Выход из цикла \n");
			printf(" } \n \n");
			break;
			}
			
		gpi__set_gpi_c(&gpi_c[gpi_i]);
		gpi__set_gpi_k(&(gpi_k[gpi_i]));
        
		++gpi_i;
		printf(" } \n \n");
		} /* end cycle 1 */

    int gpi_j = 0;
    while (gpi_j < gpi_i)
        { /* cycle 2 */
        gpi__set_gpi_s(&(gpi_s[gpi_j]), gpi_c[gpi_j], gpi_k[gpi_j]);
        printf("%d : ", gpi_j);
		gpi__print_info(gpi_n[gpi_j], gpi_c[gpi_j], gpi_k[gpi_j], gpi_s[gpi_j]);
        ++gpi_j;
        } /* end cycle 2 */
    printf(" \n");
    
	gpi__print_table(gpi_i, gpi_n, gpi_c, gpi_k, gpi_s); /* cycle 3 */

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
	printf(" Материал \"%s\" стоимость = цена * количество = %d * %d = %d \n",
		gpi_n, gpi_c, gpi_k, gpi_s
		);
	}

void gpi__print_table(
	const int	gpi_arr_length,
	const char	(*gpi_n)[100],
	const int* 	gpi_c,
	const int* 	gpi_k,
	const int* 	gpi_s
	)
	{
	printf(" | %4s | %12s | %12s | %12s | %12s | \n",
		" ID ",
		"Наименование",
		"    Цена    ",
		" Количество ",
		" Стоимость  "
		);
					
	printf(" | %4s | %12s | %12s | %12s | %12s | \n",
		"----",
		"------------",
		"------------",
		"------------",
		"------------"
		);
		
	int gpi_i = 0;
	while(gpi_i < gpi_arr_length)
		{
		printf(" | %4d | %12s | %12d | %12d | %12d | \n",
			gpi_i,
			gpi_n[gpi_i],
			gpi_c[gpi_i],
			gpi_k[gpi_i],
			gpi_s[gpi_i]
			);
		++gpi_i;
		}
	}
