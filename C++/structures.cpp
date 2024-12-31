#include <iostream>
#include <string.h>
using namespace std;
struct student
{
    char name[100];
    int roll;
    char branch[100];
    int marks[3];
    int total;
};
void ranklist (student s[],int n)
{
    int i,j;
    student temp;
    for (i=0;i<n;i++)
    {
        for (j=i+1;j<n;j++)
        {
            if (s[i].total<s[j].total)
            {
                temp=s[i];
                s[i]=s[j];
                s[j]=temp;
            }
        }
    }
    cout << "Ranklist\n";
    for (j=0;j<n;j++)
    {
        cout << j+1 << ". " << s[j].name << "(Roll No: " << s[j].roll 
        << ", Branch: " << s[j].branch << ", Total Marks: " << s[j].total << ")\n";
    }
}
void namelist (student s[], int n)
{
    int i,j;
    student a;
    for (i=0;i<n;i++)
    {
        for (j=i+1;j<n;j++)
        {
            if (strcmp(s[i].name,s[j].name)>0)
            {
                a=s[i];
                s[i]=s[j];
                s[j]=a;
            }
        }
    }
    cout << "Namelist\n";
    for (i=0;i<n;i++)
    {
        cout << i+1 << ". " << s[i].name << "(Roll No: " << s[i].roll 
        << ", Branch: " << s[i].branch << ", Total Marks: "<< s[i].total << ")\n";
    }
}
int main()
{
    int i,n,j,d,c;
    struct student s[100];
    cout << "Enter the number of students:\n";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cout << "\nEnter data for Student " << i+1;
        cout << "\nEnter Name: ";
        cin >> s[i].name;
        cout << "Enter Roll no: ";
        cin >> s[i].roll;
        cout << "Enter Branch: ";
        cin >> s[i].branch;
        s[i].total=0;
        for (j=0;j<3;j++)
        {
            cout << "Enter the marks for subject " << j+1 << ":";
            cin >> s[i].marks[j];
            s[i].total = s[i].total + s[i].marks[j];
        }
        cout << "The total marks of " << s[i].name << " is " << s[i].total;
    }
    d=1;
    while (d>0)
    {
        cout << "\nMenu:\n0.Exit\n1.Ranklist\n2.Namelist\nChoose:";
        cin >> c;
        switch (c)
        {
            case 0: d=0;
                    break;
            case 1: ranklist (s, n);
                    break;
            case 2: namelist (s, n);
                    break;
            default : cout << "Invalid option,choose again!";
        }
    }
    return 0;
}
