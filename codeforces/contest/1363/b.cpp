#include <bits/stdc++.h>
#define maxn 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define inputfile freopen(input.txt, r, stdin)
#define outputfile freopen(out.txt, w, stdout)
using namespace std;
void solve()
{

    string a;
    cin >> a;
    int zero = 0, one = 0, done = 0, dzer = 0, res = 1001;
    for (int i = 0; i < a.length(); ++i)
    {
        if (a[i] == '0')
            zero++;
        else
            one++;
    }
    for (int i = 0; i < a.length(); ++i)
    {
        if (a[i] == '0')
            dzer++;
        else
            done++;
        if (done + zero - dzer < res)
            res = done + zero - dzer;
        if (dzer + one - done < res)
            res = dzer + one - done;
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