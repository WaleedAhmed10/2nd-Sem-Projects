#include <iostream>
#include <string>
using namespace std;

//Single inheritance
class student {
private:
    string name, rollNum, address;
public:
    void getData()
    {
        cout << "Enter Name: ";
        cin >> name;
        getline(cin, name);
        cout << "Enter Roll Number: ";
        cin >> rollNum;
        cout << "Enter Address: ";
        cin >> address;
        getline(cin, address);
    }
    void displayData()
    {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNum << endl;
        cout << "Address: " << address << endl;
    }
};

class marks : public student {
private:
    int m1, m2, m3;
public:
    void inputMarks()
    {
        getData();
        cout << "Enter marks of subject 1: ";
        cin >> m1;
        cout << "Enter marks of subject 2: ";
        cin >> m2;
        cout << "Enter marks of subject 3: ";
        cin >> m3;
    }
    int totalMarks() {
        return m1 + m2 + m3;
    }
    int avgMarks()
    {
        return totalMarks() / 3;
    }
    void show_detail()
    {
        displayData();
        cout << "Marks in subject 1: " << m1 << endl;
        cout << "Marks in subject 2: " << m2 << endl;
        cout << "Marks in subject 3: " << m3 << endl;
        cout << "Total Marks: " << totalMarks() << endl;
        cout << "Average Marks: " << avgMarks() << endl;
    }
};

//Multiple inheritance
class employee
{
protected:
    string empName;
    int empId;
public:
    void inputEmployee()
    {
        cout << "Enter employee name: ";
        cin >> empName;
        cout << "Enter employee ID: ";
        cin >> empId;
    }
    void showEmployee()
    {
        cout << "Employee Name: " << empName << ", Employee ID: " << empId << endl;
    }
};

class studentDetails
{
protected:
    string degree;
    string institute;
public:
    void inputStudent()
    {
        cout << "Enter degree: ";
        cin >> degree;
        cout << "Enter institute: ";
        cin >> institute;
    }
    void showStudent()
    {
        cout << "Degree: " << degree << ", Institute: " << institute << endl;
    }
};

class manager : public employee, public studentDetails
{
private:
    string title;
    string salary;
public:
    void input()
    {
        inputEmployee();
        inputStudent();
        cout << "Enter manager title: ";
        cin >> title;
        cout << "Enter manager salary: ";
        cin >> salary;
    }
    void show()
    {
        showEmployee();
        showStudent();
        cout << "Title: " << title << ", Salary: " << salary << endl;
    }
};

class scientist : public employee, public studentDetails
{
private:
    int articlesPublished;
    string salary;
public:
    void input()
    {
        inputEmployee();
        inputStudent();
        cout << "Enter number of articles published: ";
        cin >> articlesPublished;
        cout << "Enter scientist salary: ";
        cin >> salary;
    }
    void show()
    {
        showEmployee();
        showStudent();
        cout << "Articles Published: " << articlesPublished << ", Salary: " << salary << endl;
    }
};

class laborer : public employee
{
private:
    int hoursWorked;
public:
    void input()
    {
        inputEmployee();
        cout << "Enter hours worked: ";
        cin >> hoursWorked;
    }
    void show()
    {
        showEmployee();
        cout << "Hours Worked: " << hoursWorked << endl;
    }
};

int main()
{
    marks std1;
    std1.inputMarks();
    cout << "\nStudent Details and Marks:" << endl;
    std1.show_detail();
    manager mgr;
    scientist sci;
    laborer lab;

    cout << "\nEnter details for Manager:\n";
    mgr.input();
    cout << "\nEnter details for Scientist:\n";
    sci.input();
    cout << "\nEnter details for Laborer:\n";
    lab.input();
    cout << "\nDetails of Manager:\n";
    mgr.show();
    cout << "\nDetails of Scientist:\n";
    sci.show();
    cout << "\nDetails of Laborer:\n";
    lab.show();
    return 0;
}