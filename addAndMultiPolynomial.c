#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int coe;
    int exe;
    struct node *next;
}polyNode, *listNode;

listNode multiPolyList(listNode L1, listNode L2)
{
    listNode ss, temp1, temp2, temp3, p, q;
    temp1 = L1->next;
    temp2 = L2->next;
    int c = 0, e = 0;
    ss = (listNode)malloc(sizeof(polyNode));
    ss->next = NULL;
    p = ss;
    if(!L1->next && !L2->next)
    {
        return NULL;
    }
    while(temp1)
    {
        temp2 = L2->next;
        while(temp2)
        {
            c = temp1->coe * temp2->coe;
            e = temp1->exe + temp2->exe;

            // reset q pos.
            q = ss->next;
            p = ss;
            if(c)
            {
                if(!q)
                {
                    //create and insert fisrt.
                    q = (listNode)malloc(sizeof(polyNode));
                    q->coe = c;
                    q->exe = e;
                    q->next = NULL;
                    ss->next = q;
                }
                while(q)
                {
                    if(e > q->exe)
                    {
                        // insert before q.
                        temp3 = (listNode)malloc(sizeof(polyNode));
                        temp3->coe = c;
                        temp3->exe = e;
                        temp3->next = q;
                        p->next = temp3;
                    }
                    else
                    {
                        if(q->exe == e)
                        {
                            q->coe += c;
                        }
                        else
                        {
                            if(!q->next)
                            {
                                //add in last pos.
                                temp3 = (listNode)malloc(sizeof(polyNode));
                                temp3->coe = c;
                                temp3->exe = e;
                                temp3->next = NULL;
                                q->next = temp3;
                            }
                            else
                            {
                                //insert between q and q->next.
                                temp3 = (listNode)malloc(sizeof(polyNode));
                                temp3->coe = c;
                                temp3->exe = e;
                                temp3->next = q->next;
                                q->next = temp3;
                            }
                        }
                    }
                    p = q;
                    q = q->next;

                }
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    return ss;

}

listNode addPolyList(listNode L1, listNode L2)
{
    listNode ss, temp1, temp2, temp3, q;
    ss = (listNode)malloc(sizeof(polyNode));
    ss->next = NULL;
    q = ss;

    temp1 = L1->next;
    temp2 = L2->next;

    if(!temp1 && !temp2)
    {
        if(!temp1)
        {
            return temp2;
        }
        else
        {
            return temp1;
        }
    }

    while(temp1 && temp2)
    {
        temp3 = (listNode)malloc(sizeof(polyNode));
        temp3->next = NULL;
        if(temp1->exe > temp2->exe)
        {
            temp3->coe = temp1->coe;
            temp3->exe = temp1->exe;
            temp1 = temp1->next;
        }
        else
        {
            if(temp1->exe == temp2->exe)
            {
                temp3->coe = temp1->coe + temp2->coe;
                if(!temp3->coe)
                {
                    free(temp3);
                    temp1 = temp1->next;
                    temp2 = temp2->next;
                    continue;
                }
                temp3->exe = temp1->exe;
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else
            {
                temp3->coe = temp2->coe;
                temp3->exe = temp2->exe;
                temp2 = temp2->next;
            }
        }
        q->next = temp3;
        q = q->next;
    }
    temp3->next = temp1?temp1:temp2;

    return ss;
}

int main()
{
    int m = 0, n = 0;
    int i = 0;
    listNode s1, s2, p, q, addResult, multiResult;

    scanf("%d", &m);
    s1 = (listNode)malloc(sizeof(polyNode));
    s1->next = NULL;
    q = s1;
    for(i = 0; i < m; i++)
    {
        p = (listNode)malloc(sizeof(polyNode));
        scanf("%d %d", &p->coe, &p->exe);
        p->next = q->next;
        q->next = p;
        q = q->next;
    }

    scanf("%d", &n);
    s2 = (listNode)malloc(sizeof(polyNode));
    s2->next = NULL;
    q = s2;
    for(i = 0; i< n; i++)
    {
        p = (listNode)malloc(sizeof(polyNode));
        scanf("%d %d", &p->coe, &p->exe);
        p->next = q->next;
        q->next = p;
        q = q->next;
    }

//    p = s1->next;
//    for(i = 0; i < m; i++)
//    {
//        printf("%d %d\n", p->coe, p->exe);
//        p = p->next;
//    }
//    p = s2->next;
//    for(i = 0; i < n; i++)
//    {
//        printf("%d %d\n", p->coe, p->exe);
//        p = p->next;
//    }

    addResult = addPolyList(s1, s2);

    p = addResult->next;
//    while(p)
//    {
//        printf("%d %d\n", p->coe, p->exe);
//        p = p->next;
//    }

    multiResult = multiPolyList(s1, s2);
    p = multiResult->next;
    while(p)
    {
        printf("%d %d\n", p->coe, p->exe);
        p = p->next;
    }



    return 0;
}
