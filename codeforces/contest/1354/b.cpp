#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll t;
int main()
{

    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll l1 = 1e8, l2 = 1e8, l3 = 1e8, ans = 1e8;
        for (ll i = 0; i < s.length(); i++)
        {
            if (s[i] == '1')
                l1 = i;
            else if (s[i] == '2')
                l2 = i;
            else if (s[i] == '3')
                l3 = i;
            ans = min(ans, max(l1, max(l2, l3)) - min(l1, min(l2, l3)));
        }
        if (ans > s.length())
            cout << 0 << endl;
        else
            cout << ans + 1 << endl;
    }
    return 0;
}