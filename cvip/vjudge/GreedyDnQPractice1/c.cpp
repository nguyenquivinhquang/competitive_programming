#include <bits/stdc++.h>
#define N 100
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
set<int> a[N];
int testcase;
void solve(string &x)
{
    int pos = -1;
    bool check = true;
    vector<int> trace;
    for (int i = 0; i < x.length(); i++)
    {
        int t = x[i] - 'A';
        if (a[t].size() == 0)
        {
            check = false;
            break;
        }
        auto it = a[t].lower_bound(pos + 1);
        if (it == a[t].end())
        {
            check = false;
            break;
        }
        pos = *it;
        trace.push_back(pos);
    }
    if (check)
    {
        cout << "Matched " << *trace.begin() << " " << trace[trace.size() - 1] << endl;
    }
    else
        cout << "Not matched" << endl;
}
int main()
{
    //fastio;
    string x;
    cin >> x;
    for (int i = 0; i < x.length(); i++)
        a[x[i] - 'A'].insert(i);
    cin >> testcase;
    while (testcase--)
    {
        cin >> x;
        solve(x);
    }
}