#include <stdio.h>
#include <stdlib.h>

#define ElemType int
#define QueueLength 10

typedef struct binary_tree
{
    ElemType data;
    struct binary_tree *t_left;
    struct binary_tree *t_right;
}b_tree;

typedef struct queue_struct
{
    b_tree* bt_queue[QueueLength];
    int front;
    int end;
}queue;

void InitQueue(queue *q)
{
    q->front = 0;
    q->end = 0;
}
void queue_push(queue *q, b_tree *bt)
{
    if(q->end < QueueLength)
    {
        q->bt_queue[q->end] = bt;
        q->end++;
    }
}
b_tree* queue_pop(queue *q)
{
    b_tree* btp;
    btp = q->bt_queue[q->front];
    q->front++;
    return btp;
}
bool queueEmpty(queue *q)
{
    if((q->end-q->front)<1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void PreOrderTraverse(b_tree *bt);
void InOrderTraverse(b_tree *bt);
void PostOrderTraverse(b_tree *bt);
void levelOrderTraverse(b_tree *bt);

int main()
{
    b_tree bt1, bt2,bt3,bt4,bt5, bt6;
    bt1.data = 1;   bt1.t_left = &bt2;  bt1.t_right = &bt3;
    bt2.data = 2;   bt2.t_left = &bt4;  bt2.t_right = &bt5;
    bt3.data = 3;   bt3.t_left = &bt6;  bt3.t_right = NULL;
    bt4.data = 4;   bt4.t_left = NULL;  bt4.t_right = NULL;
    bt5.data = 5;   bt5.t_left = NULL;  bt5.t_right = NULL;
    bt6.data = 6;   bt6.t_left = NULL;  bt6.t_right = NULL;

    printf("bt1->data=%d\t", bt1.data);
    printf("bt2->data=%d\t",bt1.t_left->data);
    printf("bt3->data=%d\t",bt1.t_right->data);

    printf("\nPreOrderTraverse:");
    PreOrderTraverse(&bt1);

    printf("\nInOrderTraverse:");
    InOrderTraverse(&bt1);

    printf("\nPostOrderTraverse:");
    PostOrderTraverse(&bt1);

    printf("\nLevelOrderTraverse:");
    levelOrderTraverse(&bt1);

    return 0;
}


void PreOrderTraverse(b_tree *bt)
{
    if(bt == NULL)
    {
        return ;
    }
    printf("%d ",bt->data);
    PreOrderTraverse(bt->t_left);
    PreOrderTraverse(bt->t_right);
}

void InOrderTraverse(b_tree *bt)
{
    if(bt == NULL)
    {
        return ;
    }
    InOrderTraverse(bt->t_left);
    printf("%d ", bt->data);
    InOrderTraverse(bt->t_right);
}

void PostOrderTraverse(b_tree *bt)
{
    if(bt == NULL)
    {
        return ;
    }
    PostOrderTraverse(bt->t_left);
    PostOrderTraverse(bt->t_right);
    printf("%d ", bt->data);
}

void levelOrderTraverse(b_tree *bt)
{
    queue q;
    InitQueue(&q);

    queue_push(&q, bt);
    while(!queueEmpty(&q))
    {
        b_tree *btt;
        btt = queue_pop(&q);
        printf("%d ", btt->data);
        if(btt->t_left!=NULL)
        {
            queue_push(&q, btt->t_left);
        }
        if(btt->t_right!=NULL)
        {
            queue_push(&q, btt->t_right);
        }
    }

}
