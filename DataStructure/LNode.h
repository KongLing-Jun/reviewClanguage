#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct LNode {   //定义单链表结点类型
	ElemType data;       //每一个节点存放一个数据元素
	struct LNode* next;  //指针指向下一个节点
}LNode, *LinkList;

//struct LNode {           //定义单链表结点类型
//	ElemType data;       //每一个节点存放一个数据元素
//	struct LNode* next;  //指针指向下一个节点
//};

//typedef struct LNode LNode;
//typedef struct LNode* LinkList;
//要表示一个单链表时，只需要声明一个头指针L，指向单链表的第一个节点 
//LNode *L/LinkList L 前者一般用来表示一个节点，后者一般表示整个单链表。
//struct LNode* p = (struct LNode*)malloc(sizeof(struct LNode)); //未自定义类型
//LNode* p = (LNode*)malloc(sizeof(LNode));                      //自定义类型

void test3();
LinkList InitList(LinkList L, int length);
void printList(LinkList L);
LNode* GetElem(LinkList L, int i);
