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
    ll testcase, a, b, c;
    cin >> testcase;
    while (testcase--)
    {
        cin >> a >> b >> c;
        if (a >= c)
            cout << "-1 ";
        else
            cout << "1 ";
        if (a * b > c)
            cout << b << endl;
        else
            cout << -1 << endl;
    }
}