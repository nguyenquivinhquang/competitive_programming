#include <bits/stdc++.h>
#define N 100005
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("input.txt", "r", stdin);
#define output_file freopen("output.txt", "w", stdout);
using namespace std;

int main()
{
    double a[N];
    output_file;
    double pi = 2 * acos(0.0);
    int testcase;
    for (int i = 1; i <= 100000; i++)
        a[i] = sin(i);
    int dp[N];
    reset(dp, 0);
    for (int i = 2; i <= 100000; i++)
    {
        if (a[i] > a[i - 1])
        {
            dp[i] = dp[i - 1] + 1;
            cout << i << ": " << fixed << setprecision(5) << a[i] << endl;
        }
        else
            dp[i] = 1;
    }
    // for (int i = 1; i <= 100000; i++)
    //     cout << dp[i] << endl;
}