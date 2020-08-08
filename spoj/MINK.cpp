#include <bits/stdc++.h>
#define maxn 100000
#define ll long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);

using namespace std;
int n, k, a[maxn];
deque<int> d;
void push(int x)
{
    while (!d.empty() && d.back() > x)
        d.pop_back();
    d.push_back(x);
}
void solve()
{
    d.clear();
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (i < k)
            push(a[i]);
    }
    for (int i = k; i <= n; i++)
    {
        push(a[i]);
        cout << d.front() << " ";
        if (a[i - k + 1] == d.front())
            d.pop_front();
    }
    cout << endl;
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