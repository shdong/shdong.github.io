#include<iostream>
#include <malloc.h>
#define ERROR -1
#define OK 0

typedef double ElemType;

typedef struct node {
	ElemType data;
	struct node *next;
}LNode;

bool InitLkList(LNode * &L) {
	L = (LNode *)malloc(sizeof(LNode));
	if (L == 0) return false;
	L->next = 0;
	return true;
}

int ListInsert_Lk(LNode* &L, int i, ElemType e)
{
	LNode* p = L; int j = 0;
	// Ѱ�ҵ�i-1���ڵ�
	while (p && j < i - 1) {
		p = p->next;
		++j;
	}
	// ����i-1���ڵ㲻����
	if (!p || j > i - 1)
		return ERROR;
	
	// ����һ���½ڵ㣬�����ӵ�L��
	LNode *s = (LNode *)malloc(sizeof(LNode));
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

int ListDelete_Lk
(LNode* &L, int i, ElemType& e)
{
	LNode* p = L; int j = 0;
	// ��pָ���i-1���ڵ�
	while (p && j < i - 1) {
		p = p->next;
		++j;
	}
	// ����i���ڵ㲻����
	if (!(p->next) || j > i - 1)
		return ERROR;
	LNode* q = p->next; // qָ���ɾ���ڵ�
	p->next = q->next; // ʹq��������
	e = q->data;       // e�õ�q������
	free(q);           // �ͷ�q�Ŀռ�
	return OK;
}

int GetElem_L
(LNode* L, int i, ElemType &e)
{
	LNode* p = L->next;  int j = 1;
	// ѭ��ֱ��pΪ�ջ��˵�i���ڵ�
	while (p && j < i) {
		p = p->next;
		++j;
	}
	if (!p || j > i)   // ��i���ڵ㲻����
		return ERROR;
	e = p->data;      // copy���ݵ�e��
	return OK;
}

int SetElem_L
(LNode* L, int i, ElemType e)
{
	LNode* p = L->next;  int j = 1;
	// ѭ��ֱ��pΪ�ջ��˵�i���ڵ�
	while (p && j < i) {
		p = p->next;
		++j;
	}
	if (!p || j > i)   // ��i���ڵ㲻����
		return ERROR;
	p->data=e;      // copy���ݵ�e��
	return OK;
}

int main() {
	LNode *LL;
	ElemType  f=30 ;
	InitLkList(LL);
	ListInsert_Lk(LL, 1, f);
	f = 40;
	ListInsert_Lk(LL, 1, f);
	f = 50;
	ListInsert_Lk(LL, 1, f);
	LNode *p = LL->next;
	while (p) {
		std::cout << p->data << "\n";
		p = p->next;
	}

	SetElem_L(LL, 2, 10);
	
	ListDelete_Lk(LL, 3, f);
	
	std::cout << "\n";
	
	p = LL->next;
	while (p) {
		std::cout << p->data << "\n";
		p = p->next;
	}

}