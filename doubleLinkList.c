/*双向非循环链表*/

#include <stdio.h>
#include <stdlib.h>

#define ElemType int

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OVERFLOW -2

typedef int Status;

typedef struct DuNode
{
	ElemType data;
	struct DuNode *prior;
	struct DuNode *next;
}DuNode, *DuLinkList;

typedef struct 
{
	DuLinkList head, tail;
	int len;
}DoubleLinkList;

Status InitDoubleLinkList(DuLinkList &p);
int GetDoubleLinkListLength(DuLinkList &p);
Status InsertDoubleLinkList(DuLinkList &p, int i, ElemType e);
int main(int argc, char const *argv[])
{
	/* code */
	DuLinkList L;
	int e = 0;
	InitDoubleLinkList(L);
	e = GetDoubleLinkListLength(L);
	printf("the current List length is:%d\n", e);
	InsertDoubleLinkList(L, 1, 100);
	e = GetDoubleLinkListLength(L);
	printf("the current List length is:%d\n", e);	
	InsertDoubleLinkList(L, 1, 200);
	e = GetDoubleLinkListLength(L);
	printf("the current List length is:%d\n", e);
	printf("location 1 data is:%d\n", L->next->data);
	return 0;
}

Status InitDoubleLinkList(DuLinkList &p)
{
	p = (DuLinkList)malloc(sizeof(DuNode));
	if(p)
	{
		p->next = p->prior = NULL;
	}
	else
	{
		exit(OVERFLOW);
	}
}

int GetDoubleLinkListLength(DuLinkList &p)
{
	int i = 0;
	DuLinkList s = p;
	while(s->next != NULL)
	{
		i++;
		s = s->next;
	}
	return i;
}

Status InsertDoubleLinkList(DuLinkList &p, int i, ElemType e)
{
	int j = 0;
	DuLinkList s = p;
	DuLinkList t;
	/* check the position valid */
	// if( i<1 || i>GetDoubleLinkListLength(p)+2)
	// {
	// 	return ERROR;
	// }
	while((j<i)&&(s->next!=NULL))
	{
		j++;
		s = s->next;
	}
	t = (DuLinkList)malloc(sizeof(DuNode));
	t->data = e;
	if((s->next==NULL)&&(j<i))
	{
		t->next = s->next;
		t->prior = s;
		s->next = t;
	}
	else
	{
		t->next = s;
		// printf("s->data=%d\n", s->data);
		t->prior = s->prior;
		s->prior->next = t;
		s->prior = t;
	}

	return OK;

	
}