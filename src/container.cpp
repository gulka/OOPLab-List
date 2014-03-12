#include "container.h"


void DeleteList(List*& Point_First)	
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
{
	if (Point_First == 0) return 1;
	if (Point_Current == 0) return 2;	
	List* P;

	if (Point_Current == Point_First)
	{
		P = Point_Current;
		Point_First = Point_First->next;
		Point_Current = Point_First;
		delete P;
		return 0;
	}

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
{
	List* P2;
	for(; Point_First && Point_First->next; Point_First = Point_First->next)
		while(!FindList(Point_First->next, P2, Point_First->data))
			DeleteList(Point_First->next, P2);
}

void Add_Items()
{
	do AddList(gets(buffer));
	while(strlen(buffer)>1);
}

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
{
	List* pCFirst1 = CopyList(Point_First1);
	List* pCFirst2 = CopyList(Point_First2);
	List* pCLast1 = pCFirst1;
	if (pCLast1 != 0)
	{
		while (pCLast1->next != 0)
			pCLast1 = pCLast1->next; 
		pCLast1->next = pCFirst2;  
	}
	else
		pCFirst1 = pCFirst2;
	return pCFirst1;
}

List* SubtrLists(List* Point_First1, List* Point_First2)
{
	List* Point_NewFirst = 0;
	List* P2;
	for (; Point_First1; Point_First1 = Point_First1->next)
		if (FindList(Point_First2, P2, Point_First1->data) != 0)
			AddList(Point_NewFirst, Point_First1->data);
	return Point_NewFirst;
}

List* CrossLists(List* Point_First1, List* Point_First2)
{
	List* Point_NewFirst = 0;
	List* P2;
	for (; Point_First1; Point_First1 = Point_First1->next)
		if (FindList(Point_First2, P2, Point_First1->data) == 0)
			AddList(Point_NewFirst, Point_First1->data);
	return Point_NewFirst;
}

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

int ExtractingFile(List*& Point_First, FILE* F)
{
	if (F == 0)
		return 1;
	char strBuf[MAX_LEN_STR];
	int i;
	
	Point_First = new List;
	fgets(strBuf, MAX_LEN_STR, F);
	strBuf[strlen(strBuf)-1] = '\0';
	Point_First->data = new char [strlen(strBuf)];
	strcpy(Point_First->data, strBuf);
	List* P = Point_First;
	P->next = 0;
	
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

int NumberOfElements(List* Point_First)
{
	int i = 0;
	for (; Point_First; Point_First = Point_First->next)
		i++;
	return i;
}

void BypassAllElements(List* Point_First, int Direction)	
{
	if (Direction == BACK_VIEW)
	{
		if (Point_First != 0)
		{
			BypassAllElements(Point_First->next, BACK_VIEW);
		}
	}
	else
	{
		while (Point_First != 0)
		{
			Point_First = Point_First->next;
		}
	}
}
