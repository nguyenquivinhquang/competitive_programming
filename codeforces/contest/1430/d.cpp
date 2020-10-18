#include <bits/stdc++.h>
#define N 200005
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
int n;
string s;
void solve()
{
    cin >> n >> s;

    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        if (i == 0 || s[i - 1] != s[i])
        {
            v.push_back(1);
        }
        else
        {
            v.back()++;
        }
    }

    int i = 0, j = 0, res = 0;
    while (i < v.size())
    {
        res++;
        j = max(j, i);
        while (j < v.size() && v[j] == 1)
            j++;

        if (j < v.size())
            v[j]--;
        else
        {
            i++;
        }

        i++;
    }

    cout << res << endl;
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
}