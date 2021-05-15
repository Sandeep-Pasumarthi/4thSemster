#include <iostream>
using namespace std;

template <class T>
void sort(T a[], int n)
{
    for (int i = 0; i < n - 1; i++)
        for (int j = n - 1; i < j; j--)
            if (a[j] < a[j - 1])
                swap(a[j], a[j - 1]);
}

struct node
{
    int data;
} node;

int main()
{
    float a[5] = {10.00, 50.20, 30.05, 40.02, 20.03};
    int n = 5;

    int b[5] = {10, 60, 100, 40, 20};

    struct node c[2];
    c[0].data = 1;
    c[1].data = 2;

    sort<float>(a, 5);
    sort<int>(b, 5);
    /* sort<struct node>(c, 2); this line will give an error */

    cout << " Sorted float array : ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;

    cout << " Sorted int array : ";
    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << endl;
    return 0;

    // The below line gives an error

    /* cout << " Sorted struct array : ";
    for (int i = 0; i < 2; i++)
        cout << c[i].data << " ";
    cout << endl;
    return 0; */
}