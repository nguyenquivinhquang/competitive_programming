#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int main()
{
    //cout<<setprecision(5);
    int n=0;
    int a=0;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a;
        int x=a/10;
        int y=a%10;
        if (((x*x*x)+(y*y*y))==a*a) 
            cout <<"equal "<< endl; 
        else cout <<"not equal"<<endl;
    }
    return 0;
}