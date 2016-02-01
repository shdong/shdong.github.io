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
	// 寻找第i-1个节点
	while (p && j < i - 1) {
		p = p->next;
		++j;
	}
	// 若第i-1个节点不存在
	if (!p || j > i - 1)
		return ERROR;
	
	// 生成一个新节点，并链接到L中
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
	// 让p指向第i-1个节点
	while (p && j < i - 1) {
		p = p->next;
		++j;
	}
	// 若第i个节点不存在
	if (!(p->next) || j > i - 1)
		return ERROR;
	LNode* q = p->next; // q指向待删除节点
	p->next = q->next; // 使q脱离链表
	e = q->data;       // e得到q的数据
	free(q);           // 释放q的空间
	return OK;
}

int GetElem_L
(LNode* L, int i, ElemType &e)
{
	LNode* p = L->next;  int j = 1;
	// 循环直到p为空或到了第i个节点
	while (p && j < i) {
		p = p->next;
		++j;
	}
	if (!p || j > i)   // 第i个节点不存在
		return ERROR;
	e = p->data;      // copy数据到e中
	return OK;
}

int SetElem_L
(LNode* L, int i, ElemType e)
{
	LNode* p = L->next;  int j = 1;
	// 循环直到p为空或到了第i个节点
	while (p && j < i) {
		p = p->next;
		++j;
	}
	if (!p || j > i)   // 第i个节点不存在
		return ERROR;
	p->data=e;      // copy数据到e中
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