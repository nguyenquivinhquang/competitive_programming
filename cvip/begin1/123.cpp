#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<bool> trace(10000000, false);
    long n,res=0;
    cin>>n;
    while (n!=1){
        if (n%2==0) n=n/2; else n=n*3+1;
        res++;
    }

    cout<<res;
}