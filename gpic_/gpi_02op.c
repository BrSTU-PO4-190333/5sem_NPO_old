/*
     ��ࠦ����� 2 (fio_02op). ������� ��६�����
     �� ��室���� �ࠦ����� 1  ᤥ���� ��室�� 䠩� ���:
- ����� ��६���� "�������� ���ਠ��", "業�", "������⢮","�⮨�����"
- ����� "�������� ���ਠ��", "業�", "������⢮" � ���᮫� ��᫥ ���᪠���
- ������� "�⮨�����"
- �뢥�� �� ���᮫� "�������� ���ਠ��", "業�", "������⢮","�⮨�����" 
- ���⠢��� � ���� �ணࠬ�� "����� ���� ����" ��� ⮣� �⮡� �� ��室��� 
  �� �࠭ ���짮��⥫� ��� �஢�ન १����
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
	char	gpi_n[10];			/* ������������ */
	int		gpi_c;				/* ���� */
	int		gpi_k;				/* ������⢮ */
	int		gpi_s;				/* �⮨����� */

	/* --------------------------------------------------------- */	
	
	system("chcp 866");
	
	printf(" =������� �.�.=     =gpi_02op= \n");
	printf(" ��ࠦ����� 2 (fio_02op). ������� ��६����� \n");
    printf(" \n");

	gpi__set_gpi_n(gpi_n);
	gpi__set_gpi_c(&gpi_c);
	gpi__set_gpi_k(&gpi_k);
	gpi__set_gpi_s(&gpi_s, gpi_c, gpi_k);
	gpi__print_info(gpi_n, gpi_c, gpi_k, gpi_s);
	
	printf(" \n press any key \n");
	getch();

	return(0);
	}

void gpi__set_gpi_n(char* gpi_n)
	{
	printf(" gpi_02op �������� ���ਠ�� ");
	scanf("%s", gpi_n);
	}
	
void gpi__set_gpi_c(int* gpi_c)
	{
	printf(" gpi_02op ���� ");
	scanf("%d", gpi_c);
	}
	
void gpi__set_gpi_k(int* gpi_k)
	{
	printf(" gpi_02op ������⢮ ");
	scanf("%d", gpi_k);
	}
	
void gpi__set_gpi_s(int* gpi_s, int gpi_c, int gpi_k)
	{
	(*gpi_s) = gpi_c * gpi_k;
	}
	
void gpi__print_info(const char* gpi_n, int gpi_c, int gpi_k, int gpi_s)
	{
	printf(" ���ਠ� \"%s\" �⮨����� = 業� * ������⢮ = %d * %d = %d \n",
		gpi_n, gpi_c, gpi_k, gpi_s
		);
	}
