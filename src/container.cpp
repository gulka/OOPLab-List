#include <iostream>

const int STR_LEN = 50; //максимальная длина строки
const int FN_LEN = 24;  //максимальная длина имени файла
const int DIR = 1;      //прямое направление отображения
const int BACK = -1;    //обратное направление отображения

typedef struct node {
		             char* p_value; 	// Указатель на значение 
		     	     item* next;	// Указатель на следующий узел
	                }l,*p
p pFirst = NULL;
char buffer[STR_LEN];

void Create_List(item*& pFirst, char* Str)  //Создание контейнера
{
	item* P = new item;
	P->p_value = new char[strlen(Str)];
	strcpy(P->p_value, Str);
	P->next = pFirst;
	pFirst = P;
}

void Delete_List(item*& pFirst) //Уничтожение контейнера
{
	while (pFirst != 0)
		DeleteItem(pFirst, pFirst);
}

int DeleteItem(item*& pFirst, item*& pCur)
	//Удаление элемента, на который указывает pCur
	//0 - удаление успешно
	//1 - список пуст
	//2 - элемент не найден или не существует

	//если удаляемый элемент не первый,
	//то pFirst может указывать на любой элемент перед pCur
{
	if (pFirst == 0) return 1;
	if (pCur == 0) return 2;	
	item* P;

	//удаление первого элемента
	if (pCur == pFirst)
	{
		P = pCur;
		pFirst = pFirst->next;
		pCur = pFirst;
		delete P;
		return 0;
	}

	//удаление из произвольного места
	P = pFirst;
	while (P->next != pCur)
	{
		P = P->next;
		if (P == 0) return 2;
	}
	P->next = pCur->next;
	P = pCur;
	pCur = pCur->next;
	delete P;
	return 0;
}

//--------- Добавление элементов в список --------------
void Add_Items()
{
	do Create_List(gets(buffer));
	while(strlen(buffer)>1);
}

//--------- Извлечение элементов из списка -------------
void Extracting_Elements()
{
	while(pFirst)
	{
		puts(pFirst->Str);
		pFirst=pFirst->p_next;
	}
}
