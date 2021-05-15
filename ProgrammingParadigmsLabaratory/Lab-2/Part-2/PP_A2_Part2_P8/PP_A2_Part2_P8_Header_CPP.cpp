#include <iostream>
#include <time.h>
using namespace std;

typedef struct node
{
    string name;
    struct node *right;
    struct node *left;
    int isDeleted = 0;
} player;

bool insertPlayers(player *head, string data)
{
    player *temp1 = new player;
    temp1->name = data;
    temp1->right = temp1;
    temp1->left = temp1;

    player *start;
    start = head;

    while (start->right != head)
    {
        start = start->right;
    }

    start->right = temp1;
    temp1->right = head;
    temp1->left = start;
    head->left = temp1;

    return true;
}

int arbitaryFunctionValue(int x)
{
    srand(time(0));
    int random = rand() % (3);

    if (random == 0)
    {
        int x2 = 2 * x * x;
        int xm = -5 * x;
        int xn = 20;

        return x2 + xm + xn;
    }
    else if (random == 1)
    {
        int x3 = x * x * x;
        int xm1 = -2 * x * x;
        int xm2 = 4 * x;
        int xn = -1;

        return x3 + xm1 + xm2 + xn;
    }
    else if (random == 2)
    {
        int x2 = x * x;
        int xm = -3 * x;
        int xn = 6;

        return x2 + xm + xn;
    }

    return x;
}

int generateRandomValue()
{
    srand(time(0));

    return arbitaryFunctionValue(rand() % 10 + 1);
}

int arbitaryFunctionValue()
{
    int x = rand() % 10 + 1;

    int x2 = x * x;
    int xm = -3 * x;
    int xn = 6;

    return x2 + xm + xn;
}

player *evictPlayerRight(player **head, int skip, player *temp)
{
    cout << "starting with palyer name: - " << temp->name << endl;

    while (skip > 0)
    {
        if (temp->right->isDeleted == 0)
        {
            temp = temp->right;
        }
        else
        {
            temp = temp->right;
            while (temp->isDeleted == 1)
            {
                temp = temp->right;
            }
        }
        skip--;
    }
    temp->isDeleted = 1;
    cout << "Player Evicted is: - " << temp->name << endl;
    while (temp->isDeleted == 1)
    {
        temp = temp->right;
    }

    return temp;
}

player *evictPlayerLeft(player **head, int skip, player *temp)
{
    cout << "starting with palyer name: - " << temp->name << endl;

    while (skip < 0)
    {
        if (temp->left->isDeleted == 0)
        {
            temp = temp->left;
        }
        else
        {
            temp = temp->left;
            while (temp->isDeleted == 1)
            {
                temp = temp->left;
            }
        }
        skip++;
    }
    temp->isDeleted = 1;
    cout << "Player Evicted is: - " << temp->name << endl;
    while (temp->isDeleted == 1)
    {
        temp = temp->left;
    }

    return temp;
}

void startGame1(player **head, int num, int start)
{
    int no = num;
    player *temp1;
    temp1 = *head;

    for (int i = 0; i < start; i++)
    {
        temp1 = temp1->right;
    }

    while (num != 1)
    {
        int post = arbitaryFunctionValue();
        post = post % num;
        cout << "Skip Value is: - " << post << endl;

        if (post >= 0)
        {
            temp1 = evictPlayerRight(head, post, temp1);
        }
        else
        {
            temp1 = evictPlayerLeft(head, post, temp1);
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
            node = node->right;
        }
    }
}

void startGame2(player **head, int num, int start)
{
    int no = num;
    player *temp1;
    temp1 = *head;

    for (int i = 0; i < start; i++)
    {
        temp1 = temp1->right;
    }

    while (num != 1)
    {
        int post = generateRandomValue();
        post = post % num;
        cout << "Skip Value is: - " << post << endl;

        if (post >= 0)
        {
            temp1 = evictPlayerRight(head, post, temp1);
        }
        else
        {
            temp1 = evictPlayerLeft(head, post, temp1);
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
            node = node->right;
        }
    }
}

void printClock(player **head)
{
    player *x3;
    x3 = *head;

    cout << "Participants Playing are: - " << endl;
    do
    {
        cout << x3->name << endl;
        x3 = x3->right;
    } while (x3 != *head);
}

void printAntiClock(player **head)
{
    player *x4;
    x4 = *head;

    cout << "Participants Playing are: - " << endl;
    do
    {
        cout << x4->name << endl;
        x4 = x4->left;
    } while (x4 != *head);
}