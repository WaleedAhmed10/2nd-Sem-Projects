#include <iostream>
#include <string>
using namespace std;

class BankAccount
{
private:
    long int acNum;
    string* accName;
    double balance;
    static int accountCount;

public:
    BankAccount(long int accountNumber, double accountBalance, string accountHolderName)
    {
        acNum = accountNumber;
        balance = accountBalance;
        accName = new string(accountHolderName);
        accountCount++;
    }

    ~BankAccount()
    {
        delete accName;
    }

    void deposit(double depAmount)
    {
        if (depAmount > 0)
        {
            balance += depAmount;
            cout << "Deposit successful! New balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    void withdraw(double withdrawAmount)
    {
        if (withdrawAmount > balance || withdrawAmount <= 0)
        {
            cout << "Insufficient balance or invalid withdrawal amount!" << endl;
        }
        else
        {
            balance -= withdrawAmount;
            cout << "Withdrawal successful! New balance: " << balance << endl;
        }
    }

    void checkBalance() const
    {
        cout << "Account Number: " << acNum << endl;
        cout << "Account Holder: " << *accName << endl;
        cout << "Balance: " << balance << endl;
    }

    static int getAccountCount()
    {
        return accountCount;
    }

    BankAccount operator+(double amount)
    {
        balance += amount;
        return *this;
    }

    BankAccount operator-(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
        }
        return *this;
    }

    bool operator==(const BankAccount& other) const
    {
        return balance == other.balance;
    }

    friend void displayAccountDetails(const BankAccount& account);
};

int BankAccount::accountCount = 0;

void displayAccountDetails(const BankAccount& account)
{
    cout << "\nAccount Details:\n";
    cout << "Account Number: " << account.acNum << endl;
    cout << "Account Holder: " << *(account.accName) << endl;
    cout << "Balance: " << account.balance << endl;
}

int main()
{
    BankAccount acc1(148471, 50000, "Aftab Ahmed");
    BankAccount acc2(148472, 30000, "Waleed Ahmed");

    acc1.checkBalance();
    acc1.deposit(3500);
    acc1.withdraw(20000);
    acc1.checkBalance();

    acc2.deposit(4500);
    acc2.withdraw(10000);
    acc2.checkBalance();

    displayAccountDetails(acc1);
    displayAccountDetails(acc2);

    cout << "\nTotal number of accounts created: " << BankAccount::getAccountCount() << endl;

    if (acc1 == acc2)
        cout << "Both accounts have same balance" << endl;
    else
        cout << "Accounts have different balances" << endl;
    return 0;
}