#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {   //���嵥����������
	ElemType data;       //ÿһ���ڵ���һ������Ԫ��
	struct LNode* next;  //ָ��ָ����һ���ڵ�
}LNode, *LinkList;

//struct LNode {           //���嵥����������
//	ElemType data;       //ÿһ���ڵ���һ������Ԫ��
//	struct LNode* next;  //ָ��ָ����һ���ڵ�
//};

//typedef struct LNode LNode;
//typedef struct LNode* LinkList;
//Ҫ��ʾһ��������ʱ��ֻ��Ҫ����һ��ͷָ��L��ָ������ĵ�һ���ڵ� 
//LNode *L/LinkList L ǰ��һ��������ʾһ���ڵ㣬����һ���ʾ����������
//struct LNode* p = (struct LNode*)malloc(sizeof(struct LNode)); //δ�Զ�������
//LNode* p = (LNode*)malloc(sizeof(LNode));                      //�Զ�������

void test3();
LinkList InitList(LinkList L, int length);
void printList(LinkList L);
LNode* GetElem(LinkList L, int i);
