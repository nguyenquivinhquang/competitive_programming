
#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
using namespace std;
const double e = 2.718281828459045235360287471352662497757247093699959574966;
double ttd(double a)
{
    if (a < 0)
        return a * -1.00000;
    else
        return a;
}
double pt_a_a(int x, int y, int z)
{
    double a = (3 + exp(y - 1));
    a = a / (1 + x * x * ttd(y - tan(z)));
    return a;
}
double pt_a_b(int x, int y, int z)
{
    double a = 1 + ttd(y - x) + pow(y - x, 2) / 2 + pow(y - x, 3) / 3;
    return a;
}

double pt_b_a(double x, double y, double z)
{
    double a = (y - sqrt(ttd(x))) * (x - y / (z + pow(x, 1 / 2)));
    if (a==0) return 0.00000;
    a = log(ttd(a));
    return a;
}

double pt_b_b(double x, double y, double z)
{
    double a = x - (x * x / 6) + (pow(x, 5)) / 120;
    return a;
}
int main()
{
    cout << fixed;
    int n; int x,y,z;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>x>>y>>z;
        cout << setprecision(5) << pt_a_a(x,y,z)<<" "<<pt_a_b(x,y,z)<<" "<<pt_b_a(x,y,z)<<" " <<pt_b_b(x,y,z)<<endl;
   
    }
    
        //cout<<setprecision(5);
    return 0;
}