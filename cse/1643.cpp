#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n, temp, sum = -1e9, res= -1e9;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        if (sum + temp < temp) sum = temp;
        else sum += temp;
    	res =max(sum, res);
    }
    cout << res;
}