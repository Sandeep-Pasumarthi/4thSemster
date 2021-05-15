#include <iostream>

using namespace std;

class RSArray
{
private:
    int *data;
    int size;
    int max_size;
    int count = 0;
    static int arr_count;

public:
    RSArray();
    RSArray(int);
    RSArray(const RSArray &);
    RSArray &operator=(const RSArray &);
    ~RSArray();

    bool addElement(int);
    bool inflate();
    void getCount();
    void getSize();
    void getMaxSize();
    void fetchElement(int);
    void resetElements(int, int);
    void printElements();
    void elementCorrection(int, int);
    static void numberOfArraysCreated();
};

int RSArray ::arr_count = 0;

int main()
{
    RSArray one(12);

    for (int i = 0; i < 11; i++)
    {
        one.addElement(i);
    }
    one.getMaxSize();
    one.printElements();
    RSArray two;
    two = one;
    two.fetchElement(5);
    two.getMaxSize();
    two.printElements();
}

RSArray ::RSArray() : max_size(13)
{
    data = new int[10];
    size = 10;
    arr_count++;
}

RSArray ::RSArray(int cap) : max_size(cap * 1.3)
{
    data = new int[cap];
    size = cap;
    arr_count++;
}

RSArray ::RSArray(const RSArray &src) : max_size(src.max_size)
{
    this->count = src.count;
    this->size = src.size;
    this->data = new int[this->count];

    for (int i = 0; i < this->count; i++)
    {
        this->data[i] = src.data[i];
    }

    arr_count++;
    cout << "Successfully Copied Using Copy Constructor" << endl;
}

RSArray &RSArray ::operator=(const RSArray &src)
{
    if (this == &src)
    {
        return *this;
    }
    delete[] data;

    data = new int[src.size];
    size = src.size;
    count = src.count;
    max_size = src.max_size;

    for (int i = 0; i < src.count; i++)
    {
        data[i] = src.data[i];
    }

    cout << "Successfully Copied Using Assignment Operator" << endl;

    return *this;
}

RSArray ::~RSArray()
{
    delete[] this->data;
    this->data = NULL;
    arr_count--;
    cout << "Destructed Successfully" << endl;
}

bool RSArray ::addElement(int val)
{
    if (count < size)
    {
        data[count] = val;
        count++;

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
            bool id = inflate();

            if (id == true)
            {
                return addElement(val);
            }
            else
            {
                cout << "Element not Added" << endl;

                return false;
            }
        }
        else
        {
            cout << "Thank You." << endl;

            return false;
        }
    }
}

bool RSArray ::inflate()
{
    if (count >= 10 && (int)(size + (size * 0.1) < max_size))
    {
        int fir = size + (size * 0.1);
        int *temp = new int[fir];

        for (int i = 0; i < count; i++)
        {
            temp[i] = data[i];
        }

        data = new int[fir];
        data = temp;

        size = size + (size * 0.1);

        cout << "Successfully Inflated" << endl;

        return true;
    }
    else if (size < max_size)
    {
        int *temp = new int[max_size];

        for (int i = 0; i < count; i++)
        {
            temp[i] = data[i];
        }

        data = new int[max_size];
        data = temp;

        size = max_size;

        cout << "Successfully Inflated" << endl;

        return true;
    }
    else
    {
        cout << "Resources Full!!!" << endl;

        return false;
    }
}

void RSArray ::getCount()
{
    cout << "Number of Elements Present: - " << count << endl;
}

void RSArray ::getSize()
{
    cout << "Size: - " << size << endl;
}

void RSArray ::getMaxSize()
{
    cout << "Max Size: - " << max_size << endl;
}

void RSArray ::fetchElement(int pos)
{
    cout << "Element at Position " << pos << " : - " << data[pos - 1] << endl;
}

void RSArray ::resetElements(int start, int end)
{
    if (start <= end && end <= count)
    {
        for (int i = start - 1; i < end; i++)
        {
            data[i] = 0;
        }

        cout << "Elements Resetted Successfully" << endl;
    }
    else
    {
        cout << "Check the given input numbers!!!" << endl;
    }
}

void RSArray ::printElements()
{
    for (int i = 0; i < count; i++)
    {
        cout << "Element at Position " << i + 1 << " : - " << data[i] << endl;
    }
}

void RSArray ::elementCorrection(int pos, int val)
{
    if (pos <= count)
    {
        data[pos - 1] = val;
        cout << "Successfully Corrected" << endl;
    }
    else
    {
        cout << "Given position is wrong. Check again!!!";
    }
}

void RSArray ::numberOfArraysCreated()
{
    cout << "Number of Arrays Created: - " << arr_count << endl;
}