#include <bits/stdc++.h>

using namespace std;
multiset<pair<int, int>> a,t;
int main()
{
    int n, x, y, k, c = 0;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        a.insert({y,x});
        if (i < k)
            t.insert({0, 0});
    }
    for (auto z : a)
    {
        auto pos = t.lower_bound({z.second, z.first});
        if (pos == t.begin())
            continue;
        c++;
        pos--;
        t.erase(pos);
        t.insert(z);
    }
    cout << c;
}