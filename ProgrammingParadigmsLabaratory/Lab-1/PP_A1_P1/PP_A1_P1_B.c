#include <stdio.h>

int find_max(int list[], int pos, int max)
{

    if (pos == 0)
        return max;

    if (pos > 0)
    {
        if (list[pos] > max)
        {
            max = list[pos];
        }

        return find_max(list, pos - 1, max);
    }
}

int main()
{

    int len, max;

    printf("Enter length of the list: - ");
    scanf("%d", &len);

    int list[len];

    for (int i = 0; i < len ; i++)
    {
        int x;
        printf("Enter element number %d: - ", i+1);
        scanf("%d", &x);
        list[i] = x;
    }

    if (len == 0)
    {
        printf("Empty list\n");
    }

    else
    {
        max = list[0];
        max = find_max(list, len - 1, max);
        printf("\nThe largest number in the list is: %d\n", max);
    }

    return 0;
}

