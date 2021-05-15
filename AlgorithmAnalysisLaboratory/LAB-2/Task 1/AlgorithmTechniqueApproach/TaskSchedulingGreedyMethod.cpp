#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Job
{
    char taskNum;
    int deadLine;
    int penalty;
};

bool comparison(Job, Job);
void taskScheduling(Job[], int);

int main()
{
    Job arr[] = {{'1', 4, 70}, {'2', 2, 60}, {'3', 4, 50}, {'4', 3, 40}, {'5', 1, 30}, {'6', 4, 20}, {'7', 6, 10}};
    int n = sizeof(arr) / sizeof(arr[0]);

    auto start = high_resolution_clock::now();
    cout << "Following is minimum penalty sequence of jobs \n";
    taskScheduling(arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Execution Time is: - " << duration.count() << endl;

    return 0;
}

bool comparison(Job a, Job b)
{
    return (a.penalty > b.penalty);
}

void taskScheduling(Job arr[], int n)
{
    sort(arr, arr + n, comparison);

    int result[n];
    bool slot[n];

    for (int i = 0; i < n; i++)
    {
        slot[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = min(n, arr[i].deadLine) - 1; j >= 0; j--)
        {
            if (slot[j] == false)
            {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (slot[i])
        {
            cout << arr[result[i]].taskNum << " ";
        }
    }
    cout << "\n";
}