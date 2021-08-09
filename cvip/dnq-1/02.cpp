#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll answer(ll x, ll y)
{
    ll cs, b, b_plus, b_minus;
    for (double i = 40; i > 1; i--)
    {
        cs = pow(y, 1 / i);
        b = pow(cs, i);
        b_plus = pow(cs + 1, i);
        b_minus = pow(cs - 1, i);

        if (b >= x && b <= y)
            return i;
        if (b_minus >= x && b_minus <= y)
            return i;
        if (b_plus >= x && b_plus <= y)
            return i;
    }
    return 1;
}
int main()
{
    ofstream write("debug_02.txt");
    int n;
    cin >> n;
    ll x, y;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        cout << "Case #" << i << ": " << answer(x, y) << '\n';
    }
}