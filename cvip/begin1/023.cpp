#pragma once
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int main()
{
    cout<<fixed<<setprecision(5);
    int t;
    cin>>t;
    double x;
    for (int i=1;i<=t;i++){
        cin>>x;
        double resc=1;
        double resl=1;
        double kq;
        resc=(x-2)*(x-4)*(x-8)*(x-16)*(x-32)*(x-64);
        resl=(x-1)*(x-3)*(x-7)*(x-15)*(x-31)*(x-63);

        cout<<resc/resl<<endl;
    }
    return 0;
}