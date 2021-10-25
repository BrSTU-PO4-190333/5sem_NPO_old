/*
     ��ࠦ����� 14(fio_14fc). ����஢���� 䠩��.
     �� ���� ��室��� ⥪�⮢ �ࠦ����� 13 � 12 ॠ�������� �⥭�� ࠭�� 
����祭���� 䠩�� fio_12xx c �뢮��� � 䠩� fio_14xx. 
*/

#include <stdio.h>  /* printf() */
#include <conio.h>  /* getch() */
#include <stdlib.h> /* system() */
#include <string.h> /* strcpy() */

struct gpi_Product
    {
	char	gpi_n[10];          /* ������������ */
	int		gpi_c;				/* ���� */
	int		gpi_k;				/* ������⢮ */
	int		gpi_s;				/* �⮨����� */
    };

void gpi__press_any_key();
void gpi_10fv(int* gpi_s, const int gpi_c, const int gpi_k);
struct gpi_Product* gpi__read_file(struct gpi_Product* arr, int* length, const char* path);
void gpi_print_table(struct gpi_Product* arr, const int length);
void gpi__print_file(struct gpi_Product* arr, const int length, const char* path);

int main()
	{
    int length = 0;
	struct gpi_Product* arr = NULL;
	
	system("chcp 866");
	
    printf(" %-32s %32s \n",
        "=������� �. �.=",
        "=gpi_14fc="
        );
    printf(" %s \n \n",
        "��ࠦ����� 14(fio_14fc). ����஢���� 䠩��"
        );

    arr = gpi__read_file(arr, &length, "gpi_12xx.csv");
    gpi_print_table(arr, length);
    gpi__print_file(arr, length, "gpi_14xx.csv");

	gpi__press_any_key();
    
    free(arr);

	return(0);
	}

void gpi__press_any_key()
    {
    printf(" \n %s \n",
        "Press any key..."
        );
    getch();
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

struct gpi_Product* gpi__read_file(struct gpi_Product* arr, int* length, const char* path)
    {
    FILE* file_pointer = fopen(path, "r");
    if (file_pointer == NULL)
        {
        printf(" ���� %s �� ������ ��� �⥭�� \n", path);
        return arr;
        }
    
    int Case = 0;
    int word_size = 0;
    (*length) = 0;
    char* word = (char*) calloc(word_size, sizeof(char));
    while(!feof(file_pointer))
        {
        char ch = getc(file_pointer);
        if(ch != ',' || ch != '\n')
            {
            word = (char*) realloc(word, (word_size + 1) * sizeof(char));
            word[word_size] = ch;
            ++word_size;
            }

        if(ch == ',' || ch == '\n')
            {
            word[word_size - 1] = '\0';
            ++Case;
            switch(Case)
                {
                case 1: /* ������������ */
//                    printf(" case 1 \"%s\" \n", word);
                    ++(*length);
                    arr = (struct gpi_Product*) realloc(arr, (*length) * sizeof(struct gpi_Product));
                    strcpy(arr[(*length) - 1].gpi_n, word);
                    break;
                case 2: /* ���� */
//                    printf(" case 2 \"%s\" \n", word);
                    arr[(*length) - 1].gpi_c = atoi(word);
                    break;
                case 3: /* ������⢮ */
//                    printf(" case 3 \"%s\" \n", word);
                    arr[(*length) - 1].gpi_k = atoi(word);
                    gpi_10fv(&arr[(*length) - 1].gpi_s,
                        arr[(*length) - 1].gpi_c,
                        arr[(*length)-1].gpi_k
                        );
                    Case = 0;
                    break;
                }
            word_size = 0;
            free(word);
            word = (char*) calloc(word_size, sizeof(char));
            }
        }
        
    if (word != NULL)
        {
        free(word);
        }
    printf(" ���� %s ���⠭ \n", path);
    fclose(file_pointer);
    return(arr);
    }

void gpi_print_table(struct gpi_Product* arr, const int length)
    {
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
    int i = 0;
    while(i < length)
        {
        printf(" | %10s | %10d | %10d | %10d | \n",
            arr[i].gpi_n,
            arr[i].gpi_c,
            arr[i].gpi_k,
            arr[i].gpi_s
            );
        ++i;
        }
    }

void gpi__print_file(struct gpi_Product* arr, const int length, const char* path)
    {
    FILE* file_pointer = fopen(path, "w");
    if (file_pointer == NULL)
        {
        printf(" ���� %s �� �� ����� ��� ����� \n", path);
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
    printf(" ����� ����ᠭ� � 䠩� %s \n", path);
    }
