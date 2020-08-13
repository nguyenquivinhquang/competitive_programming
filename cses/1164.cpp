#include <bits/stdc++.h>
#define maxn 200001
using namespace std;
set<int> arrival;
map<int, multiset<pair<int, int>>> a;
int result[maxn];
int n, step = 0;
int main()
{
    int x, y;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        arrival.insert(x);
        a[x].insert({y, i});
    }
    for (auto i : arrival)
    {
        for (auto j : a[i])
        {
            int arri = i, depart = j.first;
            step++;
            result[j.second] = step;
            while (1 > 0)
            {
                auto find = arrival.upper_bound(depart);
                if (find == arrival.end() || a[*find].size() == 0)
                    break;
                pair<int, int> temp = *(a[*find].begin());
                arri = *find, depart = temp.first;
                result[temp.second] = step;
                a[*find].erase(a[*find].begin());
                if (a[*find].size() == 0)
                    arrival.erase(find);
            }
        }
    }
    cout << step << endl;
    for (int i = 1; i <= n; i++)
        cout << result[i] << " ";
}