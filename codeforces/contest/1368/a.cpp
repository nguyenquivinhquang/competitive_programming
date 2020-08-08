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
    ll a, b, n, step;
    cin >> testcase;
    while (testcase--)
    {
        cin >> a >> b >> n;
        step = 0;
        while (a <= n && b <= n)
        {
            if (a < b)
                a += b;
            else
                b += a;
            step++;
        }
        cout << step << endl;
    }
}