#include <iostream>
using namespace std;

template <typename T>
void swap(T *n1, T *n2)
{
    T temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}

int main()
{
    int i1 = 6, i2 = 3;
    float f1 = 7.2, f2 = 4.5;

    cout << "Initial Values of Integers: - " << i1 << ", " << i2 << endl;
    swap<int>(i1, i2);
    cout << "Final Values after Swapping: - " << i1 << ", " << i2 << endl;
    cout << "\n";

    cout << "Initial Values of Floats: - " << f1 << ", " << f2 << endl;
    swap<float>(f1, f2);
    cout << "Final Values after Swapping: - " << f1 << ", " << f2 << endl;
    cout << "\n";
}