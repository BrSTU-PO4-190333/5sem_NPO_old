/*
     Упражнение 3 (fio_03c). Работа в цикле
     Вышеуказанные переменные вводить с консоли и выволить на консоль пока 
не будет введена в названии материала первая *
*/

#include <stdio.h>  /* printf() */
#include <conio.h>  /* getch() */
#include <stdlib.h> /* system() */

void gpi__press_any_key();
void gpi__set_n(char* gpi_n);
void gpi__set_c(int* gpi_c);
void gpi__set_k(int* gpi_k);
void gpi__set_s(int* gpi_s, const int gpi_c, const int gpi_k);	
void gpi__print_info(const char* gpi_n, const int gpi_c, const int gpi_k, const int gpi_s);

int main()
	{
	char	gpi_n[10];          /* Наименование */
	int		gpi_c;				/* Цена */
	int		gpi_k;				/* Количество */
	int		gpi_s;				/* Стоимость */

	/* ------------------------------------------------ */	
	
	system("chcp 866");
	
    printf(" %-32s %32s \n",
        "=Галанин П. И.=",
        "=fio_03c="
        );
    printf(" %s \n \n",
        "Упражнение 3 (fio_03c). Работа в цикле"
        );

    while(1)
        {
        printf(" { \n");
        gpi__set_n(gpi_n);
        if (gpi_n[0] == '*')
            {
            break;
            }
        gpi__set_c(&gpi_c);
        gpi__set_k(&gpi_k);
        gpi__set_s(&gpi_s, gpi_c, gpi_k);
        gpi__print_info(gpi_n, gpi_c, gpi_k, gpi_s);
        printf(" } \n");
        }

	gpi__press_any_key();

	return(0);
	}

void gpi__press_any_key()
    {
    printf(" \n %s \n",
        "Press any key..."
        );
    getch();
    }

void gpi__set_n(char* gpi_n)
	{
	printf(" gpi_02op Название материала ");
	scanf("%s", gpi_n);
	}
	
void gpi__set_c(int* gpi_c)
	{
	printf(" gpi_02op Цена ");
	scanf("%d", gpi_c);
	}
	
void gpi__set_k(int* gpi_k)
	{
	printf(" gpi_02op Количество ");
	scanf("%d", gpi_k);
	}
	
void gpi__set_s(int* gpi_s, const int gpi_c, const int gpi_k)
	{
	(*gpi_s) = gpi_c * gpi_k;
	}
	
void gpi__print_info(const char* gpi_n, const int gpi_c, const int gpi_k, const int gpi_s)
	{
	printf(" Материал \"%s\" стоимость = цена * количество = %d * %d = %d \n",
		gpi_n, gpi_c, gpi_k, gpi_s
		);
	}
