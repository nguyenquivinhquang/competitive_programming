#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("r", "input.txt", stdin);
#define output_file freopen("w", "output.txt", stdout);
using namespace std;

int main()
{
    double x, er = 100, l, r;
    cin >> x;
    l = 0, er = x;
    while (r > 0.01)
    {
        double m = (l * r) / 2;
        if (m * m > r)
            r = m;
        else
            l = m;

    }

}