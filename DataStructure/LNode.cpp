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
	newnode = (LNode*)malloc(sizeof(struct LNode)); // ����ͷ�ڵ�
	if (newnode == NULL) {
		printf("����ͷ�ڵ�ʧ�ܣ��˳�����");
		exit(0);
	}
	newnode->next = NULL; // ͷ�ڵ��ָ������Ϊ��
	return newnode;
}

//β�巨��������
LinkList InitList(LinkList L, int length) {
	LNode* s = newNode(L);
	LNode* p = s; // ʹ�� p ����ԭ���� s
	int i = 1;
	while (i <= length) {
		LNode* newnode = newNode(L);
		newnode->data = i;
		p->next = newnode;
		p = newnode;
		i++;
	}
	return s; // ����ͷ�ڵ�
}


//ͷ�巨��
void printList(LinkList L) {
	if (L->next == NULL) {
		printf("�޷���ӡ����Ϊ������Ϊ��");
		return;
	}

	int position = 1;
	for (LNode* p = L->next; p != NULL; p = p->next) {
		printf("������ĵ�%d��λ�õ�ֵΪ%d\n", position, p->data);
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