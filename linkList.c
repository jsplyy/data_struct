#include <stdio.h>
#include <stdlib.h>

#define ElemType int

#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OK 1
#define OVERFLOW -2

typedef int Status;

typedef struct LNode
{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

void createLinkList(LinkList &L, int n);
Status insertLinkListElem(LinkList &L, int i, ElemType e);
Status DeleteLinkListElem(LinkList &L, int i, ElemType &e);
Status getLinkListElem(LinkList L, int i, ElemType &e);
void mergeLinkList(LinkList &La, LinkList &Lb, LinkList &Lc);

int main(int argc, char const *argv[])
{
	/* code */
	LinkList L;
	LinkList La = L, Lb, Lc;
	ElemType e = 0;
	createLinkList(L, 1);
	getLinkListElem(L, 1, e);
	insertLinkListElem(L, 2, 100);
	insertLinkListElem(L, 3, 200);
	printf("get LinkList 1=%d\n", e);
	DeleteLinkListElem(L, 2, e);
	printf("delete LinkList 2=%d\n", e);
	getLinkListElem(L,2,e);
	printf("after delete LinkList 2 = %d", e);

    createLinkList(Lb,1);

	insertLinkListElem(Lb,1,45);
	insertLinkListElem(Lb,2,50);
	mergeLinkList(La, Lb, Lc);
	return 0;
}

Status getLinkListElem(LinkList L, int i, ElemType &e)
{
	LinkList p = L->next;
	int j = 1;
	while(p && j < i)
	{
		p = p->next;
		++j;
	}
	if(!p || j > i)
	{
		return ERROR;
	}
	e = p -> data;
	return OK;
}

Status insertLinkListElem(LinkList &L, int i, ElemType e)
{
	LinkList p = L;
	LinkList s = (LinkList) malloc(sizeof(LNode));
	int j = 0;
	while(p && j < i-1)
	{
		p = p->next;
		++j;
	}
	if(!p || j > i-1)
	{
		return ERROR;
	}
	s->data = e;
	s->next = p->next;
	p->next = s;
	return OK;
}

Status DeleteLinkListElem(LinkList &L, int i, ElemType &e)
{
	LinkList p = L;
	LinkList q;
	int j = 0;
	while(p->next && j < i-1)
	{
		p = p->next;
		++j;
	}
	if(!(p->next) || j > i-1)
	{
		return ERROR;
	}
	q = p->next;
	p->next = q->next;
	e = q->data;
	free(q);
	return OK;
}

void createLinkList(LinkList &L, int n)
{
	L = (LinkList)malloc(sizeof(LNode));
	LinkList p;
	L->next = NULL;
	for (int i = n; i > 0; --i)
	{
		/* code */
		p = (LinkList)malloc(sizeof(LNode));
		scanf("%d", &p->data);
		p->next = L->next;
		L->next = p;
	}
}

void mergeLinkList(LinkList &La, LinkList &Lb, LinkList &Lc)
{
    LinkList pa, pb, pc;
    pa = La->next;
    pb = Lb->next;
    Lc = pc = La;
    while(pa && pb)
    {
        if(pa->data <= pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa?pa:pb;
    free(Lb);
}
