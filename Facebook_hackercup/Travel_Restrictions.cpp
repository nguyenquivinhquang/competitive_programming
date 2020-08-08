#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define inputfile freopen(input.txt, r, stdin)
#define outputfile freopen(out.txt, w, stdout)
using namespace std;
void solve()
{
    int n, a[N][N];
    string inf, outf;
    memset(a, 0, sizeof(a));
    cin >> n;
    cin >> inf >> outf;
    for (int i = 0; i < n; i++)
    {
        if (outf[i] == 'Y')
        {
            for (int j = 0; j < n; j++)
                if (inf[j] == 'Y' && abs(i - j) == 1)
                    a[i][j] = 1;
        }

        a[i][i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (a[i][j])
                cout << "Y";
            else
                cout << "N";
        cout << endl;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int testcase;
    cin >> testcase;
    for (int i = 1; i <= testcase; i++)
    {
        cout << "Case #" << i << ": " << endl;
        solve();
    }
}