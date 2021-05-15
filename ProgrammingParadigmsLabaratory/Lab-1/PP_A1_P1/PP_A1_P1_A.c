#include<stdio.h>
#include<string.h>

int compare(char *c1, int len1, char *c2, int len2)
{

    if (len1 == 0 && len2 == 0)
        return 0;
    else if (len1 == 0 && len2 > 0)
        return -1;
    else if (len1 > 0 && len2 == 0)
        return 1;

    if (*c1 == *c2)
        return compare(++c1, --len1, ++c2, --len2);
    else
    {
        if (*c1 < *c2)
            return -1;
        else
            return 1;
    }
}

int main()
{
    char str1[50],str2[50];
    int l1,l2, result;

    printf("Enter string 1: - ");
    scanf("%s",str1);

    printf("\nEnter string 2: - ");
    scanf("%s",str2);

    l1 = strlen(str1);
    l2 = strlen(str2);

    result = compare(str1, l1, str2, l2);
    printf("\nResult is %d", result);

    return 0;
}
