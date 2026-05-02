#include <iostream>
#include <string>
using namespace std;

class Cube
{
public:
    double side;
    Cube(double s) : side(s)
    {
        cout << "The Cube's sides length are " << side << endl;
    }
    double volume()
    {
        return side * side * side;
    }
    ~Cube()
    {
        cout << "Cube object destroyed" << endl;
    }
};

class Date
{
    int day;
    int month;
    int year;
public:
    Date(int d, int m, int y) : day(d), month(m), year(y) {}
    void displayDate()
    {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
    }
};

class Convert
{
public:
    int bin, decimal, octal;
    Convert(int binary)
    {
        bin = binary;
        decimal = 0;
        octal = 0;
        binaryToOctal();
    }
    void binaryToOctal()
    {
        decimal = convBinaryToDecimal(bin);
        convDecimalToOctal(decimal);
    }
    int convBinaryToDecimal(int x)
    {
        int base = 1, rem, dec = 0;
        while (x > 0)
        {
            rem = x % 10;
            dec += rem * base;
            base *= 2;
            x /= 10;
        }
        return dec;
    }
    void convDecimalToOctal(int x)
    {
        int temp = x;
        int rem, i = 1;
        octal = 0;
        while (temp > 0)
        {
            rem = temp % 8;
            octal += rem * i;
            temp /= 8;
            i *= 10;
        }
    }
    void displayResult()
    {
        cout << "Binary:" << bin << " -> Octal: " << octal << endl;
    }
};

class employee
{
    string name;
    int id;
    double salary;
public:
    employee(string n, int i, double s)
    {
        name = n;
        id = i;
        salary = s;
    }
    void displayinfo()
    {
        cout << "name: " << name << endl;
        cout << "id: " << id << endl;
        cout << "salary: " << salary << endl;
    }
};

int main()
{
    double s;
    cout << "Enter the length of the sides of the cube: ";
    cin >> s;
    Cube cu(s);
    cout << "Volume of the cube: " << cu.volume() << endl;

    int day, month, year;
    cout << "Enter day: ";
    cin >> day;
    cout << "Enter month: ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;
    Date date(day, month, year);
    date.displayDate();

    int binary;
    cout << "Enter binary number: ";
    cin >> binary;
    Convert c(binary);
    c.displayResult();

    string name;
    int id;
    double salary;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter id: ";
    cin >> id;
    cout << "Enter salary: ";
    cin >> salary;
    employee E(name, id, salary);
    E.displayinfo();
    return 0;
}