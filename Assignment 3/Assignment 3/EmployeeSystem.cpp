#include <iostream>
#include <string>
using namespace std;

class Employee
{
protected:
    string name;
    int id;

public:
    virtual ~Employee()
    {
        cout << "Base Employee destructor called.\n";
    }

    virtual void getInfo()
    {
        cin.ignore();
        cout << "Enter the name: ";
        getline(cin, name);
        cout << "Enter ID: ";
        cin >> id;
    }

    virtual float calculateSalary() = 0;

    virtual void displayInfo()
    {
        cout << "Employee's Name: " << name << endl;
        cout << "Employee's ID: " << id << endl;
        cout << "Employee's Salary: " << calculateSalary() << endl;
    }
};

class Manager : public Employee
{
private:
    float baseSalary;
    float bonus;

public:
    ~Manager() override
    {
        cout << "Manager destructor called.\n";
    }

    void getInfo() override
    {
        cout << "Entering details for Manager...\n";
        Employee::getInfo();
        cout << "Enter base salary: ";
        cin >> baseSalary;
        cout << "Enter bonus: ";
        cin >> bonus;
    }

    float calculateSalary() override
    {
        return baseSalary + bonus;
    }
};

class Developer : public Employee
{
private:
    float baseSalary;
    int overtimeHours;
    int hourlyRate;

public:
    ~Developer() override
    {
        cout << "Developer destructor called.\n";
    }

    void getInfo() override
    {
        cout << "Entering details for Developer...\n";
        Employee::getInfo();
        cout << "Enter base salary: ";
        cin >> baseSalary;
        cout << "Enter overtime hours: ";
        cin >> overtimeHours;
        cout << "Enter hourly rate: ";
        cin >> hourlyRate;
    }

    float calculateSalary() override
    {
        return baseSalary + (overtimeHours * hourlyRate);
    }
};

class Intern : public Employee
{
private:
    float stipend;

public:
    ~Intern() override
    {
        cout << "Intern destructor called.\n";
    }

    void getInfo() override
    {
        cout << "Entering details for Intern...\n";
        Employee::getInfo();
        cout << "Enter stipend: ";
        cin >> stipend;
    }

    float calculateSalary() override
    {
        return stipend;
    }
};

int main()
{
    const int numEmployees = 3;
    Employee* employees[numEmployees];

    employees[0] = new Manager();
    employees[1] = new Developer();
    employees[2] = new Intern();

    for (int i = 0; i < numEmployees; i++)
    {
        employees[i]->getInfo();
        cout << endl;
    }

    cout << "\nEmployee Details:\n";
    for (int i = 0; i < numEmployees; i++)
    {
        employees[i]->displayInfo();
        cout << endl;
    }

    cout << "Deleting employees...\n";
    for (int i = 0; i < numEmployees; i++)
    {
        delete employees[i];
    }
    return 0;
}