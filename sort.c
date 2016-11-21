#include<stdio.h>
void maopao(int *arr, int n)
{
    int i = 0, j = 0, temp = 0;
    for(i=0;i<n;i++)
    {
        for(j=1;j<n-i;j++)
        {
            if(arr[j-1]>arr[j])
            {
                temp = arr[j-1];
                arr[j-1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void xuanze(int *arr, int n)
{
    int i = 0, j = 0, temp = 0;
    for(i = 0; i< n - 1; i++)
    {
        for(j = i+1; j < n; j++)
        {
            if(arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
void Qsort(int a[], int low, int high)
{
    if(low >= high)
    {
        return;
    }
    int first = low;
    int last = high;
    int key = a[first];/*用字表的第一个记录作为枢轴*/

    while(first < last)
    {
        while(first < last && a[last] >= key)
        {
            --last;
        }

        a[first] = a[last];/*将比第一个小的移到低端*/

        while(first < last && a[first] <= key)
        {
            ++first;
        }

        a[last] = a[first];
/*将比第一个大的移到高端*/
    }
    a[first] = key;/*枢轴记录到位*/
    Qsort(a, low, first-1);
    Qsort(a, first+1, high);
}
int main()
{
    int n = 0, arr[100005];
    int i = 0;

    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }


    if(n<10005)
    {
    xuanze(arr, n);
    }
    else
    {
        Qsort(arr, 0, n);

    }

    for(i=0;i<n-1;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("%d",arr[i]);
    return 0;
}

