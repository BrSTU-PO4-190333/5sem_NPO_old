/*
     ��ࠦ����� 6 (fio_06s). ������� �������
     �������筮 �ࠦ����� 2 � ��  ���� ��� ��室����, �� ��६���� ����� 
��� ����� ��������.
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct gpi_str
    {
	char	gpi_n[10];          /* ������������ */
	int		gpi_c;				/* ���� */
	int		gpi_k;				/* ������⢮ */
	int		gpi_s;				/* �⮨����� */
    };

int main()
{ 
struct gpi_str gpi_str[1];

/* ------------------------------------------------ */	
	
	system("chcp 866");
	
    printf(" =������� �. �.=          =gpi_06s= \n");
    printf(" ��ࠦ����� 6 (gpi_06s). ������� ������� \n \n");

	printf (" gpi_06s �������� ���ਠ�� ");
	scanf ("%s", gpi_str->gpi_n);
    
    printf (" gpi_06s ���� ");
	scanf ("%d", &gpi_str->gpi_c);
    
    printf (" gpi_06s ������⢮ ");
	scanf ("%d", &gpi_str->gpi_k);
    
    gpi_str->gpi_s = gpi_str->gpi_c * gpi_str->gpi_k;
    
	printf (" gpi_06s ���ਠ� \"%s\" �⮨����� = 業� * ������⢮ = %d * %d = %d \n \n",
		gpi_str->gpi_n,
        gpi_str->gpi_c,
        gpi_str->gpi_k,
        gpi_str->gpi_s
		);
	
	printf (" ������ ���� ������... \n");
    getch ();

	return (0);
	}
