#include <bits/stdc++.h>

using namespace std;
bool cmp(int x, int y)
{
    return x > y;
}
int main()
{
    int n, m, price[100], count[100];
    string temp;
    map<string, int> fruit;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> price[i];
    for (int i = 1; i <= m; i++)
    {
        cin >> temp;
        fruit[temp]++;
    }
    int i = 0;
    for (auto v : fruit)
    {
        count[++i] = v.second;
    }
    m = i;
    sort(count + 1, count + 1 + i, cmp);
    sort(price + 1, price + 1 + n);
    long long res = 0;
    for (int i = 1; i <= m; i++)
        res += count[i] * price[i];
    cout << res << " ";
    res = 0;
    sort(price + 1, price + 1 + n, cmp);
    for (int i = 1; i <= m; i++)
        res += count[i] * price[i];
    cout << res;
}