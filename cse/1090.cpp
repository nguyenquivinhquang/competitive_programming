#include <bits/stdc++.h>

using namespace std;

int main()
{
    multiset<int, greater<int>> a;
    int x, n, temp;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        a.insert(temp);
    }
    int res = 0;
    auto i = a.begin();
    while (i != a.end())
    {
        int t = x - *i;
        a.erase(a.begin());
        auto c = a.lower_bound(t);
        if (c != a.end())
            a.erase(a.find(*c));
        res++;
        i = a.begin();
    }
    cout << res << endl;
    ca1
}