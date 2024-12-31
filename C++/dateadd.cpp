#include <iostream>
using namespace std;
class Date 
{
    private:
    int year,month,day,days;
    public :
    Date (int d,int m, int y) : day (d),month (m),year (y){}
    int check()
    {
        if (year < 1 || month < 1 || month > 12 || day < 1 || day > 31)
        return 0;
        if ((month==4 || month==6 || month==9 || month==11) && day > 30)
        return 0;
        else if (month==2)
        {
            if ((year%4==0 && year%100!=0) || year%400==0)
            {
                if (day>29)
                return 0;
            }
            else if (day>28)
            return 0; 
        }
        return 1;
    }
    Date operator+(int days)
    {
        Date D1= *this;
        if (check()==1)
        {
            D1.day = D1.day + days;
            while (D1.day > 31 || (D1.month == 4 || D1.month == 6 || D1.month == 9 || D1.month == 11) && D1.day > 30 ||
            (D1.month == 2 && ((D1.year % 4 == 0 && D1.year % 100 != 0) || D1.year % 400 == 0) && D1.day > 29) ||
            (D1.month == 2 && !((D1.year % 4 == 0 && D1.year % 100 != 0) || D1.year % 400 == 0) && D1.day > 28))
            {
                if (D1.month == 2)
                {
                    if ((D1.year % 4 == 0 && D1.year % 100 != 0) || D1.year % 400 == 0) 
                    D1.day = D1.day - 29;
                    else
                    D1.day = D1.day - 28;
                } 
                else if (D1.month == 4 || D1.month == 6 || D1.month == 9 || D1.month == 11)
                D1.day = D1.day - 30;
                else
                D1.day = D1.day - 31;
                D1.month++;
                if (D1.month > 12) 
                {
                    D1.month = 1;
                    D1.year++;
                }
            }
            cout << "Next Date:" << D1.day << "-" << D1.month << "-" << D1.year;
        }
        else cout << "Invalid Date.";
    }
};
int main ()
{
    int d,m,y,days;
    cout << "Enter the Day:";
    cin >> d;
    cout << "Enter the Month:";
    cin>>m;
    cout << "Enter the Year:";
    cin >>y;
    Date date(d,m,y);
    cout << "Enter the number of days to be added: ";
    cin >> days;
    date+days;
    return 0;
}