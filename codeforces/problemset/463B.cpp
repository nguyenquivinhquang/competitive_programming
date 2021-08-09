#include <bits/stdc++.h>
#define maxn 100001
using namespace std;
int n, a[maxn], cost = 0, energy = 0;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    cost = a[1];
    for (int i = 2; i <= n; i++)
    {
        energy += (a[i - 1] - a[i]);
        if (energy < 0)
        {
            cost -= energy;
            energy = 0;
        }
    }
    cout << cost << endl;
}