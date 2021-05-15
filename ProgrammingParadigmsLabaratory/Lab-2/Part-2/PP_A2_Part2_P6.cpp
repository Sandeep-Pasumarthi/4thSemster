#include <iostream>
using namespace std;
const int MAX = 1000;
int arr_count = 0;
const int MAXARRCOUNT = 2;
int size[MAXARRCOUNT];

template <typename T>

struct RSArray
{
    T data;
    int isAdded = 0;
};

template <typename R>
int getCount(RSArray<R> *temp)
{
    int i = 0, count = 0;
    while (temp[i].isAdded == 1)
    {
        count++;
        i++;
    }

    return count;
}

template <typename R>
int getMaxSize(RSArray<R> *temp, int n, int arr_index)
{
    return size[arr_index];
}

template <typename R>
bool initializeRSArray(RSArray<R> *temp, int n)
{
    temp = new RSArray<R>[n];
    if (temp != NULL && MAX >= n && arr_count <= MAXARRCOUNT)
    {
        size[arr_count] = n;
        arr_count++;
        return true;
    }
    else
    {
        cout << "Sorry Couldn't Allocate Memory" << endl;

        return false;
    }
}

template <typename R>
bool inflate(RSArray<R> *temp, int n, int arr_index)
{
    if (size[arr_index] + 100 <= MAX)
    {
        RSArray<R> *temp2 = new RSArray<R>[size[arr_index] + 100];
        size[arr_index] = size[arr_index] + 100;
        int count = getCount(temp);

        for (int i = 0; i < count; i++)
        {
            temp2[i].data = temp[i].data;
            temp2[i].isAdded = temp[i].isAdded;
        }
        temp = new RSArray<R>[size[arr_index] + 100];
        temp = temp2;

        return true;
    }
    else
    {
        cout << "Max Limit Reached! Sorry!!!";

        return false;
    }
}

template <typename R>
bool addElement(RSArray<R> *temp, R val, int n, int arr_index)
{
    int coun = getCount(temp);
    if (coun < size[arr_index])
    {
        temp[coun].data = val;
        temp[coun].isAdded = 1;

        cout << "Successfully Added" << endl;

        return true;
    }
    else
    {
        cout << "Memory Exhausted!!! Time to Inflate" << endl;
        char i;
        cout << "Enter 'y' for YES and 'n' for NO: - ";
        cin >> i;
        if (i == 'y')
        {
            inflate(temp, n, arr_index);
            cout << "Successfull Inflation, Now You can add some more Elements" << endl;

            return addElement(temp, val, n, arr_index);
        }
        else
        {
            cout << "Thank You." << endl;

            return false;
        }
    }
}

template <typename R>
int fetchElement(RSArray<R> *temp, int pos)
{
    cout << '\n';
    cout << "Element at Position " << pos << " is: - " << temp[pos].data << endl;

    return temp[pos].data;
}

template <typename R>
bool resetElements(RSArray<R> *temp, int num, int pos)
{
    for (int i = pos; i < getCount(temp) && i < pos + num; i++)
    {
        temp[i].data = 0;
    }

    return true;
}

template <typename R>
bool delRSArray(RSArray<R> *temp, int arr_index)
{
    delete[] temp;
    temp = NULL;
    size[arr_index] = 0;

    return true;
}

template <typename R>
void printElements(RSArray<R> *temp)
{
    int coun = getCount(temp);

    for (int i = 0; i < coun; i++)
    {
        cout << temp[i].data << endl;
    }
}

int main()
{
    int n = 1;
    RSArray<char> *test;

    initializeRSArray(test, n);
    addElement(test, 'a', n, 0);
    addElement(test, 'b', n, 0);
    addElement(test, 'c', n, 0);
    addElement(test, 'd', n, 0);
    resetElements(test, 2, 1);
    cout << getCount(test) << endl;
    cout << getMaxSize(test, n, 0);
    fetchElement(test, 0);
    printElements(test);
    delRSArray(test, 0);

    return 0;
}