#include <bits/stdc++.h>
#define maxn 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define quangcute true
using namespace std;
int main()
{
    int testcase, sum, temp, n, res;
    while (quangcute == true)
    {
        cin >> n;
        if (n == 0)
            return 0;
        sum = res = -1e9;
        for (int i = 1; i <= n; i++)
        {
            cin >> temp;
            sum += temp;
            if (sum < temp)
            {
                sum = temp;
            }
            res = max(res, sum);
        }
        if (res > 0)
            cout << "The maximum winning streak is " << res << "." << endl;
        else
            cout << "Losing streak." << endl;
    }
}