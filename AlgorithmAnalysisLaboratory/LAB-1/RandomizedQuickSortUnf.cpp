#include "DataSetGenerator.hpp"
#include <chrono>

using namespace std;
using namespace std::chrono;

int comparisions = 0, swaps = 0;

// exchange() Function Swaps the Two Elements in an Array at Positions left and right
void exchange(float arr[], int left, int right)
{
    swaps++;
    float temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;
}

// divide() Function Finds the Exact Position for the Partition at which the Array to be Divided to Apply Quick Sort on Sub Arrays
int divide(float arr[], int low, int high)
{
    int left = low, right = high;

    // Selecting Random Element from arr[] and Exchanging it with the arr[low] Value
    int random = (rand() % (high - low + 1)) + low;
    exchange(arr, left, random);
    float pivot_value = arr[low];

    while (left < right)
    {
        /* The First Loop Make Sure that Every Element in the Left of the Pivot is Smaller than the pivot_value and
        the Second Loop Make Sure that Every Element in the Right of the Pivot is Larger than the pivot_value */

        comparisions++;
        while (arr[left] <= pivot_value)
        {
            comparisions++;
            left++;
            if (left >= right)
            {
                comparisions++;
                break;
            }
        }

        while (arr[right] > pivot_value)
        {
            comparisions++;
            right--;
        }

        // If the left is less than the right then the elements will be swapped or exchanged
        if (left < right)
        {
            comparisions++;
            exchange(arr, left, right);
        }
    }

    arr[low] = arr[right];
    arr[right] = pivot_value;

    // right is the exact pivot position
    return right;
}

void randomizedQuickSort(float arr[], int low, int high)
{
    int pivot;
    if (low < high)
    {
        comparisions++;
        pivot = divide(arr, low, high);

        // Recursively Calling Quick Sort
        randomizedQuickSort(arr, low, pivot - 1);
        randomizedQuickSort(arr, pivot + 1, high);
    }
}

int main()
{
    int pow2 = 19, ntime = 100;
    long long avg_comp = 0, avg_swaps = 0;
    int avg_time = 0;

    long n = pow(2, pow2);

    float *arr_unf = new float[n];

    for (int i = 0; i < ntime; i++)
    {
        uniformDistributionGenerator(arr_unf, pow2, 1000, 1000000, 17);
        auto start = high_resolution_clock::now();
        randomizedQuickSort(arr_unf, 0, n - 1);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(stop - start);
        avg_comp = avg_comp + comparisions;
        avg_swaps = avg_swaps + swaps;
        avg_time = avg_time + duration.count();
        comparisions = 0;
        swaps = 0;
    }

    cout << "Execution Time is: - " << avg_time / ntime << endl;
    cout << "Number of comparisions: - " << avg_comp / ntime << endl;
    cout << "Number of swaps: - " << avg_swaps / ntime << endl;

    return 0;
}
