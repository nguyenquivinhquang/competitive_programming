#include <bits/stdc++.h>
#define maxn 1000
using namespace std;
void Giang_bae(string x, int n)
{
    //cout << "--" << endl;
    map<pair<int, int>, int> res;
    pair<int, int> cache, temp;
    x = "t" + x;
    temp = make_pair(0, 0);
    cache.first = -1;
    int d = 1e9;
    res[temp] = 0;
    // temp.fisrt: x, temp.second=y
    for (int i = 1; i <= n; i++)
    {
        if (x[i] == 'L')
            temp.first--;
        if (x[i] == 'R')
            temp.first++;
        if (x[i] == 'U')
            temp.second++;
        if (x[i] == 'D')
            temp.second--;
        auto f = res.find(temp);
        if (f != res.end())
        {
            if (-res[temp] + i < d)
            {
                d = -res[temp] + i;
                cache.first = res[temp], cache.second = i;
            }
            res[temp] = i;
        }
        else
            res[temp] = i;

        //cout << f->second << endl;
    }
    if (cache.first == -1)
        cout << -1;
    else
        cout << cache.first + 1 << " " << cache.second;
    cout << endl;
    //ddebug
    //for (auto i = res.begin(); i != res.end(); i++)
    //    cout << i->first.first << " " << i->first.second << " " << i->second << endl;
}
int main()
{
    //freopen("D:\\c++\\cvip\\codeforces\\1296\\input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int testcase, n;
    string x;
    cin >> testcase;
    while (testcase--)
    {
        cin >> n >> x;
        //cout << n << x;
        Giang_bae(x, n);
    }
}