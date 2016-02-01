#include <malloc.h>
#include <iostream>
#define ERROR -1
#define LIST_INIT_SIZE 50
#define LISTINCREMENT 10
#define NoMemory -2
#define OK 0


typedef struct {
	double score;
	bool boy;
}student;

typedef student ElemType;

typedef struct {
	ElemType *elem;
	int length;
	int listsize;
}SqList;



int InitList_Sq(SqList &L) {
	L.elem = (ElemType*)malloc(LIST_INIT_SIZE
		*sizeof(ElemType));
	if (!L.elem)	return -1;
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return 0;
}
int ListInsert_Sq(SqList &L, int i, ElemType e)
{
	// 判断i是否合法
	if (i < 1 || i > L.length + 1)
		return ERROR;
	// 若线性表空间不足，再分配一些空间
	if (L.length >= L.listsize)
	{
		ElemType *newbase = (ElemType *)realloc
			(L.elem,
				(L.listsize + LISTINCREMENT)*
				sizeof(ElemType)
				);
		if (!newbase)	return NoMemory;
		free(L.elem); L.elem = newbase;
		L.listsize += LISTINCREMENT;
	}
	// q指向插入的位置
	ElemType * q = &(L.elem[i - 1]);
	// p指向最后一个元素，
	// 从p到q的所有元素后移一个单元
	ElemType *p;
	for (p = &(L.elem[L.length - 1]);
	p >= q; --p)
		*(p + 1) = *p;
	*q = e;         // 写进待插入的元素e
	++L.length;    // 表长加1
	return OK;
}
int ListDelete_Sq
(SqList &L, int i, ElemType &e)
{
	if ((i < 1) || (i > L.length))
		return ERROR;
	ElemType *p, *q;
	p = &(L.elem[i - 1]); //p指向被删除的节点
	e = *p;             //e得到被删除的节点的值
						// q指向最后一个节点
	q = L.elem + L.length - 1;
	// 从p+1到q的所有节点前移一个单元
	for (++p; p <= q; ++p)
		*(p - 1) = *p;
	--L.length;        // 表长减1
	return OK;
}


int Length(SqList L) {
	return L.length;
}

bool GetElem(SqList L, int i, ElemType &e) {
	if (i<1 || i>L.length) return false;
	e = L.elem[i - 1];//e = *(L.elem+i-1);
	return true;

}

int main() {
	student s;
	SqList L;

	InitList_Sq(L);
	s.score = 60; s.boy = true;
	ListInsert_Sq(L, 1, s);
	s.score = 70; s.boy = false;
	ListInsert_Sq(L, 1, s);
	s.score = 90; s.boy = false;
	ListInsert_Sq(L, 2, s);

	int n = Length(L);// int n = L.length;
	for (int i = 1; i <= n; i++) {
		GetElem(L, i, s);
		std::cout << s.score << " " << s.boy << "\n";
	}

	ListDelete_Sq(L, 1, s);
	std::cout << "删除的1号元素是："<<s.score << " " << s.boy << "\n";

	n = Length(L);
	for (int i = 1; i <= n; i++) {
		GetElem(L, i, s);
		std::cout << s.score << " " << s.boy << "\n";
	}

	double average_score = 0;
	for (int i = 1; i <= n; i++) {
		GetElem(L, i, s);
		average_score += s.score;
	}
	average_score /= n;
	std::cout << "平均分是" << average_score << "\n";
	return 0;
}