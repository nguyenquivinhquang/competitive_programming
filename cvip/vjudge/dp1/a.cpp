#include <bits/stdc++.h>
#define maxn 20001
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
using namespace std;
int main()
{
    ll testcase, n, a[maxn], sum, res;
    pp pos_res, pos_curr;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++)
    {
        cin >> n;
        for (int i = 1; i < n; i++)
            cin >> a[i];
        pos_curr = make_pair(1, 2);
        pos_res = pos_curr;
        sum = a[1], res = a[1];
        for (int i = 2; i < n; i++)
        {
            sum += a[i];
            if (sum < a[i])
            {
                pos_curr = make_pair(i, i + 1);
                sum = a[i];
            }
            if (sum > res)
            {
                res = sum;
                pos_res = make_pair(pos_curr.first, i + 1);
            }
            else if (sum == res && i - pos_curr.first > pos_res.second - pos_res.first)
            {
                pos_res.first = pos_curr.first;
                pos_res.second = i + 1;
            }
        }

        if (res > 0)
        {
            cout << "The nicest part of route " << t << " is between stops " << pos_res.first << " and " << pos_res.second << endl;
        }
        else
            cout << "Route " << t << " has no nice parts" << endl;
    }
}