#include<iostream>
#include<cstring>
using namespace std;
class Student
{
    public:
    struct StudDetails
    {
        char name[100];
        int age;
        int regno;
        float gpa;
        float marks;
    } sd1[100];  
    int num;
    virtual void read() = 0;
    virtual void display() = 0;
    virtual void sort() = 0;
};
class MtechStud : public Student
{
    public:
    void read() override
    {
        cout << "Enter the number of Students:";
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            cout << "Enter the Name, Age, Register number and GPA (out of 10) of Student " << i+1 << ":";
            cin >> sd1[i].name >> sd1[i].age >> sd1[i].regno >> sd1[i].gpa;
        }
    }
    void sort() override
    {
        struct StudDetails swap;
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < num - i - 1; j++)
            {
                if (sd1[j].gpa > sd1[j + 1].gpa)
                {
                    swap = sd1[j];
                    sd1[j] = sd1[j + 1];
                    sd1[j + 1] = swap;
                }
                else if (sd1[j].gpa == sd1[j + 1].gpa)
                {
                    if (strcmp(sd1[j].name, sd1[j + 1].name) > 0)
                    {
                        swap = sd1[j];
                        sd1[j] = sd1[j + 1];
                        sd1[j + 1] = swap;
                    }
                }
            }
        }
    }
    void display() override
    {
        cout << "Name\t\t\tAge\tRegister no.\tGPA(out of 10)\n";
        for (int i = 0; i < num; i++)
        {
            cout << sd1[i].name << "\t\t\t" << sd1[i].age << "\t" << sd1[i].regno << "\t\t" << sd1[i].gpa << "\n";
        }
    }
};
class BtechStud : public Student
{
    public:
    void read() override
    {
        cout << "Enter the number of Students:";
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            cout << "Enter the Name, Age, Register number and Total marks (out of 600) of Student " << i+1 << ":";
            cin >> sd1[i].name >> sd1[i].age >> sd1[i].regno >> sd1[i].marks;
        }
    }
    void sort() override
    {
        struct StudDetails swap;
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < num - 1 - i; j++)
            {
                if (sd1[j].marks > sd1[j + 1].marks)
                {
                    swap = sd1[j];
                    sd1[j] = sd1[j + 1];
                    sd1[j + 1] = swap;
                }
            }
        }
    }
    void display() override
    {
        cout << "Name\t\t\tAge\tRegister no.\tTotal Marks(out of 600)\n";
        for (int i = 0; i < num; i++)
        {
            cout << sd1[i].name << "\t\t\t" << sd1[i].age << "\t" << sd1[i].regno << "\t\t" << sd1[i].marks << "\n";
        }
    }
};
int main()
{
    int choice, f=1;
    while (f>0)
    {
        Student *ptr;
        MtechStud ms1;
        BtechStud bs1;
        cout << "\nChoose an option:\n1. MTech Student\n2. BTech Student\n3. Exit\nChoice:\n";
        cin >> choice;
        switch (choice)
        {
            case 1:
                ptr = &ms1;
                ms1.read();
                cout << "\nDisplaying entered details:\n";
                ptr->display();
                cout << "\nSorted List:\n";
                ptr->sort();
                ptr->display();
                break;
            case 2:
                ptr = &bs1;
                bs1.read();
                cout << "Displaying entered details:\n";
                ptr->display();
                cout << "\nSorted List:\n";
                ptr->sort();
                ptr->display();
                break;
            case 3:
                f=0;
                break;
            default: cout << "Invalid choice, choose again!\n";
        }
    }
    return 0;
}