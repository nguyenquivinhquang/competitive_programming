#include <bits/stdc++.h>
#define maxn 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define inputfile freopen(input.txt, r, stdin)
#define outputfile freopen(out.txt, w, stdout)
using namespace std;
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        ll a, b, n, m;
        cin >> a >> b >> n >> m;
        bool check = true;
        if (a + b < n + m)
        {
            check = false;
        }
        while ((n > 0 || m > 0) && check == true)
        {
            check = false;
            if (a == b)
            {
                ll t = min(m, n);
                if (n == 0)
                    t = m;
                if (m == 0)
                    t = n;
                a -= t;
                b -= t;
                n -= t, m -= t;
                check = true;
            }
            else if (a > b)
            {
                if (n > 0)
                {
                    ll t = min(a - b, n);
                    a -= t, n -= t;
                    check = true;
                    if (t == 0)
                        check = false;
                }
                else
                {
                    ll t = min(b, m);
                    b -= t, m -= t;
                    if (t == 0)
                        check = false;
                }
            }
            else
            {
                if (n > 0)
                {
                    ll t = min(-a + b, n);
                    b -= t, n -= t;
                    check = true;
                    if (t == 0)
                        check = false;
                }
                else
                {
                    ll t = min(a, m);
                    a -= t, m -= t;
                    check = true;
                    if (t == 0)
                        check = false;
                }
            }
        }
        if (n <= 0 && m <= 0)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}