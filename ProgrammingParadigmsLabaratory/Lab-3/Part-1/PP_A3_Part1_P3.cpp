#include <iostream>

using namespace std;
template <class C>
class RSArray
{
private:
    C *data;
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

    bool addElement(C);
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

template <typename C>
int RSArray<C>::arr_count = 0;

int main()
{
    RSArray<float> one(12);

    for (int i = 0; i < 11; i++)
    {
        one.addElement(i + 0.1);
    }
    one.printElements();
    one.getSize();
    one.getMaxSize();
    one.fetchElement(1);
    one.inflate();
    one.getSize();
    one.getMaxSize();
}

template <typename C>
RSArray<C>::RSArray() : max_size(13)
{
    data = new C[10];
    size = 10;
    arr_count++;
}

template <typename C>
RSArray<C>::RSArray(int cap) : max_size(cap * 1.3)
{
    data = new C[cap];
    size = cap;
    arr_count++;
}

template <typename C>
RSArray<C>::RSArray(const RSArray<C> &src) : max_size(src.max_size)
{
    this->count = src.count;
    this->size = src.size;
    this->data = new C[this->count];

    for (int i = 0; i < this->count; i++)
    {
        this->data[i] = src.data[i];
    }

    arr_count++;
    cout << "Successfully Copied Using Copy Constructor" << endl;
}

template <typename C>
RSArray<C> &RSArray<C>::operator=(const RSArray<C> &src)
{
    if (this == &src)
    {
        return *this;
    }
    delete[] data;

    data = new C[src.size];
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

template <typename C>
RSArray<C>::~RSArray()
{
    delete[] this->data;
    this->data = NULL;
    arr_count--;
    cout << "Destructed Successfully" << endl;
}

template <typename C>
bool RSArray<C>::addElement(C val)
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

template <typename C>
bool RSArray<C>::inflate()
{
    if (count >= 10 && (int)(size + (size * 0.1) < max_size))
    {
        int fir = size + (size * 0.1);
        C *temp = new C[fir];

        for (int i = 0; i < count; i++)
        {
            temp[i] = data[i];
        }

        data = new C[fir];
        data = temp;

        size = size + (size * 0.1);

        cout << "Successfully Inflated" << endl;

        return true;
    }
    else if (size < max_size)
    {
        C *temp = new C[max_size];

        for (int i = 0; i < count; i++)
        {
            temp[i] = data[i];
        }

        data = new C[max_size];
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

template <typename C>
void RSArray<C>::getCount()
{
    cout << "Number of Elements Present: - " << count << endl;
}

template <typename C>
void RSArray<C>::getSize()
{
    cout << "Size: - " << size << endl;
}

template <typename C>
void RSArray<C>::getMaxSize()
{
    cout << "Max Size: - " << max_size << endl;
}

template <typename C>
void RSArray<C>::fetchElement(int pos)
{
    cout << "Element at Position " << pos << " : - " << data[pos - 1] << endl;
}

template <typename C>
void RSArray<C>::resetElements(int start, int end)
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

template <typename C>
void RSArray<C>::printElements()
{
    for (int i = 0; i < count; i++)
    {
        cout << "Element at Position " << i + 1 << " : - " << data[i] << endl;
    }
}

template <typename C>
void RSArray<C>::elementCorrection(int pos, int val)
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

template <typename C>
void RSArray<C>::numberOfArraysCreated()
{
    cout << "Number of Arrays Created: - " << arr_count << endl;
}