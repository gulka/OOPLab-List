#include "container.h"


void DeleteList(List*& Point_First)
	//Удаление всего списка
{
	while (Point_First != 0)
		DeleteList(Point_First, Point_First);
}

void AddList(List*& Point_First, char* Str_buf)
	
{
	List* P = new List;
	P->data = new char[strlen(Str_buf)];
	strcpy(P->data, Str_buf);
	P->next = Point_First;
	Point_First = P;
}

int DeleteList(List*& Point_First, List*& Point_Current)
	//Удаление элемента, на который указывает Point_Current
	//0 - удаление успешно
	//1 - список пуст
	//2 - элемент не найден или не существует

	//если удаляемый элемент не первый,
	//то Point_First может указывать на любой элемент перед Point_Current
{
	if (Point_First == 0) return 1;
	if (Point_Current == 0) return 2;	
	List* P;

	//удаление первого элемента
	if (Point_Current == Point_First)
	{
		P = Point_Current;
		Point_First = Point_First->next;
		Point_Current = Point_First;
		delete P;
		return 0;
	}

	//удаление из произвольного места
	P = Point_First;
	while (P->next != Point_Current)
	{
		P = P->next;
		if (P == 0) return 2;
	}
	P->next = Point_Current->next;
	P = Point_Current;
	Point_Current = Point_Current->next;
	delete P;
	return 0;
}

void DeleteDblLists(List* Point_First)
	//удаление повторяющихся элементов списка
{
	List* P2;
	for (; Point_First && Point_First->next; Point_First = Point_First->next)
		while (!FindList(Point_First->next, P2, Point_First->data))
			DeleteList(Point_First->next, P2);
}

//--------- Добавление элементов в список --------------Roman_Maks
void Add_Items()
{
	do AddList(gets(buffer));
	while(strlen(buffer)>1);
}

//--------- Извлечение элементов из списка -------------Roman_Maks
void Extracting_Elements()
{
	List* Point_First;
	while(Point_First)
	{
		puts(Point_First->data);
		Point_First=Point_First->next;
	}
}

List* LinkLists(List* Point_First1, List* Point_First2)
	//Объединение списков
{
	List* pCFirst1 = CopyList(Point_First1);
	List* pCFirst2 = CopyList(Point_First2);
	List* pCLast1 = pCFirst1;
	if (pCLast1 != 0)
	{
		while (pCLast1->next != 0)
			pCLast1 = pCLast1->next; //доходим до конца списка
		pCLast1->next = pCFirst2;  //связываем списки
	}
	else
		pCFirst1 = pCFirst2;
	return pCFirst1;
}

List* SubtrLists(List* Point_First1, List* Point_First2)
	//Возвращает указатель на результат вычитания списка Point_First2 из списка Point_First1
{
	List* Point_NewFirst = 0;
	List* P2;
	for (; Point_First1; Point_First1 = Point_First1->next)
		//если текущий элемент не найден во втором списке
		//то добавляем его в новый список
		if (FindList(Point_First2, P2, Point_First1->data) != 0)
			AddList(Point_NewFirst, Point_First1->data);
	return Point_NewFirst;
}

List* CrossLists(List* Point_First1, List* Point_First2)
	//пересечение
{
	List* Point_NewFirst = 0;
	List* P2;
	for (; Point_First1; Point_First1 = Point_First1->next)
		//если текущий элемент найден во втором списке
		//то добавляем его в новый список
		if (FindList(Point_First2, P2, Point_First1->data) == 0)
			AddList(Point_NewFirst, Point_First1->data);
	return Point_NewFirst;
}
//--------- Реверс нонтейнера --------------------------Roman_Maks
void ReversContain()
{
	List* Point_First;
	char* Point_Adress[]={NULL};
	int i=0,j,k;
	while(Point_First)
	{
		Point_Adress[i]=Point_First->data;
		Point_First=Point_First->next;
	}
	for(j=i;j<=0;j--)
	{
		Point_First->data=Point_Adress[j];
		Point_First=Point_First->next;
	}
}
//--------- Сохранение контейнера в файл ---------------Roman_Maks
int SaveToFile(List* Point_First, FILE* F)
{
	if (F == 0) return 1;
	while (Point_First != 0)
	{
		fputs(Point_First->data, F);
		fputc('\n', F);
		Point_First = Point_First->next;
	}
	fputc('\0', F);
	return 0;
}
//--------- Извлечение контейнера из файла--------------Roman_Maks
int ExtractingFile(List*& Point_First, FILE* F)
{
	if (F == 0)
		return 1;
	//буфер максимально допустимой длины
	char strBuf[MAX_LEN_STR];
	int i;
	
	//считываем первую строку, 
	//чтобы впоследствии не потерять указатель Point_First
	Point_First = new List;
	//через буфер, чтобы не выделять лишнюю память в списке
	fgets(strBuf, MAX_LEN_STR, F);
	strBuf[strlen(strBuf)-1] = '\0';
	Point_First->data = new char [strlen(strBuf)];
	strcpy(Point_First->data, strBuf);
	List* P = Point_First;
	P->next = 0;
	
	//считываем остальные строки
	for(;;)
	{
		if (*(fgets(strBuf, MAX_LEN_STR, F)) == '\0') return 0;
		strBuf[strlen(strBuf)-1] = '\0';
		P->next = new List;
		P = P->next;
		P->data = new char [strlen(strBuf)];
		strcpy(P->data, strBuf);
		P->next = 0;
	}
	return 0;
}
