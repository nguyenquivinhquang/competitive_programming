#pragma once
#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

int main()
{
    int n, k;
    int a[1001];
    cin>>n;
    for (int i = 1; i<= 1000; i++)
    {
        a[i] =(a[i-1]+i*i)%10;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> k;
        cout <<a[k]<<endl;
    }
    return 0;
}