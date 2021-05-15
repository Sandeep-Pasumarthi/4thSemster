#include <iostream>

using namespace std;

class Game
{
private:
    typedef struct node
    {
        string name;
        struct node *next;
        int isDeleted = 0;
    } player;

    player *head;
    int numPlayers;
    const int skipMembers;
    int startAt;

public:
    Game(int, int, int);
    ~Game();

    bool addPlayers();
    void startGame();
    void printPlayers();
};

int main()
{
    Game one(6, 2, 5);
    one.addPlayers();
    one.printPlayers();
    one.startGame();
}

Game ::Game(int num, int skip, int start) : skipMembers(skip)
{
    numPlayers = num;
    startAt = start;

    head = new player;
    head->next = head;

    cout << "Enter name of the player 1: - ";
    cin >> head->name;
}

Game ::~Game()
{
    player *x, *y;
    x = head;
    for (int i = 0; i < numPlayers; i++)
    {
        y = x;
        delete y;
        y = NULL;
        x = x->next;
    }

    delete x;
    delete y;
    x = y = NULL;

    cout << "Destructed Successfully" << endl;
}

bool Game ::addPlayers()
{
    for (int i = 1; i < numPlayers; i++)
    {
        string x;
        cout << "Enter name of the player " << i + 1 << ": - ";
        cin >> x;

        player *temp1 = new player;
        temp1->name = x;
        temp1->next = temp1;

        player *start;
        start = head;

        while (start->next != head)
        {
            start = start->next;
        }

        start->next = temp1;
        temp1->next = head;
    }

    return true;
}

void Game::startGame()
{
    player *temp;
    temp = head;

    int no = numPlayers;
    int num = numPlayers;

    startAt = startAt % numPlayers;

    while (startAt > 0)
    {
        temp = temp->next;
        startAt--;
    }

    while (num != 1)
    {
        cout << "starting with palyer name: - " << temp->name << endl;

        int post = skipMembers;
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
    node = head;

    for (int i = 0; i < no; i++)
    {
        if (node->isDeleted == 0)
        {
            cout << "Winner is: - " << node->name << endl;
            return;
        }
        else
        {
            node = node->next;
        }
    }
}

void Game::printPlayers()
{
    player *x3;
    x3 = head;

    cout << "Participants Playing are: - " << endl;
    do
    {
        cout << x3->name << endl;
        x3 = x3->next;
    } while (x3 != head);
}