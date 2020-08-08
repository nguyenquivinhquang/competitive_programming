#pragma once
#include <iostream>
#include <iomanip>
#include <string.h>
using namespace std;
const int  maxn=1000001;
int main()
{
    cout << fixed << setprecision(5);
    int n;
    cin >> n;
    bool check[maxn]; int giao[maxn];
    memset(check, maxn, false);
    for (int i=1;i<=maxn;i++) giao[i]=0;
    int t;
    for (int i= 1; i <= n; i++)
    {
        cin >> t;
        check[t] = true;
        giao[t]=1;
    }
    for (int i= 1; i <= n; i++)
    {
        cin >> t;
        check[t] = true;
        giao[t]++;
    }
    cout<<"The intersection of 2 sets: ";
    for (int i=1;i<=maxn;i++){
        if (giao[i]>1) cout<<i<<" ";
    }
    
    cout<<endl;
    cout<<"The union of 2 sets: ";
    for (int i=1;i<=maxn;i++)
    {
        if (check[i]==true) cout<<i<<" ";
    }
    return 0;
}