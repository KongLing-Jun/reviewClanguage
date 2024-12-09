#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "SqList.h"

void InitList(SqList& L) 
{
	for (int i = 0; i < MaxSize; i++) 
	{
		L.data[i] = 0;
	}
	L.length = 0;
}

void PrintList(SqList& L) 
{
	for (int j = 0; j < L.length; j++) 
	{
		printf("data[%d] = %d\n", j, L.data[j]);
	}
}



bool ListInsert(SqList& L, int pos, int e)
{
	if (pos < 1 || L.length + 1 < pos) {
		return false;
	}

	if (L.length >= MaxSize) 
	{
		return false;
	}

	for (int i = L.length; i >= pos; i--)
	{
		L.data[i] = L.data[i - 1];
	}
	L.data[pos - 1] = e;
	L.length++;

	return true;
}

bool ListDelete(SqList &L, int pos, int& e)
{
	if (pos < 1 || pos > L.length) {
		return false;
	}
	e = L.data[pos - 1];
	for (int j = pos; j < L.length; j++) {
		L.data[j - 1] = L.data[j];
	}
	L.length--;
	return true;
}

int GetElem(SqList& L, int pos) {
	return L.data[pos - 1];
}

void test1()
{
	SqList L;
	InitList(L);
	ListInsert(L, 1, 1);
	ListInsert(L, 2, 2);
	ListInsert(L, 3, 4);
	ListInsert(L, 4, 8);
	int e = -1;
	if (ListDelete(L, 3, e))
	{

	}
	int pos = 0;
	scanf("%d\n", &pos);
	int elem =  GetElem(L, pos);
	printf("%d", elem);

	//printf("%d\n", judge);
	PrintList(L);
}