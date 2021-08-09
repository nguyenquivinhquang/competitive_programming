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
int c[N], trace[N];
void prepeocess()
{

    for (int i = 0; i <= 999999; i++)
    {
        vector<int> a(4, 0), b(4, 0);
        int m = i;
        for (int j = 1; j <= 3; j++)
        {
            a[i] = m % 10;
            m /= 10;
        }
        for (int j = 1; j <= 3; j++)
        {
            b[i] = m % 10;
            m /= 10;
        }
        int happy = abs((a[1] + a[2] + a[3] - b[1] - b[2] - b[3]));
    }
}
void solve()
{
}
int main()
{
    reset(trace, 0);
    reset(c, 0);
    int testcase;
}