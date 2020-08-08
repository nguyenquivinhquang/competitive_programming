#include <bits/stdc++.h>
#define maxn 200001
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
        ll n, a[maxn], m = 0, sum = 0, res = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i % 2 == 0)
                res += a[i];
        }
        for (int i = 1; i < n; i += 2)
        {
            sum += a[i] - a[i - 1];
            m = max(m, sum);
            if (sum < 0)
                sum = 0;
        }
        sum = 0;
        for (int i = 1; i < n - 1; i += 2)
        {
            sum += a[i] - a[i + 1];
            m = max(sum, m);
            if (sum < 0)
                sum = 0;
        }
        cout << res + m << endl;
    }
}