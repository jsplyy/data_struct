/* a1xn1+a2xn2+...   + b1xm1+b2xm2+..... */

#include <stdio.h>
#include <stdlib.h>

typedef int Status;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef struct 
{
	float coef;
	int expn;
}ElemType;

typedef struct node
{
	ElemType e;
	struct node *next;
}linkNode, *linkList;

typedef linkList polynomail;

void CreatePolyNomail(linkList &L)
{
	linkList p;
	int i = 0;
	L = (polynomail)malloc(sizeof(linkNode));
	L->e.coef = 0;
	L->e.expn = -1;
	L->next = NULL;
}

void InsertPolyNomail(linkList &L, ElemType e)
{
	linkList p=L, q;
	q = (linkList)malloc(sizeof(linkNode));
	q->e = e;

	while((p->next!=NULL)&&(p->next->e.expn<q->e.expn))
	{
		p = p->next;
	}
	q->next = p->next;
	p->next = q;
}

void AddPolyNomail(linkList La, linkList Lb, linkList Lc)
{

}

int main(int argc, char const *argv[])
{
	/* code */
	linkList L,Lb;
	int i = 0;
	ElemType e;
	CreatePolyNomail(L);
	CreatePolyNomail(Lb);
	for(i=1; i<=3;i++)
	{
		e.coef = i;
		e.expn = i;
		InsertPolyNomail(L, e);
	}
	printf("e.coef1=%.f e.expn=%d\n", L->next->e.coef, L->next->e.expn);
	printf("e.coef1=%.f e.expn=%d\n", L->next->next->e.coef, L->next->next->e.expn);

	for(i=5; i<=7;i++)
	{
		e.coef = i;
		e.expn = i;
		InsertPolyNomail(Lb, e);
	}
	printf("Lb e.coef1=%.f e.expn=%d\n", Lb->next->e.coef, Lb->next->e.expn);
	printf("Lb e.coef1=%.f e.expn=%d\n", Lb->next->next->e.coef, Lb->next->next->e.expn);	
	return 0;
}