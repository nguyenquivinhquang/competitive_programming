#include <iostream>
#include <math.h>
#include <iomanip>
const double pi=3.14159;
using namespace std;

int main()
{
    int t;
    double n, r;
    cin >>t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> r;
        if (n>2){
        double goc = 2*pi/n;
        double canh = sqrt(2 * r * r - 2 * r * r * cos(goc))*n;
        cout<<fixed;
        cout << setprecision(5) << canh << endl;
        } else cout<<"-1.00000"<<endl;
    }

    return 0;
}