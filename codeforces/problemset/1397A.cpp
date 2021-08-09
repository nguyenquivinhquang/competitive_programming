#include <bits/stdc++.h>
#define maxn 100
#define ll long long
#define pp pair<int,int>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
using namespace std;
void solve()
{
    map<char, int> trace;
    int n;
    string temp;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        for (int i = 0; i < temp.length(); i++)
            trace[temp[i]]++;

    }
    for (auto v : trace)
        if (v.second % n != 0)
        {
            cout << "NO" << endl;
            return;
        }
    cout << "YES" << endl;

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