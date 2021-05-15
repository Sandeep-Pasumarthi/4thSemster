#include "DataSetGenerator.hpp"
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

void bucketSort(float *array, int n)
{
    vector<float> bins[n];

    for (int i = 0; i < n; i++)
    {
        int index = n * array[i];
        bins[index].push_back(array[i]);
    }

    for (int i = 0; i < n; i++)
    {
        sort(bins[i].begin(), bins[i].end());
    }

    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        while (!bins[i].empty())
        {
            array[temp++] = *(bins[i].begin());
            bins[i].erase(bins[i].begin());
        }
    }
}

void normalize(float *arr, int n)
{
    float min = arr[0], max = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = (arr[i] - min) / (max - min + 0.0001);
    }
}

int main()
{
    int pow2 = 14, time;

    long n = pow(2, pow2);

    float *arr_nrml = new float[n];

    normalDistributionGenerator(arr_nrml, pow2, 100000, 10, 17);
    normalize(arr_nrml, n);

    auto start = high_resolution_clock::now();
    bucketSort(arr_nrml, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    time = duration.count();
    cout << "Execution Time is: - " << time << endl;

    return 0;
}
