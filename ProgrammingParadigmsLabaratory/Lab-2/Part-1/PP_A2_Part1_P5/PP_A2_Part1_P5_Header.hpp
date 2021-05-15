#include <iostream>
using namespace std;

typedef struct node
{
    string name;
    struct node *next;
    int isDeleted = 0;
} player;

bool insertPlayers(player *head, string data);
void startGame(player **head, int num, int skip, int start);
void print(player **head);