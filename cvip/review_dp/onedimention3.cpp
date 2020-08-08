//1. 3. Explosion Hazards 
#include <bits/stdc++.h>
#define maxn 101
#define ll long long
using namespace std;

int main()
{
    //1 is dangerous, 0 is non-hazardous
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