/*
     ��ࠦ����� 1 (fio_01h). �������� ���⥩襩 �ணࠬ��
     ������� � �⫠���� �ணࠬ�� HELLO. �஢���� ����稥 ��ꥪ⭮�� � 
�ᯮ���⥫쭮�� �����. ��ᬮ���� �� ������ ��⥣�஢����� �।� TC.
�ᮡ� ������ �������� ��:
- ����ன�� �।�;
- ࠡ��� � ।���஬ ��室���� ⥪��. ��易⥫쭮 �������� ࠡ���� 
� ����묨 ���������, � ⮬ �᫥ � � �ᯮ�짮������ ࠡ�祣� ���୮�� 䠩�� Q 
�� ��᪥; 
- �ନ஢���� ��ꥪ⭮�� (�࠭����) � �ᯮ���⥫쭮�� ���㫥� 
(।���஢���� �痢�, ��������)
*/

#include <stdio.h>  /* printf() */
#include <conio.h>  /* getch() */
#include <stdlib.h> /* system() */

void gpi__press_any_key();

int main()
	{
	system("chcp 866");
	
    printf(" %-32s %32s \n",
        "=������� �. �.=",
        "=gpi_01h="
        );
    printf(" %s \n \n",
        "��ࠦ����� 1 (fio_01h). �������� ���⥩襩 �ணࠬ��"
        );

    printf(" Hello, World! \n");
	printf(" �ਢ��, ���! \n");
    printf(" HELLO \n");
	
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
