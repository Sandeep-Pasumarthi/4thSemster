#include "PP_A1_P2_Functions.h"
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int main()
{
    //Functionality 1

    printf("##############################\n");
    printf("Functionality 1\n");
    printf("Coparision of two strings\n");
    printf("##############################\n");

    char str1[50],str2[50];
    int l1,l2, result;

    printf("\nEnter string 1: - ");
    scanf("%s",str1);

    printf("\nEnter string 2: - ");
    scanf("%s",str2);

    l1 = strlen(str1);
    l2 = strlen(str2);

    result = compare(str1, l1, str2, l2);
    printf("\nResult is %d\n", result);
    printf("\n");


    //Functionality 2

    printf("##############################\n");
    printf("Functionality 2\n");
    printf("Maximum of given list\n");
    printf("##############################\n");
    printf("\n");

    int len, max;

    printf("Enter length of the list: - ");
    scanf("%d", &len);
    printf("\n");

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
        printf("\n");
    }


    //Functionality 3

    printf("##############################\n");
    printf("Functionality 3\n");
    printf("Finding element in a given list\n");
    printf("##############################\n");
    printf("\n");

    struct node* head = NULL;
    int x = 1, y = 21;

    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);

    search(head, x)? printf("Yes\n") : printf("No\n");
    search(head, y)? printf("Yes\n") : printf("No\n");
    printf("\n");

    //Functionality 4

    printf("##############################\n");
    printf("Functionality 4\n");
    printf("Printing list in reverse order\n");
    printf("##############################\n");
    printf("\n");

    int n;

    printf("Enter length of list: ");
    scanf("%d", &n);
    printf("\n");

    int list1[n];

    for(int i = 0; i < n; i++)
    {
        printf("Enter the element number %d: - ", i+1);
        scanf("%d", &list1[i]);
    }

    printf("\nElements of array in reverse order: - ");
    print(list1, n);
    printf("\n");


    //Functionality 5

    printf("##############################\n");
    printf("Functionality 5\n");
    printf("Given string is palindrom or not\n");
    printf("##############################\n");
    printf("\n");

    char s[5] = {'t', 'h', 'o', 'r'};
    char x1[5] = {'h', 'a', 'h', 'a', 'h'};

    palindrome(s, 0, 4)? printf("Yes, it's a palindrome\n") : printf("No, it's not a palindrome\n");
    palindrome(x1, 0, 5)? printf("Yes, it's a palindrome\n") : printf("No, it's not a palindrome\n");
    printf("\n");

    //Functionality 6

    printf("##############################\n");
    printf("Functionality 6\n");
    printf("Replacing given charecter with a new charecter in a string\n");
    printf("##############################\n");
    printf("\n");
    char lock, key;

    printf("Enter length of the string: - ");
    scanf("%d", &len);

    char arr[len];

    printf("Enter the string: - ");
    scanf("%s", arr);
    printf("\n");

    while ((getchar()) != '\n');
    printf("Enter the character to replaced by: - ");
    scanf("%c", &lock);
    while ((getchar()) != '\n');
    printf("Enter the character to replaced with: - ");
    scanf("%c", &key);

    replace(arr, lock, key, len);
    
    printf("\n");
    printf("Result is %s\n", arr);
    printf("\n");

    //Functionality 7

    printf("##############################\n");
    printf("Functionality 7\n");
    printf("Sorting given list in ascending order\n");
    printf("##############################\n");
    printf("\n");

    printf("Enter length of the array: - ");
    scanf("%d",&n);
    printf("\n");

    int arr1[n];

    for(int i = 0; i < n; i++)
    {
        printf("Enter element number %d in array: - ", i+1);
	scanf("%d", &arr1[i]);
    }

    sort(arr1, n);

    printf("\nAfter sorting array in ascending order: - ");
    for(int i = 0; i < n; i++)
    {
	printf("%d ", arr1[i]);
    }
    printf("\n");

    return 0;
}