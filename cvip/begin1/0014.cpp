#include<iostream>
#include<iomanip>
#include <math.h>

using namespace std;
double cal(double x){
    return -4*pow(x,3)+3*x*x-2*x+1;
}
int main()
{
    int n; double x;
    cin>>n;
    cout<<fixed;
    for (int i=1;i<=n;i++){
        cin>>x;
        cout<<setprecision(5)<<cal(x)<<endl;

    }
    
    return 0;
}