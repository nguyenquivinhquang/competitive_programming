#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll testcase, n, m, l, r;
    cin >> testcase;
    while (testcase--)
    {
        vector<pair<ll, ll>> x;
        cin >> n >> l >> m;
        x.push_back({l, l});
        bool check = false;
        for (int i = 1; i <= m; i++)
        {
            cin >> l >> r;
            check = false;
            for (auto v : x)
            {
                if (v.first <= l && l <= v.second)
                    check = true;
                if (v.first <= r && r <= v.second)
                    check = true;
                if (l <= v.first && v.first <= r)
                    check = true;
                if (l <= v.second && v.second <= r)
                    check = true;
            }
            if (check == true)
                x.push_back({l, r});
        }
        sort(x.begin(), x.end());
        map<ll, ll> res;
        for (auto v : x)
            res[v.first] = v.second;
        ll d = 0, kq = 0; 
        for (auto v : res)
        {
            if (v.second < d)
                continue;
            if (d < v.first)
                kq += v.second - v.first + 1, d = v.second;
            else
            {
                kq += v.second - d;
                d = v.second;
            }
        }
        cout << kq << endl;
    }
}