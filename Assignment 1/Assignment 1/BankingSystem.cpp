#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class BankAccount
{
private:
    long int accNum;
    long int balance;
    string accName;

public:
    BankAccount(long int accountNumber, long int accountBalance, string accountHolderName)
    {
        accNum = accountNumber;
        accName = accountHolderName;
        balance = accountBalance;
    }

    void deposit(long int depAmount)
    {
        if (depAmount > 0)
        {
            balance += depAmount;
            cout << "Deposit successful! New balance: " << balance << endl;
            updateAccountInfo();
        }
        else
        {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(long int withdrawAmount)
    {
        if (withdrawAmount > balance || withdrawAmount <= 0)
        {
            cout << "Insufficient balance or invalid withdrawal amount!" << endl;
        }
        else
        {
            balance -= withdrawAmount;
            cout << "Withdrawal successful! New balance: " << balance << endl;
            updateAccountInfo();
        }
    }

    void checkBalance() const
    {
        cout << "Account Number: " << accNum << endl;
        cout << "Account Holder: " << accName << endl;
        cout << "Balance: " << balance << endl;
    }

    void updateAccountInfo()
    {
        ofstream outFile;
        outFile.open("bankAccount.txt");
        if (outFile.is_open())
        {
            outFile << "Account Number: " << accNum << endl;
            outFile << "Account Holder: " << accName << endl;
            outFile << "Balance: " << balance << endl;
            outFile << "Take a moment please..." << endl;
            outFile.close();
        }
        else
        {
            cout << "Error opening file!" << endl;
        }
    }

    static void readAccountInfo()
    {
        ifstream inFile;
        string line;
        inFile.open("bankAccount.txt");
        if (inFile.is_open())
        {
            while (getline(inFile, line))
            {
                cout << line << endl;
            }
            inFile.close();
        }
        else
        {
            cout << "Error opening file!" << endl;
        }
    }
};

int main()
{
    BankAccount acc1(148471, 50000, "Waleed Ahmed");
    acc1.deposit(3500);
    acc1.withdraw(10000);
    acc1.checkBalance();
    cout << "\nStored Account Information:\n";
    BankAccount::readAccountInfo();
    return 0;
}