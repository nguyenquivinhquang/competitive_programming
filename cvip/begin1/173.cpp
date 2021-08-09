#include <iostream>

using namespace std;

int Hoai_Thuong(double n)
{
    int count = 0;
    double x=9870;
    while (x < n)
    {
        count++;
        x=x/10.0+x;
    }
    return count;
}
int main()
{
    int n,a;
    cin>>n;
    for (int i=1;i<=n;i++)
        {
            cin>>a;
            cout<<Hoai_Thuong(a)<<endl;
        }
}