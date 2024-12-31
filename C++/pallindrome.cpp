#include <iostream>
using namespace std;
int main ()
{
    int a,r,n,rev=0;
    cout <<"Enter a:";
    cin >>a;
    n=a;
    while (a != 0)
    {
        r=a%10;
        rev=rev*10 +r;
        a=a/10;
    }
    if (rev==n)
    cout <<"Pallindrome";
    else cout<< "Not Pallindrome";
    return 0;
}