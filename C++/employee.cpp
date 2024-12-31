#include <iostream>
using namespace std;
class Employee 
{
    protected: string name;
               int empno;
               double payrate;
    public:
    Employee (string n, int emp, double pr): name(n), empno(emp), payrate(pr) {}
    virtual void pay() 
    {
        double hr;
        cout << "Enter the hours worked by employee: ";
        cin >> hr;
        cout << "Payment of employee: Rs " << payrate * hr << endl;
    }
};
class Manager : public Employee 
{
    protected: int salaried;
    public:
    Manager(string n, int emp, double pr, int s) : Employee(n, emp, pr), salaried(s) {}
    void pay() 
    {
        double fa, hr;
        if (salaried) 
        {
            cout << "Enter salary of Manager: ";
            cin >> fa;
            cout << "Payment of Manager: Rs " << fa << endl;
        } 
        else {
            cout << "Enter the hours worked by Manager: ";
            cin >> hr;
            cout << "Payment of Manager: Rs " << payrate * hr << endl;
        }
    }
};
class Supervisor : public Employee 
{
    protected:
    string department;
    public:
    Supervisor(string n, int emp, double pr, string d) : Employee(n, emp, pr), department(d) {}
    void pay() 
    {
        cout << "Payment of Supervisor: Rs " << payrate << endl;
    }
};
int main()
{
    string n,d;
    int id, s;
    double pr;
    int ch, f=1;
    while (f>0)
    {
        cout << "Choose from the following: \n0.Exit\n1.Employee\n2.Manager\n3.Supervisor\nEnter choice:\n";
        cin >> ch;
        Employee *ptr;
        switch (ch)
        {
        case 0: f=0;
                break;
        case 1: cout << "Enter Name, ID and Pay rate of Employee: ";
                cin >> n >> id >> pr;
                ptr = new Employee(n, id, pr);
                ptr->pay();
                delete ptr;
                break;
        case 2: cout << "Enter Name, ID, Pay rate and Salary status (1 for salaried else 0) of Manager: ";
                cin >> n >> id >> pr >> s;
                ptr= new Manager(n, id, pr, s);
                ptr->pay();
                delete ptr;
                break;
        case 3: cout << "Enter Name, ID, Salary and Department of Supervisor: ";
                cin >> n >> id >> pr >> d;
                ptr= new Supervisor(n, id, pr, d);
                ptr->pay();
                delete ptr;
                break;
        default: cout << "Invalid choice, choose again!\n";
        }
    }
   return 0; 
}