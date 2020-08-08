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
        string x;
        map<ll, int> a;
        cin >> x;
        ll minimun = 1e9, sum = 0, res = 0;
        for (int i = 0; i < x.length(); i++)
        {
            if (x[i] == '+')
                sum += 1;
            else
                sum--;
            if (sum < 0)
            {
                ll t = abs(sum) - 1;
                if (a[t] == 0)
                    a[t] = i + 1;
            }
        }
        a[-1] = 0;
        for (auto v : a)
            res += v.second;
        cout << res + x.length() << endl;
    }
}