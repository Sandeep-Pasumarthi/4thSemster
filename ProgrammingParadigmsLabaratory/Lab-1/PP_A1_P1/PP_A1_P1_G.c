#include<stdio.h>

void sort(int arr[], int n)
{
	int temp;

    if (n == 1)
        return;

    for (int i = 0; i < n-1; i++)
    {
        if (arr[i] > arr[i+1])
        {
            temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
        }
	}
    sort(arr, n-1);
}

int main()
{
	int n;
	printf("Enter length of the array: - ");
	scanf("%d",&n);
	printf("\n");

	int arr[n];

	for(int i = 0; i < n; i++)
    {
        printf("Enter element number %d in array: - ", i+1);
		scanf("%d", &arr[i]);
	}

	sort(arr, n);

	printf("\nAfter sorting array in ascending order: - ");
	for(int i = 0; i < n; i++)
    {
		printf("%d ", arr[i]);
	}

	return 0;
}
