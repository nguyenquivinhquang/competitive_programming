#include <bits/stdc++.h>
#define ll long long
#define pp pair<int, int>
using namespace std;
vector<pp> a;
ll n, x, temp;
int main()
{
    cin >> n >> x;
    a.push_back({0, 0});
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        a.push_back({temp, i});
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
        {
            temp = (a[i].first + a[j].first);
            if (temp > x)
                break;
            pp c = {x - temp, 0};
            auto find = lower_bound(a.begin() + i + 1, a.end(), c);
            c = *find;
            if (find != a.end() && c.first == x - temp)
            {
                cout << a[i].second << " " << a[j].second << " " << c.second;
                return 0;
            }
        }
    cout << "IMPOSSIBLE";
}