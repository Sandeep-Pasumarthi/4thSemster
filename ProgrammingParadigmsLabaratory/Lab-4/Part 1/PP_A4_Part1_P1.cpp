#include <iostream>
using namespace std;

class Vehicle
{
protected:
    int price;
    string manufacturer;

public:
    Vehicle(){};
    Vehicle(int, string);
    Vehicle(const Vehicle &);
    Vehicle &operator=(const Vehicle &);
    virtual ~Vehicle();

    virtual void readData();
    virtual void displayData();
};

class Car : public Vehicle
{
protected:
    string colour;
    int nSeats;
    string model;

public:
    Car(){};
    Car(string, int, string, int, string);
    Car(const Car &);
    Car &operator=(const Car &);
    ~Car();

    void readData();
    void displayData();
};

int main()
{
    // Parameterized Constructor
    Vehicle one(1700, "Arjun");
    one.displayData();
    cout << "\n\n";

    // Copy Constructor
    Vehicle two(one);
    two.displayData();
    cout << "\n\n";

    // Assignment Operator
    Vehicle three;
    three = two;
    three.displayData();
    cout << "\n\n";

    // Reading Data Function
    Vehicle four;
    four.readData();
    four.displayData();
    cout << "\n\n";

    // Parameterized Constructor
    Car c1("Blue", 17, "Pasupathastra", 17000000, "Sandeep");
    c1.displayData();
    cout << "\n\n";

    // Copy Constructor
    Car c2(c1);
    c1.displayData();
    cout << "\n\n";

    // Assignment Operator
    Car c3;
    c3 = c1;
    c3.displayData();
    cout << "\n\n";

    // Reading Data Function
    Car c4;
    c4.readData();
    cout << "\n\n";
    c4.displayData();
    cout << "\n\n";

    /*Car *c5 = new Car;
    c5 = &one; // Results in error*/

    // Use of Virtual Function
    Vehicle *v5;
    v5 = &c1;
    v5->displayData();
    cout << "\n\n";
    v5->readData();
    cout << "\n\n";
    v5->displayData();
    cout << "\n\n";

    delete v5;
    v5 = NULL;

    return 0;
}

Vehicle ::Vehicle(int cost, string name)
{
    price = cost;
    manufacturer = name;

    cout << "Parameterized Vehicle Constructor" << endl;
}

Vehicle ::Vehicle(const Vehicle &src)
{
    price = src.price;
    manufacturer = src.manufacturer;

    cout << "Copy Vehicle Constructor" << endl;
}

Vehicle &Vehicle::operator=(const Vehicle &src)
{
    if (this == &src)
    {
        return *this;
    }

    price = src.price;
    manufacturer = src.manufacturer;

    cout << "Assignment Operator" << endl;

    return *this;
}

Vehicle ::~Vehicle()
{
    cout << "Vehicle Destructor Called" << endl;
}

void Vehicle::readData()
{
    int cost;
    string name;
    cout << "Enter Cost: - ";
    cin >> cost;
    cout << "Enter Name: - ";
    cin >> name;

    price = cost;
    manufacturer = name;
}

void Vehicle::displayData()
{
    cout << "Displaying Vehicle Data: -" << endl;
    cout << "Price: - " << price << endl;
    cout << "Manufacturer: - " << manufacturer << endl;
}

Car ::Car(string col, int seats, string mod, int cost, string name) : Vehicle(cost, name)
{
    colour = col;
    nSeats = seats;
    model = mod;

    cout << "Derived Parameterized Constructor" << endl;
}

Car ::Car(const Car &src) : Vehicle(src)
{
    colour = src.colour;
    nSeats = src.nSeats;
    model = src.model;

    cout << "Derived Copy Constructor" << endl;
}

Car &Car::operator=(const Car &src)
{
    if (this == &src)
    {
        return *this;
    }
    Vehicle::operator=(src);
    colour = src.colour;
    nSeats = src.nSeats;
    model = src.model;

    cout << "Derived Assignment Operator" << endl;

    return *this;
}

Car ::~Car()
{
    cout << "Car Destructor Called" << endl;
}

void Car ::readData()
{
    Vehicle::readData();
    string col;
    int seats;
    string mod;

    cout << "Enter Colour: - ";
    cin >> col;
    cout << "Enter Number of Seats: - ";
    cin >> seats;
    cout << "Enter Model: - ";
    cin >> mod;

    colour = col;
    nSeats = seats;
    model = mod;

    cout << "Derived Read" << endl;
}

void Car ::displayData()
{
    cout << "Displaying Car Details: -" << endl;
    cout << "Price: - " << Vehicle::price << endl;
    cout << "Manufacturer: - " << Vehicle::manufacturer << endl;
    cout << "Colour: - " << colour << endl;
    cout << "Number of Seats: - " << nSeats << endl;
    cout << "Model: - " << model << endl;
}