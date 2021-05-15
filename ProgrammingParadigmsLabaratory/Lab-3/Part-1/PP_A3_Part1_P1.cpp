#include <iostream>
using namespace std;

class Student
{
private:
    string firstName;
    string lastName;
    int age;
    string department;
    int year;

public:
    Student() {}

    Student(string sfirstname, string slastname, int sage, string sdepartment, int syear)
    {
        firstName = sfirstname;
        lastName = slastname;
        age = sage;
        department = sdepartment;
        year = syear;
    }

    void EnterStudentData();
    void PrintStudentData() const;
};

void readStudentsData(Student *, int);
void printTotalClassData(Student *, int);

int main()
{
    int n;
    cout << "Enter number of students: - ";
    cin >> n;

    Student data[n];

    readStudentsData(data, n);
    printTotalClassData(data, n);

    return 1;
}

void Student ::EnterStudentData()
{
    cout << "Enter First Name of Student: - ";
    cin >> firstName;

    cout << "Enter Last Name of Student: - ";
    cin >> lastName;

    cout << "Enter Age of Student: - ";
    cin >> age;

    cout << "Enter Department of Student: - ";
    cin >> department;

    cout << "Enter Year of Study of Student: - ";
    cin >> year;
    cout << "\n\n";
}

void Student ::PrintStudentData() const
{
    cout << "Name of Student: - " << firstName << " " << lastName;
    cout << "\n";

    cout << "Age of Student: - ";
    cout << age;
    cout << "\n";

    cout << "Department of Student: - ";
    cout << department;
    cout << "\n";

    cout << "Year of Study of Student: - ";
    cout << year;
    cout << "\n\n";
}

void readStudentsData(Student *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Data of Student Number " << i + 1 << ": - " << endl;
        cout << "\n";

        arr[i].EnterStudentData();
    }
}

void printTotalClassData(Student *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Data of Student Number " << i + 1 << ": - " << endl;
        cout << "\n";

        arr[i].PrintStudentData();
    }
}