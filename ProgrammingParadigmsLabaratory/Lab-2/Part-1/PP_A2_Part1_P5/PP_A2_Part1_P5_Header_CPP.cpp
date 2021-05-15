#include <iostream>
using namespace std;

typedef struct node
{
    string name;
    struct node *next;
    int isDeleted = 0;
} player;

bool insertPlayers(player *head, string data)
{
    player *temp1 = new player;
    temp1->name = data;
    temp1->next = temp1;

    player *start;
    start = head;

    while (start->next != head)
    {
        start = start->next;
    }

    start->next = temp1;
    temp1->next = head;

    return true;
}

void startGame(player **head, int num, int skip, int start)
{
    player *temp;
    temp = *head;

    int no = num;

    start = start / num;

    while (start > 0)
    {
        temp = temp->next;
        start--;
    }

    while (num != 1)
    {
        cout << "starting with palyer name: - " << temp->name << endl;

        int post = skip;
        while (post > 0)
        {
            if (temp->next->isDeleted == 0)
            {
                temp = temp->next;
            }
            else
            {
                temp = temp->next;
                while (temp->isDeleted == 1)
                {
                    temp = temp->next;
                }
            }
            post--;
        }
        temp->isDeleted = 1;
        cout << "Player Evicted is: - " << temp->name << endl;
        while (temp->isDeleted == 1)
        {
            temp = temp->next;
        }
        num--;
    }

    player *node;
    node = *head;

    for (int i = 0; i < no; i++)
    {
        if (node->isDeleted == 0)
        {
            cout << "Winner is: - " << node->name << endl;
            break;
        }
        else
        {
            node = node->next;
        }
    }
}

void print(player **head)
{
    player *x3;
    x3 = *head;

    cout << "Participants Playing are: - " << endl;
    do
    {
        cout << x3->name << endl;
        x3 = x3->next;
    } while (x3 != *head);
}