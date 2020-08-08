#include <bits/stdc++.h>
#define maxn 100001
#define ll long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        ll arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        ll maxi = arr[0];

        ll maxi_diff = 0;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] < maxi)
            {
                maxi_diff = max(maxi_diff, maxi - arr[i]);
            }
            else
            {
                maxi = arr[i];
            }
        }

        if (maxi_diff == 0)
        {
            cout << 0 << endl;
            continue;
        }
        cout << int(log2(maxi_diff)) + 1 << endl;
    }
}