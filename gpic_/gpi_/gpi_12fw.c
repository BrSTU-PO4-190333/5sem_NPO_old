/*
     Упражнение 12 (fio_12fw). Вывод в файл.
     Аналогично упражнению 11 и на базе его исходника, но  вывод на консоль  
заменяется на вывод в последовательный файл fio_12xx.
*/

#include <stdio.h>  /* printf() */
#include <conio.h>  /* getch() */
#include <stdlib.h> /* system() */

#define gpi_Product_length 100
struct gpi_Product
    {
	char	gpi_n[10];          /* Наименование */
	int		gpi_c;				/* Цена */
	int		gpi_k;				/* Количество */
	int		gpi_s;				/* Стоимость */
    };

void gpi__press_any_key();
void gpi__set_n(char* gpi_n);
void gpi__set_c(int* gpi_c);
void gpi__set_k(int* gpi_k);
void gpi_10fv(int* gpi_s, const int gpi_c, const int gpi_k);	
void gpi__print_info(const char* gpi_n, const int gpi_c, const int gpi_k, const int gpi_s);
void gpi__print_file(struct gpi_Product* arr, const int length, const char* path);

int main()
	{
	struct gpi_Product obj[gpi_Product_length];
	
	system("chcp 866");
	
    printf(" %-32s %32s \n",
        "=Галанин П. И.=",
        "=gpi_12fw="
        );
    printf(" %s \n \n",
        "Упражнение 12 (fio_12fw). Вывод в файл"
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

    gpi__print_file(obj, i, "gpi_12xx.csv");

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
	printf(" gpi_02op Название материала ");
	scanf("%s", gpi_n);
	}
	
void gpi__set_c(int* gpi_c)
	{
	printf(" gpi_02op Цена ");
	scanf("%d", gpi_c);
	}
	
void gpi__set_k(int* gpi_k)
	{
	printf(" gpi_02op Количество ");
	scanf("%d", gpi_k);
	}
	
void gpi_10fv(int* gpi_s, const int gpi_c, const int gpi_k)
	{
	(*gpi_s) = gpi_c * gpi_k;
	}
	
void gpi__print_info(const char* gpi_n, const int gpi_c, const int gpi_k, const int gpi_s)
	{
	printf(" Материал \"%s\" стоимость = цена * количество = %d * %d = %d \n",
		gpi_n, gpi_c, gpi_k, gpi_s
		);
	}

void gpi__print_file(struct gpi_Product* arr, const int length, const char* path)
    {
    FILE* file_pointer = fopen(path, "w");
    if (file_pointer == NULL)
        {
        printf(" Файл %s не был открыт для записи \n", path);
        return;
        }
    int i = 0;
    while(i < length)
        {
        fprintf(file_pointer, "%s", arr[i].gpi_n);
        fprintf(file_pointer, ",");
        
        fprintf(file_pointer, "%d", arr[i].gpi_c);
        fprintf(file_pointer, ",");
        
        fprintf(file_pointer, "%d", arr[i].gpi_k);
        fprintf(file_pointer, "\n");
                
        ++i;
        }
    fclose(file_pointer);
    printf(" Данные записаны в файл %s \n", path);
    }
