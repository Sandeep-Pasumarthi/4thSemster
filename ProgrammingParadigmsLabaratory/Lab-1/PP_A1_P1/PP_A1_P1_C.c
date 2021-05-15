#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

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

bool search(struct node* head, int x)
{
    if (head == NULL)
        return false;

    if (head->key == x)
        return true;

    return search(head->next, x);
}

int main()
{
    struct node* head = NULL;
    int x = 1, y = 21;

    push(&head, 10);
    push(&head, 30);
    push(&head, 11);
    push(&head, 21);
    push(&head, 14);

    search(head, x)? printf("Yes\n") : printf("No\n");
    search(head, y)? printf("Yes") : printf("No");

    return 0;
}
