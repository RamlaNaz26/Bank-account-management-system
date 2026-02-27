#include <iostream>
using namespace std;


class BankAccount
{
private:
    int accNo[100];
    string name[100];
    double balance[100];
    int total;   // total accounts

public:
    // Constructor
    BankAccount()
    {
        total = 0;
    }

    // Create account
    void createAccount()
    {
        cout << "\nEnter Account Number: ";
        cin >> accNo[total];

        cout << "Enter Account Holder Name: ";
        cin.ignore();
        getline(cin, name[total]);

        cout << "Enter Initial Balance: ";
        cin >> balance[total];

        total++;
        cout << "\nAccount Created Successfully!\n";
    }

    // Display all accounts
    void displayAccounts()
    {
        if (total == 0)
        {
            cout << "\nNo Accounts Available!\n";
            return;
        }

        cout << "\nAccount No\tName\t\tBalance\n";
        cout << "----------------------------------------\n";

        for (int i = 0; i < total; i++)
        {
            cout << accNo[i] << "\t\t" << name[i] << "\t\t" << balance[i] << endl;
        }
    }

    // Deposit money
    void deposit()
    {
        int number;
        double amount;
        bool found = false;

        cout << "\nEnter Account Number: ";
        cin >> number;

        for (int i = 0; i < total; i++)
        {
            if (accNo[i] == number)
            {
                cout << "Enter Deposit Amount: ";
                cin >> amount;
                balance[i] += amount;
                cout << "\nAmount Deposited Successfully!\n";
                found = true;
                break;
            }
        }

        if (!found)
            cout << "\nAccount Not Found!\n";
    }

    // Withdraw money
    void withdraw()
    {
        int number;
        double amount;
        bool found = false;

        cout << "\nEnter Account Number: ";
        cin >> number;

        for (int i = 0; i < total; i++)
        {
            if (accNo[i] == number)
            {
                cout << "Enter Withdraw Amount: ";
                cin >> amount;

                if (balance[i] >= amount)
                {
                    balance[i] -= amount;
                    cout << "\nWithdrawal Successful!\n";
                }
                else
                {
                    cout << "\nInsufficient Balance!\n";
                }
                found = true;
                break;
            }
        }

        if (!found)
            cout << "\nAccount Not Found!\n";
    }

    // Search account
    void searchAccount()
    {
        int number;
        bool found = false;

        cout << "\nEnter Account Number to Search: ";
        cin >> number;

        for (int i = 0; i < total; i++)
        {
            if (accNo[i] == number)
            {
                cout << "\nAccount Found!\n";
                cout << "Account No: " << accNo[i] << endl;
                cout << "Name: " << name[i] << endl;
                cout << "Balance: " << balance[i] << endl;
                found = true;
                break;
            }
        }

        if (!found)
            cout << "\nAccount Not Found!\n";
    }
};

int main()
{
    BankAccount bank;
    int choice;

    do
    {
        cout << "\n======= BANK ACCOUNT MANAGEMENT SYSTEM =======\n";
        cout << "1. Create Account\n";
        cout << "2. Display All Accounts\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Search Account\n";
        cout << "6. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            bank.createAccount();
            break;
        case 2:
            bank.displayAccounts();
            break;
        case 3:
            bank.deposit();
            break;
        case 4:
            bank.withdraw();
            break;
        case 5:
            bank.searchAccount();
            break;
        case 6:
            cout << "\nThank You for Using Bank System!\n";
            break;
        default:
            cout << "\nInvalid Choice! Try Again.\n";
        }

    } while (choice != 6);

    return 0;
}
