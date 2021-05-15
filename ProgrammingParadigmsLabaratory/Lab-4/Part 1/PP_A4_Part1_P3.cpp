#include <iostream>
using namespace std;

class Shape
{
public:
    virtual double area() = 0;
    virtual void setValues() = 0;
};

class Traingle : public Shape
{
protected:
    double base;
    double height;

public:
    Traingle()
    {
        cout << "Traingle Constructor" << endl;
    }

    Traingle(double x, double y) : base(x), height(y)
    {
        cout << "Parameterized Traingle Constructor" << endl;
    }

    ~Traingle()
    {
        cout << "Triangle Destructor" << endl;
    }

    void setValues()
    {
        double x, y;

        cout << "Enter Base: - ";
        cin >> x;

        cout << "Enter Height: - ";
        cin >> y;

        base = x;
        height = y;
    }

    double area()
    {
        return 0.5 * base * height;
    }
};

class Rectangle : public Shape
{
protected:
    double length;
    double breath;

public:
    Rectangle()
    {
        cout << "Rectangle Constructor" << endl;
    }

    Rectangle(double x, double y) : length(x), breath(y)
    {
        cout << "Parameterized Rectangle Constructor" << endl;
    }

    ~Rectangle()
    {
        cout << "Rectangle Destructor" << endl;
    }

    void setValues()
    {
        double x, y;

        cout << "Enter Length: - ";
        cin >> x;

        cout << "Enter Breath: - ";
        cin >> y;

        length = x;
        breath = y;
    }

    double area()
    {
        return length * breath;
    }
};

class Circle : public Shape
{
protected:
    double radius;

public:
    Circle()
    {
        cout << "Circle Constructor" << endl;
    }

    Circle(double x) : radius(x)
    {
        cout << "Parameterized Circle Constructor" << endl;
    }

    ~Circle()
    {
        cout << "Circle Destructor" << endl;
    }

    void setValues()
    {
        double x;

        cout << "Enter Radius: - ";
        cin >> x;

        radius = x;
    }

    double area()
    {
        return 3.14 * radius * radius;
    }
};

int main()
{
    int x, y, z;

    cout << "Number of Traingles: - ";
    cin >> x;

    cout << "Number of Rectangles: - ";
    cin >> y;

    cout << "Number of Circles: - ";
    cin >> z;

    Shape *s[x + y + z];

    double area = 0;

    for (int i = 0; i < x + y + z; i++)
    {
        if (i < x)
        {
            s[i] = new Traingle;
            s[i]->setValues();
            area = area + s[i]->area();
        }
        else if (i >= x && i < x + y)
        {
            s[i] = new Rectangle;
            s[i]->setValues();
            area = area + s[i]->area();
        }
        else
        {
            s[i] = new Circle;
            s[i]->setValues();
            area = area + s[i]->area();
        }

        delete s[i];
        s[i] = NULL;
    }

    cout << "Total Area: - " << area << endl;

    return 0;
}