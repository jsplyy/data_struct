#include<stdio.h>
#include<stdlib.h>

#define ERROR 0
#define OK 1
#define TRUE 1
#define FALSE 0

#define ElemType int
#define MAXSIZE 1000

typedef int Status;

typedef struct 
{
	ElemType data;
	int cur;
}component, sLinkList[MAXSIZE];

void initStaticLinkList(sLinkList &space);
int mallocStaticLinkList(sLinkList &space);
void freeStaticLinkList(sLinkList &space, ElemType k);
int locateStaticLinkListElem(sLinkList &space, ElemType e);

int main(int argc, char const *argv[])
{
	/* code */
	/*定义一个静态链表数组*/
	
	return 0;
}

void initStaticLinkList(sLinkList &space)
{
	for(int i = 0; i < MAXSIZE -1 ; ++i)
	{
		space[i].cur = i + 1;
	}
	space[MAXSIZE-1].cur = 0;
}

int mallocStaticLinkList(sLinkList &space)
{
	int i = space[0].cur;
	if(space[0].cur)
	{
		space[0].cur = space[i].cur;
	}
	return i;
}

void freeStaticLinkList(sLinkList &space, ElemType k)
{
	space[k].cur = space[0].cur;
	space[0].cur = k;
}

Status insertStaticLinkList(sLinkList &space, ElemType e)
{
	int i = mallocStaticLinkList(space);
	if(i > 0)
	{
		space[i].data = e;
	}

}

int locateStaticLinkListElem(sLinkList &space, ElemType e)
{
	int i = space[0].cur;
	while(i && space[i].data != e)
	{
		i = space[i].cur;
		return i;
	}
}