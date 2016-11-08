#include <stdio.h>
#include <stdlib.h>

#define ElemType int

#define ERROR 0
#define TRUE 1
#define FALSE 0
#define OK 1

typedef int Status;
typedef struct CNode
{
	ElemType data;
	struct CNode *next;

}CNode, *CLinkList;

void createCircularLinkedList(CLinkList &cL, int n);
Status getCircularLinkedListElem(CLinkList &cL, int i, ElemType &e);

int main(int argc, char const *argv[])
{
	/* code */
	CLinkList cL;
	int e = 0;
	createCircularLinkedList(cL, 10);
	getCircularLinkedListElem(cL, 13, e);
	printf("getCircularLinkedListElem e=%d\n", e);
	return 0;
}

Status getCircularLinkedListElem(CLinkList &cL, int i, ElemType &e)
{
	int j = 0;
	CLinkList p = cL;
	if(i <= 0)
	{
		return ERROR;
	}
	while(j<i)
	{
		p = p->next;
		j++;
	}
	e = p->data;
	return OK;
}

void createCircularLinkedList(CLinkList & cL, int n)
{
	CLinkList p;
	cL = (CLinkList)malloc(sizeof(CNode));
	cL->next = cL;
	for(int i =1; i<= n; i++)
	{
		p = (CLinkList)malloc(sizeof(CNode));
		p->data = i;
		p->next = cL->next;
		cL->next = p;
	}	
}