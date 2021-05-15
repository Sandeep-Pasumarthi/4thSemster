#include<stdio.h>
#include<string.h>
#include<stdbool.h>

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

struct node
{
    int key;
    struct node* next;
};

void push(struct node** head, int new_key)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->key = new_key;
    new_node->next = (*head);
    (*head) = new_node;
}

int search(struct node* head, int x)
{
    if (head == NULL)
        return 0;

    if (head->key == x)
        return 1;

    return search(head->next, x);
}

void print(int temp[],int len)
{
    if (len > 0)
    {
        len--;
        printf("%d\n", temp[len]);
        print(temp, len);
    }
}

int palindrome(char s[], int start, int len)
{
    if(len == 0 || len == 1)
    {
        return 1;
    }
    else if (s[start] != s[len-1])
    {
        return 0;
    }
    else if (len < start || start == len)
    {
        return 1;
    }

    return palindrome(s, ++start, --len);
}

void replace(char arr[], char lock, char key, int n)
{
    if ((n-1) < 0)
    {
        return;
    }
    if (arr[n-1] == lock)
    {
        arr[n-1] = key;
    }

    replace(arr, lock, key, n-1);
}

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
