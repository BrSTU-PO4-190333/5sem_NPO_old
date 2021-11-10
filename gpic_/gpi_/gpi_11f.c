/*
     ��ࠦ����� 11 (fio_11f). ������ �� �᫮���.
     �������筮 �ࠦ����� 10 � �� ���� ��� ��室����, ��  �뢮� �� ���᮫� 
⮫쪮 ���ਠ��� � 業�� ����� 50
*/

#include <stdio.h>  /* printf() */
#include <conio.h>  /* getch() */
#include <stdlib.h> /* system() */

#define gpi_Product_length 100
struct gpi_Product
    {
	char	gpi_n[10];          /* ������������ */
	int		gpi_c;				/* ���� */
	int		gpi_k;				/* ������⢮ */
	int		gpi_s;				/* �⮨����� */
    };

void gpi__press_any_key();
void gpi__set_n(char* gpi_n);
void gpi__set_c(int* gpi_c);
void gpi__set_k(int* gpi_k);
void gpi_10fv(int* gpi_s, const int gpi_c, const int gpi_k);	
void gpi__print_info(const char* gpi_n, const int gpi_c, const int gpi_k, const int gpi_s);
void gpi_11f(struct gpi_Product* arr, const int length);

int main()
	{
	struct gpi_Product obj[gpi_Product_length];
	
	system("chcp 866");
	
    printf(" %-32s %32s \n",
        "=������� �. �.=",
        "=gpi_11f="
        );
    printf(" %s \n \n",
        "��ࠦ����� 11 (fio_11f). ������ �� �᫮���"
        );

    int i = 0;
    while(i < gpi_Product_length)
        {
        printf(" { \n");
        gpi__set_n(obj[i].gpi_n);
        if (obj[i].gpi_n[0] == '*')
            {
            break;
            }
        gpi__set_c(&obj[i].gpi_c);
        gpi__set_k(&obj[i].gpi_k);
        gpi_10fv(&obj[i].gpi_s, obj[i].gpi_c, obj[i].gpi_k);
        gpi__print_info(obj[i].gpi_n, obj[i].gpi_c, obj[i].gpi_k, obj[i].gpi_s);
        printf(" } \n");
        ++i;
        }

    gpi_11f(obj, i);

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
	
void gpi_10fv(int* gpi_s, const int gpi_c, const int gpi_k)
	{
	(*gpi_s) = gpi_c * gpi_k;
	}
	
void gpi__print_info(const char* gpi_n, const int gpi_c, const int gpi_k, const int gpi_s)
	{
	printf(" ���ਠ� \"%s\" �⮨����� = 業� * ������⢮ = %d * %d = %d \n",
		gpi_n, gpi_c, gpi_k, gpi_s
		);
	}

void gpi_11f(struct gpi_Product* arr, const int length)
    {
    printf(" \n ���ਠ�� � 業�� ����� 祬 50: \n");
    
    int i = 0;
    while(i < length)
        {
        if (arr[i].gpi_c > 50)
            {
            break;
            }
        ++i;
        }
    if (i == length)
        {
        printf(" ��� ⠪�� ���ਠ��� \n");
        return;
        }
    
    printf(" | %10s | %10s | %10s | %10s | \n",
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
    while(i < length)
        {
        if (arr[i].gpi_c > 50)
            {
            printf(" | %10s | % 10d | %10d | %10d | \n",
                arr[i].gpi_n,
                arr[i].gpi_c,
                arr[i].gpi_k,
                arr[i].gpi_s
                );
            }
        ++i;
        }
    }
