#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include "SeqList.h"

void test2()
{
	SeqList L1;
	InitSeqList(L1);
	IncreaseSize(L1, 5);
	int element = GetElement(L1, 3);
	printf("%d", element);
}

void InitSeqList(SeqList& L1)
{
	//用malloc函数申请一片连续的存储空间。
	L1.data = (ElemType*)malloc(InitSize * sizeof(ElemType));
	L1.length = 0;
	L1.MaxSize1 = InitSize;
}

void IncreaseSize(SeqList& L1, int len)
{
	ElemType* p = L1.data;
	L1.data = (ElemType*)malloc((L1.MaxSize1 + len) * sizeof(ElemType));
	for (int i = 0; i < L1.length; i++) {
		L1.data[i] = p[i];
	}	
	L1.MaxSize1 = L1.MaxSize1 + len;
	free(p);
}

int GetElement(SeqList& L1, int pos)
{
	return L1.data[pos - 1];
}



