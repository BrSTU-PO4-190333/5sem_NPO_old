/*
     Упражнение 7 (fio_07ms). Работа с массивом структур в цикле.
     На базе исходника упражнения 6 Объявить массив структур  и отработать 
аналогично упражнению 4 за один проход ввод с консоли в массив, вычисление 
стоимости и вывод на консоль из массива пока не будет введена в названии 
материала первая *
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct gpi_Struct
	{
	char	gpi_n[10];			/* Наименование */
	int		gpi_c;				/* Цена */
	int		gpi_k;				/* Количество */
	int		gpi_s;				/* Стоимость */
	};

void gpi__set_gpi_n(struct gpi_Struct* gpi_struct);
void gpi__set_gpi_c(struct gpi_Struct* gpi_struct);
void gpi__set_gpi_k(struct gpi_Struct* gpi_struct);
void gpi__set_gpi_s(struct gpi_Struct* gpi_struct);	
void gpi__print_info(struct gpi_Struct* gpi_struct);
void gpi__print_table(const int gpi_length, struct gpi_Struct* gpi_arr);

int main()
	{
    const int gpi_length = 100;
	struct gpi_Struct gpi_arr[100];
	/* --------------------------------------------------------- */	
	
	system("chcp 866");
	
	printf(" =Галанин П.И.=     =gpi_07ms= \n");
	printf(" Упражнение 7 (fio_07ms). Работа с массивом структур в цикле. \n");
    printf(" \n");

    int gpi_i = 0;
    while(gpi_i < gpi_length)
        {
        printf(" { \n");
        gpi__set_gpi_n(&gpi_arr[gpi_i]);
        
        if(gpi_arr[gpi_i].gpi_n[0] == '*')
            {
            printf(" Выход из цикла \n");
            printf(" } \n");
            break;
            }
        
        gpi__set_gpi_c(&gpi_arr[gpi_i]);
        gpi__set_gpi_k(&gpi_arr[gpi_i]);
        gpi__set_gpi_s(&gpi_arr[gpi_i]);
        gpi__print_info(&gpi_arr[gpi_i]);
        printf(" } \n");
        ++gpi_i;
        }
        
    gpi__print_table(gpi_i, gpi_arr);
	
	printf(" \n press any key \n");
	getch();

	return(0);
	}

void gpi__set_gpi_n(struct gpi_Struct* gpi_struct)
	{
	printf(" gpi_06s Название материала ");
	scanf("%s", gpi_struct->gpi_n);
	}
	
void gpi__set_gpi_c(struct gpi_Struct* gpi_struct)
	{
	printf(" gpi_06s Цена ");
	scanf("%d", &(gpi_struct->gpi_c));
	}
	
void gpi__set_gpi_k(struct gpi_Struct* gpi_struct)
	{
	printf(" gpi_06s Количество ");
	scanf("%d", &(gpi_struct->gpi_k));
	}
	
void gpi__set_gpi_s(struct gpi_Struct* gpi_struct)
	{
	gpi_struct->gpi_s = gpi_struct->gpi_c * gpi_struct->gpi_k;
	}
	
void gpi__print_info(struct gpi_Struct* gpi_struct)
	{
	printf(" Материал \"%s\" стоимость = цена * количество = %d * %d = %d \n",
		gpi_struct->gpi_n,
		gpi_struct->gpi_c,
		gpi_struct->gpi_k,
		gpi_struct->gpi_s
		);
	}

void gpi__print_table(const int gpi_length, struct gpi_Struct* gpi_arr)
    {
    printf(" \n");
        
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
    while(gpi_i < gpi_length)
        {
        printf(" | %4d | %12s | %12d | %12d | %12d | \n",
            gpi_i,
            gpi_arr[gpi_i].gpi_n,
            gpi_arr[gpi_i].gpi_c,
            gpi_arr[gpi_i].gpi_k,
            gpi_arr[gpi_i].gpi_s
            );
        ++gpi_i;
        }
    printf(" \n");
    }
