#include <tchar.h>
#include <stdio.h>
#include <locale.h>
#include <iostream>
#include <conio.h>


const int MAX_LEN_STR = 50; 
const int MAX_LEN_FILENAME = 24;  
const int DIR_VIEW = 1;      
const int BACK_VIEW = -1;    

struct List
{
	char* data;
	List* next;
};

void AddList(List*&, char*);
int DeleteList(List*&, List*&);
void DeleteList(List*& Point_First);
void DeleteDblLists(List*);
void Add_Items();
void Extracting_Elements();
void ReversContain();
int SaveToFile(List*, FILE*);
int ExtractingFile(List*&, FILE*);
void Menu1();
void Menu2(List*&);
void Menu3(List*&, List*&);
List* LinkLists(List*, List*);
List* SubtrLists(List*, List*);
List* CrossLists(List*, List*);
int NumberOfElements(List*);
void BypassAllElements(List*, int);