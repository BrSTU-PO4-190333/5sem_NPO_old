/*
     ��ࠦ����� 4 (fio_04m). ����� � ���ᨢ��� � 横��
     ��� ���㪠������ ��६����� ����� ���ᨢ� �� 100 ����⮢ � ��ࠡ���� 
�� ���� ��室 ���� � ���᮫� � ���ᨢ, ���᫥��� �⮨���� � �뢮� �� ���᮫� 
�� ���ᨢ� ���� �� �㤥� ������� � �������� ���ਠ�� ��ࢠ� *
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
char	gpi_n[10][100];     /* ������������ */
int		gpi_c[100];			/* ���� */
int		gpi_k[100];			/* ������⢮ */
int		gpi_s[100];			/* �⮨����� */

/* ------------------------------------------------ */	
	
	system("chcp 866");
	
    printf(" =������� �. �.=          =gpi_04m= \n");
    printf(" ��ࠦ����� 4 (fio_04m). ����� � ���ᨢ��� � 横�� \n \n");

    int i = 0;
    while(i < 100)
        {
        printf (" fio_04m �������� ���ਠ�� ");
        scanf ("%s", gpi_n[i]);
        
        if (gpi_n[i][0] == '*')
            {
            printf (" \n");
            break;
            }
        
        printf (" fio_04m ���� ");
        scanf ("%d", &gpi_c[i]);
        
        printf (" fio_04m ������⢮ ");
        scanf ("%d", &gpi_k[i]);
        
        gpi_s[i] = gpi_c[i] * gpi_k[i];
        
        printf (" fio_04m ���ਠ� \"%s\" �⮨����� = 業� * ������⢮ = %d * %d = %d \n",
            gpi_n[i], gpi_c[i], gpi_k[i], gpi_s[i]
            );

        printf (" \n");
        }

	printf (" ������ ���� ������... \n");
    getch ();

	return (0);
	}
