#include <iostream>
using namespace std;
const int MAX = 1000;
int arr_count = 0;
const int MAXARRCOUNT = 2;
int size[MAXARRCOUNT];
namespace MAXSIZE
{
    int maxsize = MAX;
};

typedef struct RSArray
{
    int data;
    int isAdded = 0;
} arr;

inline int getCount(arr *);
inline int getMaxSize(arr *, int, int);
bool initializeRSArray(arr *, int);
bool inflate(arr *, int, int);
bool addElement(arr *, int, int, int);
inline int fetchElement(arr *, int);
bool resetElements(arr *, int, int);
inline bool delRSArray(arr *, int);
inline void printElements(arr *);
inline void maxSizeOfArray();

int main()
{
    int n = 1;
    arr *test;

    maxSizeOfArray();
    initializeRSArray(test, n);
    addElement(test, 2, n, 0);
    addElement(test, 6, n, 0);
    addElement(test, 5, n, 0);
    addElement(test, 4, n, 0);
    resetElements(test, 2, 1);
    cout << getCount(test) << endl;
    cout << getMaxSize(test, n, 0);
    fetchElement(test, 0);
    printElements(test);
    delRSArray(test, 0);

    return 0;
}

int getCount(arr *temp)
{
    int i = 0, count = 0;
    while (temp[i].isAdded == 1)
    {
        count++;
        i++;
    }

    return count;
}

int getMaxSize(arr *temp, int n, int arr_index)
{
    return size[arr_index];
}

bool initializeRSArray(arr *temp, int n)
{
    temp = new arr[n];
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

bool inflate(arr *temp, int n, int arr_index)
{
    if (size[arr_index] + 100 <= MAX)
    {
        arr *temp2 = new arr[size[arr_index] + 100];
        size[arr_index] = size[arr_index] + 100;
        int count = getCount(temp);

        for (int i = 0; i < count; i++)
        {
            temp2[i].data = temp[i].data;
            temp2[i].isAdded = temp[i].isAdded;
        }
        temp = new arr[size[arr_index] + 100];
        temp = temp2;

        return true;
    }
    else
    {
        cout << "Max Limit Reached! Sorry!!!";

        return false;
    }
}

bool addElement(arr *temp, int val, int n, int arr_index)
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

int fetchElement(arr *temp, int pos)
{
    cout << '\n';
    cout << "Element at Position " << pos << " is: - " << temp[pos].data << endl;

    return temp[pos].data;
}

bool resetElements(arr *temp, int num, int pos)
{
    for (int i = pos; i < getCount(temp) && i < pos + num; i++)
    {
        temp[i].data = 0;
    }

    return true;
}

bool delRSArray(arr *temp, int arr_index)
{
    delete[] temp;
    size[arr_index] = 0;

    return true;
}

void printElements(arr *temp)
{
    int coun = getCount(temp);

    for (int i = 0; i < coun; i++)
    {
        cout << temp[i].data << endl;
    }
}

void maxSizeOfArray()
{
    cout << "Maximum Size a Array can have is: - " << MAXSIZE::maxsize << endl;
}