#include <bits/stdc++.h>
#define vv vector<int>
#define ll long long
#define pp pair<int, map<ll, ll>>
using namespace std;
map<ll, pp> so2;
ll n, x;
vector<ll> a;
multiset<pair<int, int>> id;
map<int, int> trace;
void print(pp temp, int val)
{

    {
        int sl = 0;
        for (auto i = temp.second.begin(); i != temp.second.end(); i++)
            if (i->second > 0)
            {
                if (i->first * 2 == val && trace[i->first] > 1)
                {
                    auto find = id.lower_bound({i->first, 0});
                    cout << find->second << " ";
                    id.erase(find);
                    find = id.lower_bound({i->first, 0});
                    cout << find->second << " ";
                    return;
                }
                auto find = id.lower_bound({i->first, 0});
                cout << find->second << " ";
                id.erase(find);
                sl++;
                if (sl == 2)
                    return;
            }
    }
}
int main()
{
    ll temp;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        a.push_back(temp);
        id.insert({temp, i});
        trace[temp]++;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
        {
            //auto val = so2[a[i] + a[j]];
            so2[a[i] + a[j]].first++;
            //auto temp = val.second;
            so2[a[i] + a[j]].second[a[i]] += 1;
            so2[a[i] + a[j]].second[a[j]] += 1;
        }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
        {
            temp = x - a[i] - a[j];
            if (temp <= 0)
                break;
            int t = so2[temp].first;
            if (so2[temp].second[a[i]] != 0)
                t -= 2;
            if (so2[temp].second[a[j]] != 0)
                t -= 2;
            if (t > 0)
            {
                so2[temp].second[a[i]]--;
                so2[temp].second[a[j]]--;
                trace[a[i]]--, trace[a[j]]--;
                pair<int, int> temp2 = {a[i], 0};
                auto find = id.lower_bound(temp2);
                cout << find->second << " ";
                temp2 = {a[j], 0};
                id.erase(find);
                find = id.lower_bound(temp2);
                cout << find->second << " ";
                id.erase(find);

                print(so2[temp], temp);
                return 0;
            }
        }
    cout << "IMPOSSIBLE";
}