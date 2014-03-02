#include <iostream>


void DeleteList(List*& Point_First)
	//�������� ����� ������
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
	//�������� ��������, �� ������� ��������� Point_Current
	//0 - �������� �������
	//1 - ������ ����
	//2 - ������� �� ������ ��� �� ����������

	//���� ��������� ������� �� ������,
	//�� Point_First ����� ��������� �� ����� ������� ����� Point_Current
{
	if (Point_First == 0) return 1;
	if (Point_Current == 0) return 2;	
	List* P;

	//�������� ������� ��������
	if (Point_Current == Point_First)
	{
		P = Point_Current;
		Point_First = Point_First->next;
		Point_Current = Point_First;
		delete P;
		return 0;
	}

	//�������� �� ������������� �����
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
	//�������� ������������� ��������� ������
{
	List* P2;
	for (; Point_First && Point_First->next; Point_First = Point_First->next)
		while (!FindList(Point_First->next, P2, Point_First->data))
			DeleteList(Point_First->next, P2);
}

//--------- ���������� ��������� � ������ --------------
void Add_Items()
{
	do AddList(gets(buffer));
	while(strlen(buffer)>1);
}

//--------- ���������� ��������� �� ������ -------------
void Extracting_Elements()
{
	while(Pointer_First)
	{
		puts(Pointer_First->Str);
		Pointer_First=Pointer_First->p_next;
	}
}
