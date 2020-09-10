#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int,int>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
#define reset(a,val) memset(a,val,sizeof(a));
#define modulo int(1e9+7)
#define endl '\n'
using namespace std;
void solve()
{
    ll a[N], n, fee = 0, inc = 0, dec = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i >= 1; i--)
    {
        if (a[i] == 0)
            continue;
        if (a[i] > 0)
        {
            int m = min(a[i], dec);
            a[i] -= m, dec -= m;
            if (a[i] > 0)
            {
                fee += a[i];
                inc += a[i];
            }
        }
        else
        {
            int m = min(-a[i], inc);
            a[i] += m, inc -= m;
            if (a[i] < 0)
                dec += -a[i];
        }
    }
    cout << fee << endl;
}
int main()
{

    int testcase;
    cin >> testcase;
    while(testcase--)
    {
        solve();
    }
}