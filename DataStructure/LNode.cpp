#define CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "LNode.h"

void test3() {
	LinkList L = NULL;
	L = InitList(L, 5);
	printList(L);
	LNode* s = GetElem(L, 4);
	printf("%d %p", s->data, s->next);
}

LNode* newNode(LNode* newnode) {
	newnode = (LNode*)malloc(sizeof(struct LNode)); // 创建头节点
	if (newnode == NULL) {
		printf("创建头节点失败，退出程序");
		exit(0);
	}
	newnode->next = NULL; // 头节点的指针域置为空
	return newnode;
}

//尾插法建立链表
LinkList InitList(LinkList L, int length) {
	LNode* s = newNode(L);
	LNode* p = s; // 使用 p 代替原来的 s
	int i = 1;
	while (i <= length) {
		LNode* newnode = newNode(L);
		newnode->data = i;
		p->next = newnode;
		p = newnode;
		i++;
	}
	return s; // 返回头节点
}


//头插法：
void printList(LinkList L) {
	if (L->next == NULL) {
		printf("无法打印，因为该链表为空");
		return;
	}

	int position = 1;
	for (LNode* p = L->next; p != NULL; p = p->next) {
		printf("该链表的第%d个位置的值为%d\n", position, p->data);
		position++;
	}
}

LNode* GetElem(LinkList L, int i){
	LNode* p = L->next;

	if (i < 0) {
		return NULL;
	}
	if (i == 0) {
		return L;
	}
	//for (int j = 1; j < i && p != NULL; j++, p = p->next) {}
	int j = 1;
	while (j < i && p != NULL) {
		p = p->next;
		j++;
	}
	return p;
}