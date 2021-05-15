#include <iostream>
using namespace std;

class Person
{
protected:
    string name;
    int age;
    char gender;

public:
    Person(){};
    Person(string, int, char);
    ~Person();

    virtual void readData(string, int, char);
    virtual void displayData();
};

class Student : virtual public Person
{
protected:
    string department;
    int year;

public:
    Student(){};
    Student(string, int, string, int, char);
    ~Student();

    void readData(string, int, string, int, char);
    void displayData();
};

class Clerk : virtual public Person
{
protected:
    int workload;
    int salary;

public:
    Clerk(){};
    Clerk(int, int, string, int, char);
    ~Clerk();

    void readData(int, int, string, int, char);
    void displayData();
};

class Professor : public Student, public Clerk
{
protected:
    int courseload;

public:
    Professor(){};
    Professor(string, int, int, string, int, char);
    ~Professor();

    void readData(string, int, int, string, int, char);
    void displayData();
};

int main()
{
    Person p1("Arjuna", 17, 'M');
    p1.displayData();
    cout << "\n\n";
    Person p2;
    p2.readData("Sandeep", 19, 'M');
    p2.displayData();
    cout << "\n\n";

    Student s1("CST", 2021, "Sandeep", 18, 'M');
    s1.displayData();
    cout << "\n\n";
    Student s2;
    s2.readData("AERO", 2023, "Arjuna", 17, 'M');
    s2.displayData();
    cout << "\n\n";

    Clerk c1(16, 20000, "Sandeep", 16, 'M');
    c1.displayData();
    cout << "\n\n";
    Clerk c2;
    c2.readData(17, 25000, "Satwik", 18, 'M');
    c2.displayData();
    cout << "\n\n";

    Professor pr1("CST", 5, 100000, "Dhrona", 1000, 'M');
    pr1.displayData();
    cout << "\n\n";
    Professor pr2;
    pr2.readData("AERO", 10, 1000000, "Shukra", 15000, 'M');
    pr2.displayData();
    cout << "\n\n";

    return 0;
}

Person ::Person(string n, int a, char g)
{
    name = n;
    age = a;
    gender = g;

    cout << "Parameterized Person Constructor" << endl;
}

Person ::~Person()
{
    cout << "Person Destructor" << endl;
}

void Person ::readData(string n, int a, char g)
{
    name = n;
    age = a;
    gender = g;
}

void Person ::displayData()
{
    cout << "Name: - " << name << endl;
    cout << "Age: - " << age << endl;
    cout << "Gender: - " << gender << endl;
}

Student ::Student(string d, int y, string n, int a, char g) : Person(n, a, g)
{
    department = d;
    year = y;

    cout << "Parameterized Student Constructor" << endl;
}

Student ::~Student()
{
    cout << "Student Destructor" << endl;
}

void Student::readData(string d, int y, string n, int a, char g)
{
    Person::readData(n, a, g);
    department = d;
    year = y;
}

void Student::displayData()
{
    Person::displayData();
    cout << "Department: - " << department << endl;
    cout << "Year: - " << year << endl;
}

Clerk ::Clerk(int w, int s, string n, int a, char g) : Person(n, a, g)
{
    workload = w;
    salary = s;

    cout << "Parameterized Clerk Costructor" << endl;
}

Clerk ::~Clerk()
{
    cout << "Clerk Destructor" << endl;
}

void Clerk ::readData(int w, int s, string n, int a, char g)
{
    Person::readData(n, a, g);
    workload = w;
    salary = s;
}

void Clerk ::displayData()
{
    Person::displayData();
    cout << "Work Load: - " << workload << endl;
    cout << "Salary: - " << salary << endl;
}

Professor ::Professor(string d, int c, int s, string n, int a, char g) : Student(d, 0, n, a, g), Clerk(0, s, n, a, g), Person(n, a, g)
{
    courseload = c;

    cout << "Parameterized Professor Constructor" << endl;
}

Professor ::~Professor()
{
    cout << "Professor Destructor" << endl;
}

void Professor::readData(string d, int c, int s, string n, int a, char g)
{
    Person::readData(n, a, g);
    department = d;
    courseload = c;
    salary = s;
}

void Professor::displayData()
{
    Person::displayData();
    cout << "Department: - " << department << endl;
    cout << "Course Load: - " << courseload << endl;
    cout << "Salary: - " << salary << endl;
}