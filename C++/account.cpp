#include <iostream>
using namespace std;
class BankAccount 
{
    private: string dName;
             static int aNo;
             int aType;
             float balance;
             float minbal1=1000.00;
             float minbal2=500.00;
    public:
    int c; 
    BankAccount(): dName (" "), aType (0), balance (0.0) {}
    int Assign ()
    {
        cout << "Enter Name:";
        cin.ignore ();
        getline (cin,dName);
        cout << "Account number is:" << aNo << endl ;
        cout << "Enter Account type (1.Savings or 2.Checking):";
        cin >> aType;
        cout << "Enter Initial balance:";
        cin >> balance;
        if (aType==1 && balance<minbal1)
        {
            cout << "Minimum balance is Rs 1000." << endl << "Enter Initial balance:";
            cin >> balance;
            if (balance<minbal1)
            {
                cout << "Enter Initial balance:";
                cin >> balance;
            }
        }
         if (aType==2 && balance<minbal2)
        {
            cout << "Minimum balance is Rs 500." << endl << "Enter Initial balance:";
            cin >> balance;
            if (balance<minbal2)
            {
                cout << "Enter Initial balance:";
                cin >> balance;
            }
        }
        if ((aType==1 && balance>=minbal1) || (aType==2 && balance>=minbal2))
        {cout << "Account created successfully." << endl;
        c=aNo;
        aNo++;}
        else cout << "Failed to create account." << endl;
        return 0;
    } 
    void Deposit ()
    {
        double amount;
        cout << "Enter the amount to be deposited:";
        cin >> amount;
        if (amount>0)
        {
            balance = balance + amount;
            cout << "Deposit successful. Current Balance= Rs " << balance << endl;
        }
        else cout << "Invalid deposit amount." << endl;
    }
    void Withdraw ()
    {
        double amount;
        if (aType == 1)
        {
            cout << "Minimum balance of Savings account is Rs 1000." << endl << "Enter the amount to Withdraw:";
            cin >> amount;
            if (amount<=balance-minbal1 && amount > 0)
            {
                balance= balance-amount;
                cout << "Withdraw successful: Current Balance= Rs " << balance << endl;
            }
            else 
            {
                cout << "Insufficient Balance. Balance= Rs " << balance << endl;
                cout << "Enter the amount to be Withdrawn:";
                cin >> amount;
                if (amount<=balance-minbal1 && amount > 0)
                {
                   balance= balance-amount;
                   cout << "Withdraw successful: Current Balance= Rs " << balance << endl;
                }
                else cout << "Insufficient Balance. Balance= Rs " << balance << endl;
            }
        }
        if (aType == 2)
        {
            cout << "Minimum balance of Checking account is Rs 500." << endl << "Enter the amount to Withdraw:";
            cin >> amount;
            if (amount<=balance-minbal2 && amount > 0)
            {
                balance= balance-amount;
                cout << "Withdraw successful: Current Balance= Rs " << balance << endl;
            }
            else 
            {
                cout << "Insufficient Balance. Balance= Rs " << balance << endl;
                cout << "Enter the amount to be Withdrawn:";
                cin >> amount;
                if (amount<=balance-minbal2 && amount > 0)
                {
                   balance= balance-amount;
                   cout << "Withdraw successful: Current Balance= Rs " << balance << endl;
                }
                else cout << "Insufficient Balance. Balance= Rs " << balance << endl;
            }
        }
    }
    void Display ()
    {
        cout << "Bank Account Details:\n";
        cout << "Name: " << dName << endl;
        cout << "Account no: " << c << endl;
        cout << "Balance: Rs " << balance << endl;
    }
};
int BankAccount :: aNo=10000001;
int main ()
{
    BankAccount acc[100];
    int e, d=1, y=0, p=0, ano, i;
    while (d>0)
    {
        cout << "Choose a function to perform:\n0.Exit\n1.Account Creation\n2.Deposit\n3.Withdraw\n4.Display\nChoice:";
        cin >> e;
        switch (e)
        {
            case 0: d=0;
                    break;
            case 1: y=acc[p].Assign();
                    if (y==1)
                    {
                        p++;
                        y=0;
                    }
                    break;
            case 2: cout << "Enter Account no: " ;
                    cin >> ano;
                    for (i=0;i<p;i++)
                    {
                        if (acc[i].c==ano)
                        break;
                    }
                    if (i>p)
                    cout << "Account not found.\n";
                    else 
                    acc[i].Deposit();
                    break;
            case 3: cout << "Enter Account no: " ;
                    cin >> ano;
                    for (i=0;i<p;i++)
                    {
                        if (acc[i].c==ano)
                        break;
                    }
                    if (i>p)
                    cout << "Account not found.\n";
                    else 
                    acc[i].Withdraw();
                    break;
            case 4: cout << "Enter Account no: " ;
                    cin >> ano;
                    for (i=0;i<p;i++)
                    {
                        if (acc[i].c==ano)
                        break;
                    }
                    if (i>p)
                    cout << "Account not found.\n";
                    else 
                    acc[i].Display();
                    break;
            default : cout << "Invalid choice, choose again!";
        }
    }
    return 0;
}