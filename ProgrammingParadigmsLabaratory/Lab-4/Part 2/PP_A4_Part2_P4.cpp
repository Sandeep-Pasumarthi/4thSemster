#include <iostream>
using namespace std;

class Shape
{
public:
    virtual void setValues() = 0;
    virtual void display() = 0;
    virtual double area() = 0;
};

class Traingle : public Shape
{
protected:
    double base;
    double height;

public:
    Traingle();
    Traingle(double, double);
    ~Traingle();

    void setValues();
    void display();
    double area();
};

class Rectangle : public Shape
{
protected:
    double length;
    double breath;

public:
    Rectangle();
    Rectangle(double, double);
    ~Rectangle();

    void setValues();
    void display();
    double area();
};

class Circle : public Shape
{
protected:
    double radius;

public:
    Circle();
    Circle(double);
    ~Circle();

    void setValues();
    void display();
    double area();
};

class ShapeStackNode
{
protected:
    Shape *s;
    ShapeStackNode *next;

public:
    friend class ShapeStack;
};

class ShapeStack
{
protected:
    ShapeStackNode *head;

public:
    ShapeStack();
    ~ShapeStack();

    void push(Shape *);
    void pop();
    void display();
    double totalArea();
};

int main()
{
    ShapeStack s1;

    int x, y, z;

    cout << "Number of Traingles: - ";
    cin >> x;

    cout << "Number of Rectangles: - ";
    cin >> y;

    cout << "Number of Circles: - ";
    cin >> z;

    Shape *s[x + y + z];

    for (int i = 0; i < x + y + z; i++)
    {
        if (i < x)
        {
            s[i] = new Traingle;
            s[i]->setValues();
            s1.push(s[i]);
        }
        else if (i >= x && i < x + y)
        {
            s[i] = new Rectangle;
            s[i]->setValues();
            s1.push(s[i]);
        }
        else
        {
            s[i] = new Circle;
            s[i]->setValues();
            s1.push(s[i]);
        }
    }

    s1.display();

    return 0;
}

Traingle ::Traingle()
{
    cout << "Traingle Constructor" << endl;
}

Traingle ::Traingle(double x, double y) : base(x), height(y)
{
    cout << "Parameterized Traingle Constructor" << endl;
}

Traingle ::~Traingle()
{
    cout << "Triangle Destructor" << endl;
}

void Traingle ::setValues()
{
    double x, y;

    cout << "\n";
    cout << "Enter Base: - ";
    cin >> x;

    cout << "Enter Height: - ";
    cin >> y;
    cout << "\n";

    base = x;
    height = y;
}

void Traingle ::display()
{
    cout << "\n";
    cout << "Traingle: " << endl;
    cout << "Base: - " << base << endl;
    cout << "Height: - " << height << endl;
    cout << "Area of Traingle: - " << area() << endl;
    cout << "\n";
}

double Traingle ::area()
{
    return 0.5 * base * height;
}

Rectangle ::Rectangle()
{
    cout << "Rectangle Constructor" << endl;
}

Rectangle ::Rectangle(double x, double y) : length(x), breath(y)
{
    cout << "Parameterized Rectangle Constructor" << endl;
}

Rectangle ::~Rectangle()
{
    cout << "Rectangle Destructor" << endl;
}

void Rectangle ::setValues()
{
    double x, y;

    cout << "\n";
    cout << "Enter Length: - ";
    cin >> x;

    cout << "Enter Breath: - ";
    cin >> y;
    cout << "\n";

    length = x;
    breath = y;
}

void Rectangle ::display()
{
    cout << "\n";
    cout << "Rectangle: " << endl;
    cout << "Length: - " << endl;
    cout << "Breath: - " << breath << endl;
    cout << "Area of Rectangle: - " << area() << endl;
    cout << "\n";
}

double Rectangle ::area()
{
    return length * breath;
}

Circle ::Circle()
{
    cout << "Circle Constructor" << endl;
}

Circle ::Circle(double x) : radius(x)
{
    cout << "Parameterized Circle Constructor" << endl;
}

Circle ::~Circle()
{
    cout << "Circle Destructor" << endl;
}

void Circle ::setValues()
{
    double x;

    cout << "\n";
    cout << "Enter Radius: - ";
    cin >> x;
    cout << "\n";

    radius = x;
}

void Circle ::display()
{
    cout << "\n";
    cout << "Circle: " << endl;
    cout << "Radius: - " << radius << endl;
    cout << "Area of Circle: - " << area() << endl;
    cout << "\n";
}

double Circle ::area()
{
    return 3.14 * radius * radius;
}

ShapeStack ::ShapeStack()
{
    head = NULL;
    cout << "Shape Stack Constructor" << endl;
}

ShapeStack ::~ShapeStack()
{
    if (head == NULL)
    {
        cout << "Shape Stack Destructor" << endl;
    }
    else
    {
        ShapeStackNode *temp = new ShapeStackNode;
        ShapeStackNode *temp2 = new ShapeStackNode;
        temp = head;

        while (temp != NULL)
        {
            temp2 = temp;
            temp = temp->next;
            delete temp2;
            temp2 = NULL;
        }

        delete temp;

        cout << "Shape Stack Destructor" << endl;
    }
}

void ShapeStack ::push(Shape *val)
{
    ShapeStackNode *temp = new ShapeStackNode;
    temp->s = val;
    temp->next = head;
    head = temp;
}

void ShapeStack ::pop()
{
    if (head == NULL)
    {
        cout << "\n";
        cout << "Zero elements can't Pop" << endl;
        cout << "\n";

        return;
    }

    ShapeStackNode *temp = new ShapeStackNode;
    temp = head;
    head = head->next;
    temp->next = NULL;

    cout << "\n";
    cout << "Area popped out is " << temp->s->area() << endl;
    cout << "\n";
    delete temp;
    temp = NULL;
}

void ShapeStack ::display()
{
    ShapeStackNode *temp = new ShapeStackNode;
    temp = head;

    cout << "\n";
    cout << "Plot Consists: " << endl;
    while (temp != NULL)
    {
        temp->s->display();
        temp = temp->next;
    }

    totalArea();
    cout << "\n";

    delete temp;
}

double ShapeStack ::totalArea()
{
    ShapeStackNode *temp = new ShapeStackNode;
    temp = head;
    double area = 0;

    while (temp != NULL)
    {
        area = area + temp->s->area();
        temp = temp->next;
    }

    cout << "\n";
    cout << "Total Area of Plot: - " << area << endl;
    cout << "\n";

    delete temp;
    return area;
}