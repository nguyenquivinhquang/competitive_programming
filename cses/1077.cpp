#include <bits/stdc++.h>
using namespace std;
int n, k, old_m;
int main()
{
    cin >> n >> k;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    multiset<int> t(v.begin(), v.begin() + k);
    auto m = next(t.begin(), (k + 1) / 2 - 1);
    int  d = 0;
    for (int i = 0; i < k; i++)
        d += abs(*m - v[i]);
    cout << d << " ";
    old_m = *m;
    for (int i = k; i < n; i++)
    {
        t.insert(v[i]);
        if (v[i] < *m)
            m--;
        if (v[i - k] <= *m)
            m++;
        t.erase(t.find(v[i - k]));
        d += abs(v[i] - *m) - abs(v[i - k] - old_m);
        if (k % 2 == 0)
            d -= (*m - old_m);
        old_m = *m;
        cout << d << " ";
    }
}