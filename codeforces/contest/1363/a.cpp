#include <bits/stdc++.h>
#define maxn 1001
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define inputfile freopen(input.txt, r, stdin)
#define outputfile freopen(out.txt, w, stdout)
using namespace std;

int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        int n, x, dp[2], temp;
        bool check = 0;
        dp[1] = dp[0] = 0;
        cin >> n >> x;
        for (int i = 1; i <= n; ++i)
        {
            cin >> temp;
            dp[temp % 2]++;
        }
        for (int i = 1; i <= dp[1]; i += 2)
        {
            if (x - i <= dp[0] && x - i >= 0)
                check = 1;
            if (i > x)
                break;
        }
        if (check == 1)
            cout << "yes";
        else
            cout << "no";
        cout << endl;
    }
}