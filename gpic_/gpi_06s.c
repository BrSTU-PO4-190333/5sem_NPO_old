/*
     ��ࠦ����� 6 (fio_06s). ������� �������
     �������筮 �ࠦ����� 2 � ��  ���� ��� ��室����, �� ��६���� ����� 
��� ����� ��������.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct gpi_Struct
	{
	char	gpi_n[10];			/* ������������ */
	int		gpi_c;				/* ���� */
	int		gpi_k;				/* ������⢮ */
	int		gpi_s;				/* �⮨����� */
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
	
	printf(" =������� �.�.=     =gpi_06s= \n");
	printf(" ��ࠦ����� 6 (fio_06s). ������� ������� \n\n");

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
	printf(" gpi_06s �������� ���ਠ�� ");
	scanf("%s", gpi_struct->gpi_n);
	}
	
void gpi__set_gpi_c(struct gpi_Struct* gpi_struct)
	{
	printf(" gpi_06s ���� ");
	scanf("%d", &(gpi_struct->gpi_c));
	}
	
void gpi__set_gpi_k(struct gpi_Struct* gpi_struct)
	{
	printf(" gpi_06s ������⢮ ");
	scanf("%d", &(gpi_struct->gpi_k));
	}
	
void gpi__set_gpi_s(struct gpi_Struct* gpi_struct)
	{
	gpi_struct->gpi_s = gpi_struct->gpi_c * gpi_struct->gpi_k;
	}
	
void gpi__print_info(struct gpi_Struct* gpi_struct)
	{
	printf("\n ���ਠ� \"%s\" �⮨����� = 業� * ������⢮ = %d * %d = %d \n",
		gpi_struct->gpi_n,
		gpi_struct->gpi_c,
		gpi_struct->gpi_k,
		gpi_struct->gpi_s
		);
	}
