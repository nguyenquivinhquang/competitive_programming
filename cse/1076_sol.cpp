#include <bits/stdc++.h>
using namespace std;
int n, k;

int main()
{
    cin >> n >> k;
    vector<int> v(n);
    for (auto &x : v)
        cin >> x;
    multiset<int> ms(v.begin(), v.begin() + k);
    auto it = next(ms.begin(), (k + 1) / 2 - 1);
    cout << *it;
    for (int i = k; i < n; i++)
    {
        ms.insert(v[i]);
        if (v[i] < *it)
            it--;

        if (v[i - k] <= *it)
            it++;
        ms.erase(ms.find(v[i - k]));

        cout << " " << *it;
    }
}