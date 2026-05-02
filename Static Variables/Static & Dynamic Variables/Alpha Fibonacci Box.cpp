#include <iostream>
using namespace std;

class alpha
{
    static int total;
    int id;
public:
    alpha()
    {
        total++;
        id = total;
    }
    static void showtotal()
    {
        cout << "Total = " << total << endl;
    }
    void showid()
    {
        cout << "ID is = " << id << endl;
    }
};

int alpha::total = 0;

class Box
{
private:
    float length, width, height;
    static int objectCount;
public:
    Box(float l, float w, float h)
    {
        length = l;
        width = w;
        height = h;
        objectCount++;
    }
    static int getObjectCount()
    {
        return objectCount;
    }
};

int Box::objectCount = 0;

class Fibonacci
{
private:
    static int calc(int x)
    {
        if (x <= 1)
        {
            return x;
        }
        return (calc(x - 1) + calc(x - 2));
    }
public:
    static void printSeries(int x)
    {
        for (int i = 0; i < x; i++)
        {
            cout << calc(i) << " ";
        }
    }
};

class sumIntegers
{
private:
    static int sum;
public:
    void add(int num)
    {
        sum += num;
        cout << "Current Sum: " << sum << endl;
    }
    static int getSum()
    {
        return sum;
    }
};

int sumIntegers::sum = 0;

int main()
{
    alpha a1;
    cout << "After creating one object, value of total:" << endl;
    alpha::showtotal();
    alpha a2, a3;
    cout << "After creating more than one object, value of total:" << endl;
    alpha::showtotal();
    a1.showid();
    a2.showid();
    a3.showid();

    int x;
    cout << "Enter number of Fibonacci terms: ";
    cin >> x;
    cout << "Fibonacci numbers up to " << x << " terms: ";
    Fibonacci::printSeries(x);

    sumIntegers obj1, obj2;
    int m;
    cout << "\nPlease enter 5 numbers to be summed" << endl;
    for (int i = 1; i <= 5; ++i)
    {
        cout << "Enter a number: ";
        cin >> m;
        obj1.add(m);
    }
    cout << "The final total is: " << sumIntegers::getSum() << endl;

    Box b1(1.0, 2.0, 3.0);
    Box b2(4.0, 5.0, 6.0);
    cout << "\nNumber of Box objects created: " << Box::getObjectCount() << endl;
    return 0;
}