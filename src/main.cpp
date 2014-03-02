#include "container.h"
#include "stdafx.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "rus");
	Menu1();
	return(0);
}

void Menu1()
{
	setlocale(LC_CTYPE, "rus");
	const char* MENU_1 = 
"1 - Новый список\n2 - Открыть список\nEsc - Exit\n";

	char data;
	char FileName[MAX_LEN_FILENAME];
	List* pL1;
	FILE* F;

	for(;;)
	{
		system("cls");
		puts(MENU_1);
		pL1 = 0;
		data = getch();
		switch (data)
		{
		case '1':
			{
				Menu2(pL1);
				break;
			}
		/*case '2':
			{
				system("cls");
				printf("Введите название файла: \n");
				gets(FileName);
				F = fopen(FileName,"r");
				if (!F)
				{
					printf("Ошибка открытия файла");
					getch();
					break;
				}
				OpenList(pL1, F);
				fclose(F);
				Menu2(pL1);
				break;
			}
		case 27:
			{
				return;
			}
		default:
			{
				system("cls");
				printf("Ошибка!\nПовторите ввод!");
				getch();
				break;
			}
		}*/
	}
}

void Menu2(List*& pL1)
{
	setlocale(LC_CTYPE, "rus");
	const char* MENU_2 =
"______\n\n \
1 - Сохранить\t\t 8 - Изменить направление отображения\n \
2 - Добавить\t\t 9 - Объеденить\n \
3 - Извлечь\t\
4 - Найти\t\t 10 - Пересечь\n \
5 - Подсчет\t 0 - Вычесть\n \
6 - Сортировка \t\t Esc - Копировать\
7 - Удалить дубликаты\n";

	List* pL2;
	List* pL3;
	List* Point_Current;
	char data, FileName[MAX_LEN_FILENAME], strBuf[MAX_LEN_STR];
	int Direction = DIR_VIEW;
	FILE* F;

	for(;;)
	{
		system("cls");
		PrintList(pL1, Direction);
		puts(MENU_2);
		data = getch();
		switch (data)
		{
		/*case '1':
			{
				system("cls");
				printf("Введите название файла: \n");
				gets(FileName);
				if (!(F = fopen(FileName, "w")))
				{
					printf("Ошибка открытия файла\n\nПовторите ввод!");
					getch();
					break;
				}
				SaveList(pL1, F);
				fclose(F);
				break;
			}*/
		case '2':
			{
				system("cls");
				printf("Введите строку: \n");
				Add_Items();
				break;
			}
		case '3':
			    system("cls");
				Extracting_Elements();
				break;

		case '4':
			/*{
				system("cls");
				printf("Введите строку: \n");
				gets(strBuf);
				switch (FindList(pL1, Point_Current, strBuf))
				{
				case 1:
					{
						system("cls");
						printf("Список пуст\n\nНажмите любую клавишу");
						getch();
						break;
					}
				case 2:
					{
						system("cls");
						printf("Нет такого элемента\n\nНажмите любую клавишу");
						getch();
						break;
					}
				default:
					Menu3(pL1, Point_Current);
				}
				break;
			}*/
		case '5':
			/*{
				system("cls");
				printf("%i Список\n\nНажмите любую клавишу", CountLists(pL1));
				getch();
				break;
			}*/
		case '6':
			/*{
				SortList(pL1);
				break;
			}*/
		case '7':
			{
				DeleteDblLists(pL1);
				break;
			}
		case '8':
			/*{
				Direction = -(Direction);
				break;
			}*/
		case '9':
			/*{
				system("cls");
				printf("Введите имя файла: \n");
				gets(FileName);
				F = fopen(FileName, "r");
				if (!F)
				{
					printf("Ошибка\n\nНажмите любую клавишу");
					getch();
					break;
				}
				OpenList(pL2, F);
				fclose(F);
				pL3 = LinkLists(pL1, pL2);
				DeleteList(pL2);
				Menu2(pL3);
				break;
			}
		case '10':
			{
				system("cls");
				printf("Введите имя файла: \n");
				gets(FileName);
				F = fopen(FileName, "r");
				if (!F)
				{
					printf("Ошибка\n\nНажмите любую клавишу");
					getch();
					break;
				}
				OpenList(pL2, F);
				fclose(F);
				pL3 = CrossLists(pL1, pL2);
				DeleteList(pL2);
				Menu2(pL3);
				break;
			}
		case '0':
			{
				system("cls");
				printf("Введите имя файла: \n");
				gets(FileName);
				F = fopen(FileName, "r");
				if (!F)
				{
					printf("Ошибка\n\nНажмите любую клавишу");
					getch();
					break;
				}
				OpenList(pL2, F);
				fclose(F);
				pL3 = SubtrLists(pL1, pL2);
				DeleteList(pL2);
				Menu2(pL3);
				break;
			}
		case 27:
			{
				DeleteList(pL1);
				return;
			}
		default:
			{
				system("cls");
				printf("Неправильная команда\n\nНажмите любую клавишу");
				getch();
				break;
			}
		}
	}*/
}

void Menu3(List*& pL1, List*& Point_Current)
{
	setlocale(LC_CTYPE, "rus");
	const char* MENU_3 = 
"______\n\n \
1 - Удалить список\n \
Esc - Назад\n";

	char data;

	for(;;)
	{
		system("cls");
		puts(Point_Current->data);
		puts(MENU_3);
		data = getch();
		switch (data)
		{
		case '1': 
			{
				DeleteList(pL1, Point_Current);
				return;
			}
		case 27:
			{
				return;
			}
		default:
			{
				system("cls");
				printf("Неправильная инструкция\n\nНажмите любую клавишу");
				getch();
				break;
			}
		}
	}
}
