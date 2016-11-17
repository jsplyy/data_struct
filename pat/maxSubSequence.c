#include<stdio.h>

int main(int argc, char const *argv[])
{
    int n = 0, i = 0, negFlag = 1, low = 0, high = 0, start = 0;
    int a[100002];
    int sum = 0, total = 0;
    scanf("%d", &n);

    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }

    for(i=0;i<n;i++)
    {
        if(a[i]>=0)
        {
            negFlag = 0;
        }
        sum += a[i];
        if(sum>total)
        {
            total = sum;
            low = start;
            high = i;
        }
        if(sum<0)
        {
            sum = 0;
            start = i+1;
        }
    }
    if(total==0)
    {
        if(negFlag)
        {
            printf("%d %d %d", 0, a[0], a[n-1]);
        }
        else
        {
            printf("0 0 0");
        }
    }
    else
    {
        printf("%d %d %d", total, a[low], a[high]);
    }

	return 0;
}
