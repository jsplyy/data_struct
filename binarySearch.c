#include <stdio.h>

void binarySearch(int *arr, int n, int p)
{
	int low = 0, high = n - 1;
	int mid = n / 2;

	while(low < high)
	{
		mid = low + (high - low) / 2;
		if (p == arr[mid])
		{
			break;
		}
		else
		{
			if (p < arr[mid])
			{
				high = mid - 1;
			}	
			else
			{
				low = mid + 1;
			}
		}

	}

	if (p == arr[low])
	{
		printf("find p in arr[%d]\n", low);
	}
	else
	{
		printf("search finish and not found.\n");
	}

}

int main(int argc, char const *argv[])
{
	int arr[11] = {0,5,13,19,22,41,55,68,72,81,98};
	int arr2[2] = {34, 55};
	printf("binary search implement.\n");

	binarySearch(arr, 11, 55);
	binarySearch(arr2, 2, 55);
	return 0;
}