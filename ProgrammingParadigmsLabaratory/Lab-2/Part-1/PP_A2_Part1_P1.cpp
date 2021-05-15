#include <iostream>
#include <fstream>
using namespace std;

typedef struct data
{
    string name;
    string age;
    string department;
    string year;
} data;

bool storeDataFromUserInput(data arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Details of Student " << i + 1 << ": - " << endl;
        cout << "\n";

        cout << "Enter Name of Student " << i + 1 << ": - ";
        cin >> arr[i].name;

        cout << "Enter Age of Student " << i + 1 << ": - ";
        cin >> arr[i].age;

        cout << "Enter Department of Student " << i + 1 << ": - ";
        cin >> arr[i].department;

        cout << "Enter Year of Study of Student " << i + 1 << ": - ";
        cin >> arr[i].year;
        cout << "\n\n";
    }

    return true;
}

bool printDataStored(data arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Details of Student " << i + 1 << ": - " << endl;
        cout << "\n";

        cout << "Name of Student " << i + 1 << ": - ";
        cout << arr[i].name;
        cout << "\n";

        cout << "Age of Student " << i + 1 << ": - ";
        cout << arr[i].age;
        cout << "\n";

        cout << "Department of Student " << i + 1 << ": - ";
        cout << arr[i].department;
        cout << "\n";

        cout << "Year of Study of Student " << i + 1 << ": - ";
        cout << arr[i].year;
        cout << "\n\n";
    }

    return true;
}

bool writeDataFromArrayToFile(data arr[], int n)
{
    string file;
    cout << "Enter Name of the File with Extension: - ";
    cin >> file;
    cout << "\n";

    ofstream file_;
    file_.open(file);
    if (file_.is_open())
    {
        for (int i = 0; i < n; i++)
        {
            file_ << arr[i].name << " ";
            file_ << arr[i].age << " ";
            file_ << arr[i].department << " ";
            file_ << arr[i].year << "\n";
        }

        return true;
    }
    else
    {
        return false;
    }
}

bool readDataFromFile(data arr[], int n)
{
    string file;
    cout << "Enter Name of the File with Extension: - ";
    cin >> file;
    cout << "\n";

    ifstream file_;
    file_.open(file);
    if (file_.is_open())
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (j == 0)
                {
                    getline(file_, arr[i].name, ' ');
                }
                else if (j == 1)
                {
                    getline(file_, arr[i].age, ' ');
                }
                else if (j == 2)
                {
                    getline(file_, arr[i].department, ' ');
                }
                else if (j == 3)
                {
                    getline(file_, arr[i].year, ' ');
                }
            }
        }
    }

    return true;
}

int main()
{
    int n;
    cout << "Enter the number of student details to store: - ";
    cin >> n;

    data arr[n];
    storeDataFromUserInput(arr, n);
    writeDataFromArrayToFile(arr, n);
    readDataFromFile(arr, n);
    printDataStored(arr, n);
}
