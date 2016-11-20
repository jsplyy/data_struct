#include<stdio.h>

struct node
{
    int data;
    int next;
}nodes[100002];

int main()
{
    int address = 0, k = 0, n = 0;
    int i = 0;
    int pos = 0;
    int numbers[100002];
    int mid = 0, temp = 0, j = 0;
    scanf("%d %d %d", &address, &n, &k);

    for(i = 0; i < n; i++)
    {
        scanf("%d", &pos);
        scanf("%d %d", &nodes[pos].data, &nodes[pos].next);
    }

    //printf("%d %d %d", address, n, k);
    numbers[0] = address;
    for(i = 1; i < n; i++)
    {
        numbers[i] = nodes[numbers[i-1]].next;
        //printf("%d\n", numbers[i]);
    }
    i = 0;
    if(k%2)
    {
        mid = k / 2;
    }
    else
    {
        mid = k /2 - 1;
    }
    while(i+k <= n)
    {
        for(j = 0; j <= mid; j++)
        {
            temp = numbers[i+j];
            numbers[i+j] = numbers[i+k-1-j];
            numbers[i+k-1-j] = temp;
        }
        i += k;
    }

    for(i = 0; i < n-1; i++)
    {
        printf("%05d %d %05d\n", numbers[i], nodes[numbers[i]].data, numbers[i+1]);
    }
    printf("%05d %d -1", numbers[i], nodes[numbers[i]].data);

    return 0;
}
