/*
     ��ࠦ����� 5 (fio_05m3). ����� � ���ᨢ��� � ��᪮�쪨� 横���
     �������筮 �ࠦ����� 4, �� �� 3 ��室� �� ���ᨢ� (�����, ������� 
�⮨�����, �뢮� �� ���᮫�).
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

int     gpi_i;

/* ------------------------------------------------ */	
	
	system ("chcp 866");
	
    printf (" =������� �. �.=          =gpi_05m3= \n");
    printf (" ��ࠦ����� 5 (fio_05m3). ����� � ���ᨢ��� � ��᪮�쪨� 横��� \n \n");

    /* ���� 横� */
    gpi_i = 0;
    while (gpi_i < 100)
        {
        printf (" gpi_04m �������� ���ਠ�� ");
        scanf ("%s", gpi_n[gpi_i]);
        
        if (gpi_n[gpi_i][0] == '*')
            {
            printf (" \n");
            break;
            }
        
        printf (" gpi_04m ���� ");
        scanf ("%d", &gpi_c[gpi_i]);
        
        printf (" gpi_04m ������⢮ ");
        scanf ("%d", &gpi_k[gpi_i]);
    
        printf(" \n");
        ++gpi_i;
        }
    
    /* ��ன 横� */
    gpi_i = 0;
    while (1 == 1)
        {
        if (gpi_n[gpi_i][0] == '*')
            break;

        gpi_s[gpi_i] = gpi_c[gpi_i] * gpi_k[gpi_i];
        ++gpi_i;    
        }
        
    /* ��⨩ 横� */
    printf (" \n gpi_04m | %10s | %10s | %10s | %10s | \n",
        " �������� ",
        "   ����   ",
        "������⢮",
        "�⮨����� "
        );
    printf (" gpi_04m | %10s | %10s | %10s | %10s | \n",
        "----------",
        "----------",
        "----------",
        "----------"
        );
    gpi_i = 0;
    while (1 == 1)
        {
        if (gpi_n[gpi_i][0] == '*')
            break;
            
        printf (" gpi_04m | %10s | %10d | %10d | %10d | \n",
            gpi_n[gpi_i], gpi_c[gpi_i], gpi_k[gpi_i], gpi_s[gpi_i]
            );
        ++gpi_i;
        }
    printf(" \n");

    printf (" ������ ���� ������... \n");
    getch ();

	return (0);
	}
