#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    int n; double a; int res=0;
    cout<<fixed<<setprecision(1);
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a;
        if (a!=0) cout<<a<<endl; else res++;
    }
    for (int i=1;i<=res;i++)
        cout<<"0"<<endl;
}