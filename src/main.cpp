#include "container.h"

int main()
{
	setlocale(LC_CTYPE, "rus");
	Menu1();
	return(0);
}

void Menu1()
{
	setlocale(LC_CTYPE, "rus");
	const char* MENU_1 = 
"1 - New list\n2 - Open list\nEsc - Exit\n";

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
		case '2':
			{
				system("cls");
				printf("Enter the file name: \n");
				gets(FileName);
				F = fopen(FileName,"r");
				if (!F)
				{
					printf("Error opening file");
					getch();
					break;
				}
				ExtractingFile(pL1, F);
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
				printf("Error!\nRetype!");
				getch();
				break;
			}
		}
	}
}

void Menu2(List*& pL1)
{
	setlocale(LC_CTYPE, "rus");
	const char* MENU_2 =
"______\n\n \
1 - Save\t\t 8 - Change the direction of the display\n \
2 - Add\t\t 9 - Merge\n \
3 - Extract\t\
4 - Find\t\t 10 - Cross\n \
5 - Counting\t 0 - Deduct\n \
6 - Sorting \t\t Esc - Copy\
7 - Remove duplicate\n";

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
		case '1':
			{
				system("cls");
				printf("Enter the file name: \n");
				gets(FileName);
				if (!(F = fopen(FileName, "w")))
				{
					printf("Error opening file\n\nRetype!");
					getch();
					break;
				}
				SaveToFile(pL1, F);
				fclose(F);
				break;
			}
		case '2':
			{
				system("cls");
				printf("Enter string: \n");
				Add_Items();
				break;
			}
		case '3':
			    system("cls");
				Extracting_Elements();
				break;

		case '4':
			{
				system("cls");
				printf("Enter string: \n");
				gets(strBuf);
				switch (FindList(pL1, Point_Current, strBuf))
				{
				case 1:
					{
						system("cls");
						printf("List is empty\n\nPress any key");
						getch();
						break;
					}
				case 2:
					{
						system("cls");
						printf("No such element\n\nPress any key");
						getch();
						break;
					}
				default:
					Menu3(pL1, Point_Current);
				}
				break;
			}
		case '5':
			{
				system("cls");
				printf("%i List\n\nPress any key", CountLists(pL1));
				getch();
				break;
			}
		case '6':
			{
				SortList(pL1);
				break;
			}
		case '7':
			{
				DeleteDblLists(pL1);
				break;
			}
		case '8':
			{
				Direction = -(Direction);
				break;
			}
		case '9':
			{
				system("cls");
				printf("Enter the file name: \n");
				gets(FileName);
				F = fopen(FileName, "r");
				if (!F)
				{
					printf("Error\n\nPress any key");
					getch();
					break;
				}
				ExtractingFile(pL2, F);
				fclose(F);
				pL3 = LinkLists(pL1, pL2);
				DeleteList(pL2);
				Menu2(pL3);
				break;
			}
		case '10':
			{
				system("cls");
				printf("Enter the file name: \n");
				gets(FileName);
				F = fopen(FileName, "r");
				if (!F)
				{
					printf("Error\n\nPress any key");
					getch();
					break;
				}
				ExtractingFile(pL2, F);
				fclose(F);
				pL3 = CrossLists(pL1, pL2);
				DeleteList(pL2);
				Menu2(pL3);
				break;
			}
		case '0':
			{
				system("cls");
				printf("Enter the file name: \n");
				gets(FileName);
				F = fopen(FileName, "r");
				if (!F)
				{
					printf("Error\n\nPress any key");
					getch();
					break;
				}
				ExtractingFile(pL2, F);
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
				printf("Wrong command\n\nPress any key");
				getch();
				break;
			}
		}
	}
}

void Menu3(List*& pL1, List*& Point_Current)
{
	setlocale(LC_CTYPE, "rus");
	const char* MENU_3 = 
"______\n\n \
1 - Remove the list\n \
Esc - Back\n";

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
				printf("Invalid instruction\n\nPress any key");
				getch();
				break;
			}
		}
	}
}
