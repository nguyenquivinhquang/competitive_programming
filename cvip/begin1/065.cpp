#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
#include <string.h>
using namespace std;

int main()
{
    cout << fixed << setprecision(0);
    int max_a[9]; int min_a[9];
    for (int i=1;i<=8;i++){
        max_a[i]=0;
        min_a[i]=99999999;
    }
    int t;
    for (int i=1;i<=8;i++)
    for (int j=1;j<=8;j++){
        cin>>t;
        max_a[j]+=t;
        min_a[j]=min(min_a[j],t);
    }
    int res=1;
    for (int i=1;i<=8;i++) if (max_a[i]>max_a[res]) res=i;
    cout<<min_a[res];
    
    return 0;
}