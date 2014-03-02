#include <iostream>

const int STR_LEN = 50; //������������ ����� ������
const int FN_LEN = 24;  //������������ ����� ����� �����
const int DIR = 1;      //������ ����������� �����������
const int BACK = -1;    //�������� ����������� �����������

typedef struct node {
		             char* p_value; 	// ��������� �� �������� 
		     	     item* next;	// ��������� �� ��������� ����
	                }l,*p
p pFirst = NULL;
char buffer[STR_LEN];

void Create_List(item*& pFirst, char* Str)  //�������� ����������
{
	item* P = new item;
	P->p_value = new char[strlen(Str)];
	strcpy(P->p_value, Str);
	P->next = pFirst;
	pFirst = P;
}

void Delete_List(item*& pFirst) //����������� ����������
{
	while (pFirst != 0)
		DeleteItem(pFirst, pFirst);
}

int DeleteItem(item*& pFirst, item*& pCur)
	//�������� ��������, �� ������� ��������� pCur
	//0 - �������� �������
	//1 - ������ ����
	//2 - ������� �� ������ ��� �� ����������

	//���� ��������� ������� �� ������,
	//�� pFirst ����� ��������� �� ����� ������� ����� pCur
{
	if (pFirst == 0) return 1;
	if (pCur == 0) return 2;	
	item* P;

	//�������� ������� ��������
	if (pCur == pFirst)
	{
		P = pCur;
		pFirst = pFirst->next;
		pCur = pFirst;
		delete P;
		return 0;
	}

	//�������� �� ������������� �����
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

//--------- ���������� ��������� � ������ --------------
void Add_Items()
{
	do Create_List(gets(buffer));
	while(strlen(buffer)>1);
}

//--------- ���������� ��������� �� ������ -------------
void Extracting_Elements()
{
	while(pFirst)
	{
		puts(pFirst->Str);
		pFirst=pFirst->p_next;
	}
}
