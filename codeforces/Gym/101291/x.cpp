//Three Square
#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define t1 first
#define t2 second
using namespace std;
int main()
{
    int a, b, c, s = 0;
    bool check = false;
    pp x, y, z;
    cin >> x.first >> x.second;
    cin >> y.first >> y.second;
    cin >> z.first >> z.second;
    s = x.first + x.second + y.first + y.second + z.first + z.second;
    for (int i = 1; i <= 2; i++)
        for (int j = 1; j <= 2; j++)
            for (int k = 1; k <= 2; k++)
            {
                if (i == 1)
                    a = x.first;
                else
                    a = x.second;
                if (j == 1)
                    b = y.first;
                else
                    b = y.second;
                if (k == 1)
                    c = z.first;
                else
                    c = z.second;
                if (a + b + c == s - a - b - c)
                    check = true;
            }
    if (check == true)
        cout << "YES";
    else
        cout << "NO";
}