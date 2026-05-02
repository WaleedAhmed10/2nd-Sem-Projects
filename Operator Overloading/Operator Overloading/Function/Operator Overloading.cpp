#include <iostream>
#include <cmath>
using namespace std;

//Functional Overloading:
int power(int);
double power(double);

int main()
{
    int a;
    double x;
    cout << "Enter an integer values: \n";
    cin >> a;
    cout << "Enter a floating value: \n";
    cin >> x;
    cout << power(a) << endl;
    cout << power(x) << endl;
    return 0;
}

int power(int x)
{
    return pow(x, 1.0 / 3.0);
}

double power(double x)
{
    return pow(x, 1.0 / 3.0);
}

//Operational Overloading:
class counter
{
public:
    int count;
    counter()
    {
        count = 0;
    }
    counter operator++()
    {
        ++count;
        return *this;
    }
    void display()
    {
        cout << "Value of c1 = " << count << endl;
    }
};

int main()
{
    counter c1, c2;
    cout << "Value of c1 = " << c1.count << endl;
    cout << "Value of c2 = " << c2.count << endl;
    ++c1;
    c1.display();

    int a;
    double x;
    cout << "Enter an integer values: \n";
    cin >> a;
    cout << "Enter a floating value: \n";
    cin >> x;
    cout << power(a) << endl;
    cout << power(x) << endl;
    return 0;
}
