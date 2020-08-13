#include <bits/stdc++.h>
#define ll long long
using namespace std;
vector<pair<ll, ll>> a;
ll n, x, y, ti = 0, reward = 0;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {  
        cin >> x >> y;
        a.push_back({x, y});
    }
    sort(a.begin(), a.end());
    for (auto i : a)
    {
        ti+=i.first;
        reward+=i.second-ti;
    }
    cout << reward;
}