#include "PP_A2_Part2_P8_Header.hpp"

int main()
{
    int n, start;
    cout << "Enter number of players to play: - ";
    cin >> n;

    cout << "Pick a number to Start Game: - ";
    cin >> start;

    player *head = new player;
    head->right = head;
    head->left = head;

    cout << "Enter name of the player " << 1 << ": - ";
    cin >> head->name;

    for (int i = 1; i < n; i++)
    {
        string x;
        cout << "Enter name of the player " << i + 1 << ": - ";
        cin >> x;
        insertPlayers(head, x);
    }

    // Part A
    int post = arbitaryFunctionValue();
    cout << "\nSkip Value: - " << post % n << endl;
    cout << "\n";

    printClock(&head);
    printAntiClock(&head);
    /*startGame1(&head, n, start) will use one function that generates a random value*/
    /*startGame2(&head, n, start) will use different functions to generate a random value*/
    startGame2(&head, n, start);
}