#pragma once
#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;

int main()
{
    cout<<fixed<<setprecision(5);
    int a[10000];
    a[0]=1;
    for (int i=1;i<=10000;i++){
        a[i]=a[i-1]*i+1;
    }
    int t,x;
    cin>>t;
    for(int i=1;i<=t;i++){
       cin>>x;
       cout<<a[x]<<endl; 
    }
    return 0;
}