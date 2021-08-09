#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
bool check(int x,int m)
{
    int n=x;
    int res=0;
    while (n > 0)
    {
        
        res += pow(n % 10,2);
        n = n / 10;
    }
    if (res==m) return true; else return false;
}
int main()
{
    int t;
    int n,m;
    cin >> n>>m;
    int a[1000001]; int count=0;
    for (int i=1;i<=n;i++) if (check(i,m)==true ){
        count++;
        a[count]=i;
    }
    cout <<count<<endl;
    for (int i=1;i<=count;i++){
        cout<<a[i]<<endl;
    }
    return 0;
}