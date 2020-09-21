#include <bits/stdc++.h>
#define N 100
#define Quyen "Cute"
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(a, val) memset(a, val, sizeof(a));
#define modulo int(1e9 + 7)
#define endl '\n'
using namespace std;
int convert(string x)
{
    int t = 0;
    for (int i = 0; i < x.length(); i++)
        t = t * 10 + x[i] - '0';
    return t;
}
int main()
{
    ll a, b, c;
    string x;
    cin >> x;
    a = convert(x);
    cin >> x >> x;
    b = convert(x);
    cin >> x >> x;
    c = convert(x);

    if (a + b == c)
        cout << "YES";
    else
        cout << "NO";
}