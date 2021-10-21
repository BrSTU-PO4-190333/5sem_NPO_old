/*
     Упражнение 14(fio_14fc). Копирование файла.
     На базе исходных текстов упражнений 13 и 12 реализовать Чтение ранее 
полученного файла fio_12xx c выводом в файл fio_14xx. 
*/

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#include "gpi_09i.h"

void gpi__print_csv_file(const int gpi_length, struct gpi_Struct* gpi_arr);
struct gpi_Struct* gpi__read_csv_file(struct gpi_Struct* gpi_arr, int* gpi_length);
void gpi__print_table_head();
void gpi__print_element(const int gpi_i, struct gpi_Struct* gpi_arr);
void gpi__print_table(const int gpi_length, struct gpi_Struct* gpi_arr);

int main()
	{
    int gpi_length = 0;
    struct gpi_Struct* gpi_arr = calloc(gpi_length, sizeof(struct gpi_Struct));
	/* --------------------------------------------------------- */	
	
	system("chcp 866");
	
	printf(" =Галанин П.И.=     =gpi_14fc= \n");
	printf(" Упражнение 14(fio_14fc). Копирование файла. \n");
    printf(" \n");

    gpi_arr = gpi__read_csv_file(gpi_arr, &gpi_length);
	gpi__print_table(gpi_length, gpi_arr);
    gpi__print_csv_file(gpi_length, gpi_arr);
    free(gpi_arr);
    
	printf(" \n press any key \n");
	getch();

	return(0);
	}

void gpi__print_csv_file(const int gpi_length, struct gpi_Struct* gpi_arr)
    {
    char gpi_path[] = "gpi_14xx.csv";
    FILE* gpi_file_pointer = fopen(gpi_path, "w");
    if (gpi_file_pointer == NULL)
        {
        printf(" Файл %s не был открыт для записи \n", gpi_path);
        return;
        }
    int gpi_i = 0;
    while(gpi_i < gpi_length)
        {
        fprintf(gpi_file_pointer, "%s", gpi_arr[gpi_i].gpi_n);
        fprintf(gpi_file_pointer, ",");
        
        fprintf(gpi_file_pointer, "%d", gpi_arr[gpi_i].gpi_c);
        fprintf(gpi_file_pointer, ",");
        
        fprintf(gpi_file_pointer, "%d", gpi_arr[gpi_i].gpi_k);
        fprintf(gpi_file_pointer, "\n");
                
        ++gpi_i;
        }
    fclose(gpi_file_pointer);
    printf(" Данные записаны в %s файл \n", gpi_path);
    }

struct gpi_Struct* gpi__read_csv_file(struct gpi_Struct* gpi_arr, int* gpi_length)
    {
    char path[] = "gpi_12xx.csv";
    FILE* file_pointer = fopen(path, "r");
    if (file_pointer == NULL)
        {
        printf(" Файл %s не был открыт для чтения \n", path);
        return gpi_arr;
        }
    int gpi_case = 0;
    int word_size = 0;
    (*gpi_length) = 0;
    char* word = (char*) calloc(word_size, sizeof(char));
    while(!feof(file_pointer))
        {
        char ch = getc(file_pointer);
        if(ch != ',' || ch != '\n')
            {
            word = (char*) realloc(word, (word_size+1) * sizeof(char));
            word[word_size] = ch;
            ++word_size;
            }

        if(ch == ',' || ch == '\n')
            {
            word[word_size-1] = '\0';
            ++gpi_case;
            switch(gpi_case)
                {
                case 1: //наименование
//                    printf(" case 1 \"%s\" \n", word);
                    ++(*gpi_length);
                    gpi_arr = (struct gpi_Struct*) realloc(gpi_arr, (*gpi_length) * sizeof(struct gpi_Struct));
                    strcpy(gpi_arr[(*gpi_length)-1].gpi_n, word);
                    break;
                case 2: //цена
//                    printf(" case 2 \"%s\" \n", word);
                    gpi_arr[(*gpi_length)-1].gpi_c = atoi(word);
                    break;
                case 3: //количество
//                    printf(" case 3 \"%s\" \n", word);
                    gpi_arr[(*gpi_length)-1].gpi_k = atoi(word);
                    gpi_arr[(*gpi_length)-1].gpi_s = gpi_arr[(*gpi_length)-1].gpi_c * gpi_arr[(*gpi_length)-1].gpi_k;
                    gpi_case = 0;
                    break;
                }
            word_size = 0;
            free(word);
            word = (char*) calloc(word_size, sizeof(char));
            }
        }
        
    if (word_size != 1)
        {
        free(word);
        }
    printf(" Файл %s прочитан \n", path);
    fclose(file_pointer);
    return(gpi_arr);
    }

void gpi__print_table_head()
    {
    printf(" \n");
    printf(" | %4s | %12s | %12s | %12s | %12s | \n",
        " ID ",
        "Наименование",
        "    Цена    ",
        " Количество ",
        " Стоимость  "
        );
        
    printf(" | %4s | %12s | %12s | %12s | %12s | \n",
        "----",
        "------------",
        "------------",
        "------------",
        "------------"
        );
    }

void gpi__print_element(const int gpi_i, struct gpi_Struct* gpi_arr)
    {
    printf(" | %4d | %12s | %12d | %12d | %12d | \n",
        gpi_i,
        gpi_arr[gpi_i].gpi_n,
        gpi_arr[gpi_i].gpi_c,
        gpi_arr[gpi_i].gpi_k,
        gpi_arr[gpi_i].gpi_s
        );
    }

void gpi__print_table(const int gpi_length, struct gpi_Struct* gpi_arr)
    {
    gpi__print_table_head();
    int gpi_i = 0;
    while(gpi_i < gpi_length)
        {
        gpi__print_element(gpi_i, gpi_arr);
        ++gpi_i;
        }
    printf(" \n");
    }
