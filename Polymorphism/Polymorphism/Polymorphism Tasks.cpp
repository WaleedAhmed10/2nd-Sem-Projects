#include <iostream>
#include <string>
using namespace std;

class Factorial
{
public:
    virtual int calculate(int n) = 0;
};

class IterativeFactorial : public Factorial
{
public:
    int calculate(int n) override
    {
        int fact = 1;
        for (int i = 1; i <= n; i++)
        {
            fact = fact * i;
        }
        return fact;
    }
};

class Polygon
{
private:
    int width;
    int height;
public:
    void set_values(int a, int b)
    {
        width = a;
        height = b;
    }
    virtual double area() = 0;
    int getWidth() const { return width; }
    int getHeight() const { return height; }
};

class Rectangle : public Polygon
{
public:
    double area() override
    {
        return getWidth() * getHeight();
    }
};

class Triangle : public Polygon
{
public:
    double area() override
    {
        return 0.5 * getWidth() * getHeight();
    }
};

class Person
{
public:
    string name;
    string address;
    int fees;
    char grade;

    void getInput()
    {
        cin.ignore();
        cout << "Enter name of student: " << endl;
        getline(cin, name);
        cout << "Enter address of student: " << endl;
        getline(cin, address);
        cout << "Enter fees of student: " << endl;
        cin >> fees;
        cout << "Enter grade of student: " << endl;
        cin >> grade;
    }

    void display()
    {
        cout << "Name is: " << name << endl;
        cout << "Address is: " << address << endl;
        cout << "Fees is: " << fees << endl;
        cout << "Grade is: " << grade << endl;
    }
};

class Lecturer : public Person
{
public:
    int salary;
    int lectures_per_week;

    void getInput()
    {
        cin.ignore();
        cout << "Enter name of lecturer: " << endl;
        getline(cin, name);
        cout << "Enter address of lecturer: " << endl;
        getline(cin, address);
        cout << "Enter salary: " << endl;
        cin >> salary;
        cout << "Enter lectures in a week: " << endl;
        cin >> lectures_per_week;
    }

    void display()
    {
        cout << "Name is: " << name << endl;
        cout << "Address is: " << address << endl;
        cout << "Salary is: " << salary << endl;
        cout << "Lectures in a week is: " << lectures_per_week << endl;
    }
};

int main()
{
    Rectangle rect;
    Triangle tri;
    int width, height;
    cout << "Enter the width = ";
    cin >> width;
    cout << "Enter the height = ";
    cin >> height;
    rect.set_values(width, height);
    cout << "Area of Rectangle = " << rect.area() << endl;
    cout << "Enter the width = ";
    cin >> width;
    cout << "Enter the height = ";
    cin >> height;
    tri.set_values(width, height);
    cout << "Area of Triangle = " << tri.area() << endl;

    int num;
    cout << "Enter the number: ";
    cin >> num;
    Factorial* fact;
    fact = new IterativeFactorial();
    cout << "Factorial = " << fact->calculate(num) << endl;
    delete fact;

    Person student;
    student.getInput();
    student.display();
    cout << "***" << endl;
    Lecturer lecturer;
    lecturer.getInput();
    lecturer.display();
    return 0;
}