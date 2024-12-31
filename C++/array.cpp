#include <iostream>
using namespace std;
class Array
{
    public: int a[50];
            int n;
            static float sum;
    void data ()
    {
        float avg,sum;
        cout << "Enter the size of the array:";
        cin >> n;
        cout << "Enter the elements of the Array:";
        for (int i=0; i<n;i++)
        {
            cin >> a[i];
            sum=sum+a[i];
        }
        avg = sum/n;
        cout << "The sum and average of the Array is " << sum << " and " << avg << endl;
    }
    static float average (const int *a,int n)
    {
        int i;
        for (i=0;i<n;i++)
        sum =sum + a[i];
        return sum/n;
    }
    void mul (int z)
    {
        float c=0,d;
        int i;
        cout << "The Array now is: ";
        for (i=0;i<n;i++)
        {
            a[i]=a[i]*z;
            c=c+a[i];
            cout << a[i] << " ";
        }
        d=c/n;
        cout << "\nThe sum and average of Array after multiplication by " << z << " is " << c 
        << " and " << d << endl;
    }
    Array sort (Array t1)
    {
        int temp;
        for (int i=0; i<t1.n;i++)
        {
            for (int j=0;j<t1.n-i-1;j++)
            {
                if (t1.a[j]> t1.a[j+1])
                {
                    temp=t1.a[j];
                    t1.a[j]=t1.a[j+1];
                    t1.a[j+1]=temp;
                }
            }
        }
        cout << "The sorted Array is: ";
        for (int i=0;i<t1.n;i++)
        cout << t1.a[i] << " "; 
    }
};
float Array :: sum=0;
int main ()
{
    static float avg;
    int z;
    Array o1,o2,o3;
    o1.data();
    avg = Array :: average(o1.a,o1.n);
    cout << "The average of the Array using static function is " << avg << endl;
    cout << "Enter the value of Multiplier for the Array:";
    cin >> z;
    o2=o1;
    o2.mul(z);
    avg = Array :: average(o2.a,o2.n);
    cout << "The average of the Array after multiplication using static function is " << avg << endl;
    o3.sort(o1);
    return 0;
}