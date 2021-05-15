#include <bits/stdc++.h>
#include <chrono>

using namespace std;
using namespace std::chrono;

int MatrixChainOrder(int *, int);

int main()
{
    int arr[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    auto start = high_resolution_clock::now();
    cout << "Minimum number of multiplications: - " << MatrixChainOrder(arr, size) << endl;
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Execution Time is: - " << duration.count() << endl;

    return 0;
}

int MatrixChainOrder(int *p, int n)
{
    int m[n][n];
    int i, j, k, L, q;

    for (i = 1; i < n; i++)
        m[i][i] = 0;

    for (L = 2; L < n; L++)
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n - 1];
}