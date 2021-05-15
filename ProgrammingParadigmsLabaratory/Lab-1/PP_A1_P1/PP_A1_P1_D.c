#include <stdio.h>
#include <stdlib.h>

void print(int temp[],int len)
{
    if (len > 0)
    {
        len--;
        printf("%d\n", temp[len]);
        print(temp, len);
    }
}

int main()
{
    int n;

    printf("Enter length of list: ");
    scanf("%d", &n);

    int list[n];

    for(int i = 0; i < n; i++)
    {
        printf("Enter the element number %d: - ", i+1);
        scanf("%d", &list[i]);
    }

    printf("Elements of array in reverse order: -\n");
    print(list, n);
    return 0;
}
