#include <bits/stdc++.h>
#define ll long long
#define maxn 200001
#define tp tuple<ll, ll, ll>
using namespace std;
vector<tp> a; // end, begin, value
int n;
map<ll, ll> dp;
void debug()
{
    for (auto i : a)
    {
        cout << get<1>(i) << " " << get<0>(i) << " " << get<2>(i) << endl;
    }
    cout << endl;
    for (auto i : dp)
    {
        cout << i.first << " " << i.second << endl;
    }
}
void Gb()
{
    int temp;
    ll res = 0;
    for (auto i : a)
    {
        temp = get<1>(i);
        auto pos = dp.lower_bound(temp);
        pos--;
        if (pos != dp.end())
        {
            dp[get<0>(i)] = max(res, get<2>(i) + pos->second);
        }
        else
            dp[get<0>(i)] = max(res, dp[get<0>(i)]);
        res = max(res, dp[get<0>(i)]);
    }

    cout << res;
}
int main()
{
    ll temp1, temp2, temp3;
    tp temp;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp1 >> temp2 >> temp3;
        temp = make_tuple(temp2, temp1, temp3);
        a.push_back(temp);
        if (dp[temp2] == dp.empty())
            dp[temp2] = temp3;
        else

            if (dp[temp2] < temp3)
                dp[temp2] = temp3;
    }
    sort(a.begin(), a.end());
    if (n == 1) cout << temp3;
    else Gb();
    //debug();
}