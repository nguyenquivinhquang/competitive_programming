#include <iostream>
#include <iomanip>
#include<math.h>
using namespace std;

int main()
{
    int n;
    double a, b, c;
    cout<<fixed;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a >> b;
        if (a <= 0 || b <= 0 || a <= b)
            cout << "0.00000 " << endl;
        else
        {
            c = sqrt(a * a - b * b);
            c=(b+c-a)/2;
            cout<<setprecision(5)<<c<<endl;
        }
    }
    return 0;
}