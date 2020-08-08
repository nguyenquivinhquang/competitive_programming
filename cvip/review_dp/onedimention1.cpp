//1. Long sequence of 0 and 1
#include <bits/stdc++.h>
#define maxn 101
#define ll long long
using namespace std;

int main()
{
    ll n, total[maxn], number_of_0[maxn];
    cin >> n;
    total[1] = 2, number_of_0[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        number_of_0[i] = total[i - 1];
        total[i] = total[i - 1] + number_of_0[i - 1];
    }
    cout << total[n];
}