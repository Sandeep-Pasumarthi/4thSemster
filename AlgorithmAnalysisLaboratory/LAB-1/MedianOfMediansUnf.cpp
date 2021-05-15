#include "DataSetGenerator.hpp"
#include <algorithm>
#include <climits>
#include <chrono>

using namespace std::chrono;

int swaps = 0, medians = 0, partitions = 0;

void insertionSort(float arr[], int n);
float findMedian(float arr[], int n);
float kthSmallest(float arr[], int s, int l, int r, int k);
void swap(float *a, float *b);
int partition(float arr[], int l, int r, float x);

int main()
{
    int pow2 = 15, s = 7, ntime = 10;
    long long time = 0, avg_swaps = 0, avg_medians = 0, avg_partitions = 0;

    long n = pow(2, pow2);

    float *arr_unf = new float[n];

    for (int i = 0; i < ntime; i++)
    {
        uniformDistributionGenerator(arr_unf, pow2, 1000, 1000000, 17);
        auto start = high_resolution_clock::now();
        kthSmallest(arr_unf, s, 0, n - 1, n / 2);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);

        time = time + duration.count();
        avg_swaps = avg_swaps + swaps;
        avg_medians = avg_medians + medians;
        avg_partitions = avg_partitions + partitions;
        swaps = 0;
        medians = 0;
        partitions = 0;
    }

    cout << "Execution Time is: - " << time / ntime << endl;
    cout << "Swaps: - " << avg_swaps / ntime << endl;
    cout << "Medians: - " << avg_medians / ntime << endl;
    cout << "Partitions: - " << avg_partitions / ntime << endl;

    return 0;
}

void insertionSort(float arr[], int n)
{
    int i, j;
    float key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

float findMedian(float arr[], int n)
{
    insertionSort(arr, n);
    medians++;
    return arr[n / 2];
}

float kthSmallest(float arr[], int s, int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int n = r - l + 1;
        int i;
        float median[(n + (s - 1)) / s];
        for (i = 0; i < n / s; i++)
        {
            median[i] = findMedian(arr + l + i * s, s);
        }
        if (i * s < n)
        {
            median[i] = findMedian(arr + l + i * s, n % s);
            i++;
        }
        float medOfMed = (i == 1) ? median[i - 1] : kthSmallest(median, s, 0, i - 1, i / 2);

        int pos = partition(arr, l, r, medOfMed);

        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1)
            return kthSmallest(arr, s, l, pos - 1, k);

        return kthSmallest(arr, s, pos + 1, r, k - pos + l - 1);
    }

    return 0.0;
}

void swap(float *a, float *b)
{
    float temp = *a;
    *a = *b;
    *b = temp;

    swaps++;
}

int partition(float arr[], int l, int r, float x)
{
    partitions++;
    int i;

    for (i = l; i < r; i++)
    {
        if (arr[i] == x)
        {
            break;
        }
    }
    swap(&arr[i], &arr[r]);

    i = l;
    for (int j = l; j <= r - 1; j++)
    {
        if (arr[j] <= x)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}
