/*
     Упражнение 6 (fio_06s). Объявление структур
     Аналогично упражнению 2 и на  базе его исходника, но переменные объявить 
как элемент структуры.
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

int main()
	{
	struct gpi_Struct gpi_struct;
	/* --------------------------------------------------------- */	
	
	system("chcp 866");
	
	printf(" =Галанин П.И.=     =gpi_06s= \n");
	printf(" Упражнение 6 (fio_06s). Объявление структур \n\n");

	gpi__set_gpi_n(&gpi_struct);
	gpi__set_gpi_c(&gpi_struct);
	gpi__set_gpi_k(&gpi_struct);
	gpi__set_gpi_s(&gpi_struct);
	gpi__print_info(&gpi_struct);
	
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
	printf("\n Материал \"%s\" стоимость = цена * количество = %d * %d = %d \n",
		gpi_struct->gpi_n,
		gpi_struct->gpi_c,
		gpi_struct->gpi_k,
		gpi_struct->gpi_s
		);
	}
