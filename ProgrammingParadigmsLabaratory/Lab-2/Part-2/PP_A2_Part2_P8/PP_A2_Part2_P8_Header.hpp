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

bool insertPlayers(player *head, string data);
int arbitaryFunctionValue(int x);
int generateRandomValue();
int arbitaryFunctionValue();
player *evictPlayerRight(player **head, int skip, player *temp);
player *evictPlayerLeft(player **head, int skip, player *temp);
void startGame1(player **head, int num, int start);
void startGame2(player **head, int num, int start);
void printClock(player **head);
void printAntiClock(player **head);