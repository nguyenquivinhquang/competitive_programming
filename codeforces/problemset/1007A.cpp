#include <bits/stdc++.h>

using namespace std;
multiset<int> a;
vector<int> b;
int n, res = 0;
int main()
{
    int temp;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        a.insert(temp);
        b.push_back(temp);
    }
    sort(b.begin(), b.end());
    bool condition = true;
    for (auto c : b)
    {
        auto find = a.upper_bound(c);
        if (find == a.end())
        {
            cout << res;
            return 0;
        }
        res++;
        a.erase(find);
        if (a.size() == 0)
        {
            cout << res;
            return 0;
        }
        if (a.find(c) != a.end())
            a.erase(a.find(c));
    }
}