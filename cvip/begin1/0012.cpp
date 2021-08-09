#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int n,a,c,d;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        cin>>a>>d>>c;
        double answer;
        answer=a*(2*c+(a-1)*d)/2;
        cout <<fixed;
        cout<<setprecision(5)<<answer<<endl;
    }
    return 0;
}