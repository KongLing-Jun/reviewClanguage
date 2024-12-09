#pragma once
#define MaxSize 10

typedef struct {
	int data[MaxSize];
	int length;
}SqList;

void test1();
void InitList(SqList &L);
void PrintList(SqList &L);
bool ListInsert(SqList& L, int pos, int e);
bool ListDelete(SqList& L, int pos, int& e);
int GetElem(SqList& L, int pos);
