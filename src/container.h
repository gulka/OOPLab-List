#include "stdafx.h"

const int MAX_LEN_STR = 50; //������������ ����� ������
const int MAX_LEN_FILENAME = 24;  //������������ ����� ����� �����
const int DIR_VIEW = 1;      //������ ����������� �����������
const int BACK_VIEW = -1;    //�������� ����������� �����������

struct List
{
	char* data;
	List* next;
};

void AddList(List*&, char*);
void Add_Items();
void Extracting_Elements();
int  DeleteList(List*&, List*&);
void DeleteList(List*& Point_First);
void DeleteDblLists(List*);
void Menu1();
void Menu2(List*&);
void Menu3(List*&, List*&);