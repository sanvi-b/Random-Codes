#include <iostream>
using namespace std;
class Date 
{
    private:
    int year,month,day;
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
    void nextdate()
    {
        if (check()==1)
        {
            day++;
            if (day>31)
            {
                day=1;
                month++;
            }
            if (month>12)
            {
                month=1;
                year++;
            }
            if (month==2 && day>29 && ((year%4==0 && year%100!=0) || year%400==0))
            {
                day=1;
                month++;
            }
            if (month==2 && day>28 && !((year%4==0 && year%100!=0) || year%400==0))
            {
                day=1;
                month++;
            }
            if ((month==4 || month==6 || month==9 || month==11) && day>30)
            {
                day=1;
                month++;
            }
            cout << "Next Date:" << day << "-" << month << "-" << year;
        }
        else cout << "Invalid Date.";
    }
};
int main ()
{
    int d,m,y;
    cout << "Enter the Day:";
    cin >> d;
    cout << "Enter the Month:";
    cin>>m;
    cout << "Enter the Year:";
    cin >>y;
    Date date(d,m,y);
    date.nextdate ();
    return 0;
}