#include <stdio.h>
#include <stdlib.h>

#define ElemType int
#define LIST_INIT_SIZE 100
#define LIST_INCREMENT 10

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;

typedef struct 
{
	ElemType *elem;
	int length;
	int listSize;
}SqList;

Status InitSqList(SqList &L);
Status InsertSqList(SqList &L, int i, ElemType e);
Status DeleteListSq(SqList &L, int i, ElemType& e);
Status MergeSqList(SqList La, SqList Lb, SqList &Lc);

int main()
{
	SqList L;
	SqList La, Lb, Lc;
	ElemType e;
	InitSqList(L);
	InitSqList(La);
	InitSqList(Lb);
	InitSqList(Lc);

	InsertSqList(L, 1, 100);
	InsertSqList(L, 2, 200);
	InsertSqList(L,3, 300);
	DeleteListSq(L, 2, e);
	printf("L[0]=%d\n", L.elem[0]);
	printf("delete L[1]=%d\n", e);
	printf("atfer delete L[1]=%d\n", L.elem[1]);
	
	for(int i = 1; i <= 10; i++)
	{
		InsertSqList(La, i, i*1000);
	}

	for(int i = 1; i <= 5; i++)
	{
		InsertSqList(Lb, i, i);
	}
	MergeSqList(La, Lb, Lc);
	for(int i = 0; i< 15; i++)
	{
		printf("atfer merge data Lc[%d]=%d\n", i+1, Lc.elem[i]);
	}
	return 0;
}

Status InitSqList(SqList &L)
{
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(!L.elem)
	{
		return OVERFLOW;		
	}
	L.length = 0;
	L.listSize = LIST_INIT_SIZE;
	return OK;
}

Status InsertSqList(SqList &L, int i, ElemType e)
{
	ElemType* newBase;
	ElemType* p, *q;
	if(i < 1 || i > L.length + 1) 
		return ERROR;
	if(L.length >= L.listSize)
	{
		newBase = (ElemType *)realloc(L.elem, (L.listSize + LIST_INCREMENT) * sizeof(ElemType));
		if(!newBase)
		{
			exit(OVERFLOW);
		}
		L.elem = newBase;
		L.listSize += LIST_INCREMENT;
	}
	q = &(L.elem[i-1]);
	for(p = &(L.elem[i-1]); p >= q; --p)
	{
		*(p + 1) = *p;
	}
	*q = e;
	++L.length;
	return OK;
}

Status DeleteListSq(SqList &L, int i, ElemType &e)
{
	ElemType* p, *q;
	if(i < 1 || (i > L.length))
	{
		return ERROR;		
	}
	p = &(L.elem[i-1]);
	e = *p;
	q = L.elem + L.length -1;
	for(++p; p<=q;++p)
	{
		*(p-1) = *p;
	}
	--L.length;
	return OK;
}

Status MergeSqList(SqList La, SqList Lb, SqList &Lc)
{
	ElemType *pa, *pb, *pc, *paLast, *PbLast;
	pa = La.elem;
	pb = Lb.elem;
	Lc.listSize = Lc.length = La.length + Lb.length;
	pc = Lc.elem = (ElemType *)malloc(Lc.listSize * sizeof(ElemType));
	if (!Lc.elem)
	{
		exit(OVERFLOW);
	}
	paLast = La.elem + La.length -1;
	PbLast = Lb.elem + Lb.length -1;
	while(pa <= paLast && pb <= PbLast)
	{
		if(*pa <= *pb)
		{
			*pc++ = *pa++;
		}
		else
		{
			*pc++ = *pb++;
		}
	}
	while(pa <= paLast)
	{
		*pc++ = *pa++;
	}
	while(pb <= PbLast)
	{
		*pc++ = *pb++;
	}
}