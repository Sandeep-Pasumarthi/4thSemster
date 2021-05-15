#include "DataSetGenerator.hpp"
#include <chrono>

using namespace std;
using namespace std::chrono;

int comparisions = 0;

void merge_arr(float arr[], float temp[], long left, long mid, long right)
{
    long left_end, len, index;
    left_end = mid - 1;
    len = (right - left) + 1;
    index = left;

    // Adding Elements in Sorted Order
    while ((left <= left_end) && (mid <= right))
    {
        comparisions++;
        if (arr[left] <= arr[mid])
        {
            temp[index] = arr[left];
            left++;
            comparisions++;
        }
        else
        {
            temp[index] = arr[mid];
            mid++;
            comparisions++;
        }
        index++;
    }

    // Adding Remaining Left Elements in temp[] Array
    while (left <= left_end)
    {
        temp[index] = arr[left];
        left++;
        index++;
        comparisions++;
    }

    // Adding Remaining Right Elements in temp[] Array
    while (mid <= right)
    {
        temp[index] = arr[mid];
        mid++;
        index++;
        comparisions++;
    }

    // Finally Copying Sorted temp[] Array in the given Array
    for (long i = 0; i < len; i++)
    {
        arr[right] = temp[right];
        right--;
    }
}

void mergeSort(float arr[], float temp[], long left, long right)
{
    long mid;
    if (right > left)
    {
        comparisions++;
        mid = (right + left) / 2;

        // Recursively Calling Merge Sort
        mergeSort(arr, temp, left, mid);
        mergeSort(arr, temp, mid + 1, right);
        merge_arr(arr, temp, left, mid + 1, right);
    }
}

int main()
{
    int pow2 = 19, ntime = 1000;
    long long avg_comp = 0;
    int avg_time = 0;

    long n = pow(2, pow2);

    float *arr_nrml = new float[n];
    float *temp_nrml = new float[n];

    normalDistributionGenerator(arr_nrml, pow2, 1000000, 0.5, 17);

    for (int i = 0; i < ntime; i++)
    {
        auto start = high_resolution_clock::now();
        mergeSort(arr_nrml, temp_nrml, 0, n - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        avg_comp = avg_comp + comparisions;
        avg_time = avg_time + duration.count();
        comparisions = 0;
    }

    cout << "Execution Time is: - " << avg_time / ntime << endl;
    cout << "Number of comparisions: - " << avg_comp / ntime << endl;

    return 0;
}
