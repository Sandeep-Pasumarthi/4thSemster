#include <stdio.h>
#include <stdlib.h>

void replace(char arr[], char lock, char key, int n)
{
    if ((n-1) == 0)
    {
        return;
    }
    if (arr[n-1] == lock)
    {
        arr[n-1] = key;
    }

    replace(arr, lock, key, n-1);
}

int main()
{
    char lock, key;
    int len;

    printf("Enter length of the string: - ");
    scanf("%d", &len);

    char arr[len];

    printf("Enter the string: - ");
    scanf("%s", arr);

    printf("Enter the character to replaced by: - ");
    scanf("%c", &lock);

    printf("Enter the character to replaced with: - ");
    scanf("%c", &key);

    replace(arr, lock, key, len);

    printf("%s", arr);
}
