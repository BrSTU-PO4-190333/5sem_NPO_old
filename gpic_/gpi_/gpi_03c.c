/*
     ��ࠦ����� 3 (fio_03c). ����� � 横��
     ���㪠����� ��६���� ������� � ���᮫� � �뢮���� �� ���᮫� ���� 
�� �㤥� ������� � �������� ���ਠ�� ��ࢠ� *
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
char	gpi_n[10];          /* ������������ */
int		gpi_c;				/* ���� */
int		gpi_k;				/* ������⢮ */
int		gpi_s;				/* �⮨����� */

/* ------------------------------------------------ */	
	
	system ("chcp 866");
	
    printf (" =������� �. �.=          =gpi_03c= \n");
    printf (" ��ࠦ����� 3 (fio_03c). ����� � 横�� \n \n");

    while(1 == 1)
        {
//        printf(" { \n");
        
        printf (" gpi_02op �������� ���ਠ�� ");
        scanf ("%s", gpi_n);
        
        if (gpi_n[0] == '*')
            {
            printf (" \n");
            break;
            }
        
        printf (" gpi_02op ���� ");
        scanf ("%d", &gpi_c);
        
        printf (" gpi_02op ������⢮ ");
        scanf ("%d", &gpi_k);
        
        gpi_s = gpi_c * gpi_k;
        
        printf (" gpi_02op ���ਠ� \"%s\" �⮨����� = 業� * ������⢮ = %d * %d = %d \n",
            gpi_n, gpi_c, gpi_k, gpi_s
            );

//        printf (" } \n \n");
        printf (" \n");
        }

	printf (" ������ ���� ������... \n");
    getch ();

	return(0);
	}

