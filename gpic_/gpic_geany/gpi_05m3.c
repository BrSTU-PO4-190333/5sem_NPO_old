/*
     ��ࠦ����� 5 (fio_05m3). ����� � ���ᨢ��� � ��᪮�쪨� 横���
     �������筮 �ࠦ����� 4, �� �� 3 ��室� �� ���ᨢ� (�����, ������� 
�⮨�����, �뢮� �� ���᮫�).
*/

#include <stdio.h>  /* printf() */
#include <conio.h>  /* getch() */
#include <stdlib.h> /* system() */

void gpi__press_any_key();
void gpi__set_n(char* gpi_n);
void gpi__set_c(int* gpi_c);
void gpi__set_k(int* gpi_k);
void gpi__set_s(int* gpi_s, const int gpi_c, const int gpi_k);

int main()
	{
	char	gpi_n[10][100];     /* ������������ */
	int		gpi_c[100];			/* ���� */
	int		gpi_k[100];			/* ������⢮ */
	int		gpi_s[100];			/* �⮨����� */

	/* ------------------------------------------------ */	
	
	system("chcp 866");
	
    printf(" %-32s %32s \n",
        "=������� �. �.=",
        "=gpi_05m3="
        );
    printf(" %s \n \n",
        "��ࠦ����� 5 (fio_05m3). ����� � ���ᨢ��� � ��᪮�쪨� 横���"
        );

    /* ���� 横� */
    int i = 0;
    while(i < 100)
        {
        printf(" { \n");
        gpi__set_n(gpi_n[i]);
        if (gpi_n[i][0] == '*')
            {
            break;
            }
        gpi__set_c(&gpi_c[i]);
        gpi__set_k(&gpi_k[i]);
        printf(" } \n");
        ++i;
        }
    
    /* ��ன 横� */
    int gpi_len = i;
    i = 0;
    while (i < gpi_len)
        {
        gpi__set_s(&gpi_s[i], gpi_c[i], gpi_k[i]);
        ++i;    
        }
        
    /* ��⨩ 横� */
    printf(" \n | %10s | %10s | %10s | %10s | \n",
        " �������� ",
        "   ����   ",
        "������⢮",
        "�⮨����� "
        );
    printf(" | %10s | %10s | %10s | %10s | \n",
        "----------",
        "----------",
        "----------",
        "----------"
        );
    i = 0;
    while (i < gpi_len)
        {
        printf(" | %10s | %10d | %10d | %10d | \n",
            gpi_n[i], gpi_c[i], gpi_k[i], gpi_s[i]
            );
        ++i;
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
	printf(" gpi_02op �������� ���ਠ�� ");
	scanf("%s", gpi_n);
	}
	
void gpi__set_c(int* gpi_c)
	{
	printf(" gpi_02op ���� ");
	scanf("%d", gpi_c);
	}
	
void gpi__set_k(int* gpi_k)
	{
	printf(" gpi_02op ������⢮ ");
	scanf("%d", gpi_k);
	}
	
void gpi__set_s(int* gpi_s, const int gpi_c, const int gpi_k)
	{
	(*gpi_s) = gpi_c * gpi_k;
	}
