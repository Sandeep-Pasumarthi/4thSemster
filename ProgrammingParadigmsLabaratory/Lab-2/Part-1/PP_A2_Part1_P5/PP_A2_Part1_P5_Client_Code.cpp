#include "PP_A2_Part1_P5_Header.hpp"

int main()
{
    int n, skip, start;
    cout << "Enter number of players to play: - ";
    cin >> n;

    cout << "Pick a number to remove one player: - ";
    cin >> skip;

    cout << "Pick a number to Start Game: - ";
    cin >> start;

    player *head = new player;
    head->next = head;

    cout << "Enter name of the player " << 1 << ": - ";
    cin >> head->name;

    for (int i = 1; i < n; i++)
    {
        string x;
        cout << "Enter name of the player " << i + 1 << ": - ";
        cin >> x;
        insertPlayers(head, x);
    }

    print(&head);
    startGame(&head, n, skip, start);
    return 0;
}