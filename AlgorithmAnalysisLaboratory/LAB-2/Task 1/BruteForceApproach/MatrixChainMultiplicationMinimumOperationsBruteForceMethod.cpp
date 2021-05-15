#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

int MatrixChainOrder(int[], int, int);

int main()
{
    int arr[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    auto start = high_resolution_clock::now();
    cout << "Minimum number of multiplications: - " << MatrixChainOrder(arr, 1, n - 1) << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Execution Time is: - " << duration.count() << endl;
}

int MatrixChainOrder(int p[], int i, int j)
{
    if (i == j)
    {
        return 0;
    }

    int k;
    int min = INT_MAX;
    int count;

    for (k = i; k < j; k++)
    {
        count = MatrixChainOrder(p, i, k) + MatrixChainOrder(p, k + 1, j) + p[i - 1] * p[k] * p[j];

        if (count < min)
            min = count;
    }

    return min;
}