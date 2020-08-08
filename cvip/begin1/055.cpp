#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int a[100], b[100], c[100];
    int nos = 0; // numbers of solutuion;
    int n;
    cin >> n;
    int lim = pow(n, 1.0 / 3.0) + 1;
    for (int x = 0; x <= lim; x++)
    {
        for (int y = 0; y <= lim; y++)
        {
            float z=0.00000; 
            z = pow(n - x * x * x - y * y * y, 1.0 / 3.0);
            long  kq = z;
            if ((x*x*x+y*y*y+kq*kq*kq) == n)
            {
                cout<<"YES"<<endl;
                cout<<x<<" "<<y<<" "<<kq<<endl;
                return 0;
            }
        }
    }
   cout<<"NO"<<endl;
}