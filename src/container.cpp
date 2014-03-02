#include <iostream>

const int STR_LEN = 50; //максимальна€ длина строки
const int FN_LEN = 24;  //максимальна€ длина имени файла
const int DIR = 1;      //пр€мое направление отображени€
const int BACK = -1;    //обратное направление отображени€

typedef struct node {
		             char* p_value; 	// ”казатель на значение 
		     	     item* next;	// ”казатель на следующий узел
	                }l,*p
p pFirst = NULL;
char buffer[STR_LEN];

void Create_List(item*& pFirst, char* Str)  //—оздание контейнера
{
	item* P = new item;
	P->p_value = new char[strlen(Str)];
	strcpy(P->p_value, Str);
	P->next = pFirst;
	pFirst = P;
}

void Delete_List(item*& pFirst) //”ничтожение контейнера
{
	while (pFirst != 0)
		DeleteItem(pFirst, pFirst);
}

int DeleteItem(item*& pFirst, item*& pCur)
	//”даление элемента, на который указывает pCur
	//0 - удаление успешно
	//1 - список пуст
	//2 - элемент не найден или не существует

	//если удал€емый элемент не первый,
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
