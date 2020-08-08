#include <bits/stdc++.h>

using namespace std;

int main()
{
    int testcase;
    cin >>testcase;
    while (testcase--)
    {
        long long n,k;
        cin >> n >> k;
        long long temp = (k-1)/(n-1);
        cout << temp + k << endl;
    }
    
}