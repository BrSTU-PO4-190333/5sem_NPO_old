/*
     ��ࠦ����� 7 (fio_07ms). ����� � ���ᨢ�� ������� � 横��.
     �� ���� ��室���� �ࠦ����� 6 ����� ���ᨢ �������  � ��ࠡ���� 
�������筮 �ࠦ����� 4 �� ���� ��室 ���� � ���᮫� � ���ᨢ, ���᫥��� 
�⮨���� � �뢮� �� ���᮫� �� ���ᨢ� ���� �� �㤥� ������� � �������� 
���ਠ�� ��ࢠ� *
*/

#include <stdio.h>  /* printf() */
#include <conio.h>  /* getch() */
#include <stdlib.h> /* system() */

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
void gpi__set_s(int* gpi_s, const int gpi_c, const int gpi_k);	
void gpi__print_info(const char* gpi_n, const int gpi_c, const int gpi_k, const int gpi_s);

int main()
	{
	struct gpi_Product obj[100];
	
	system("chcp 866");
	
    printf(" %-32s %32s \n",
        "=������� �. �.=",
        "=fio_07ms="
        );
    printf(" %s \n \n",
        "��ࠦ����� 7 (fio_07ms). ����� � ���ᨢ�� ������� � 横��"
        );

    int i = 0;
    while(i < 100)
        {
        printf(" { \n");
        gpi__set_n(obj[i].gpi_n);
        if (obj[i].gpi_n[0] == '*')
            {
            break;
            }
        gpi__set_c(&obj[i].gpi_c);
        gpi__set_k(&obj[i].gpi_k);
        gpi__set_s(&obj[i].gpi_s, obj[i].gpi_c, obj[i].gpi_k);
        gpi__print_info(obj[i].gpi_n, obj[i].gpi_c, obj[i].gpi_k, obj[i].gpi_s);
        printf(" } \n");
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
	
void gpi__print_info(const char* gpi_n, const int gpi_c, const int gpi_k, const int gpi_s)
	{
	printf(" ���ਠ� \"%s\" �⮨����� = 業� * ������⢮ = %d * %d = %d \n",
		gpi_n, gpi_c, gpi_k, gpi_s
		);
	}
