#pragma once
#define  InitSize 10

typedef int ElemType;
typedef struct {
	ElemType* data;
	int length;
	int MaxSize1;
}SeqList;

void test2();
void InitSeqList(SeqList& L1);
void IncreaseSize(SeqList& L1, int len);
int GetElement(SeqList& L1, int pos);



