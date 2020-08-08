#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
vector<int> prefix_function(string s)
{
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
void solve()
{
    string a, b;
    cin >> a >> b;
    a = b + "$" + a;
    vector<int> res = prefix_function(a);
    vector<int> kq;
    for (int i = 0; i < res.size(); i++)
        if (res[i] == b.size())
            kq.push_back(i - 2 * b.size() + 1);
    if (kq.size() == 0)
        cout << "Not Found" << endl << endl;
    else
    {
        cout << kq.size() << endl;
        for (auto v : kq)
            cout << v << " ";
        cout << endl
             << endl;
    }
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
        solve();
}