#include <bits/stdc++.h>
#define ll long long
#define int long long
using namespace std;
const int N = 10000;

int n, c[N], curSum = 0, cur1 = 0;
vector<int> flip1, flip0, constFlip; // flip1 -> 1 to 0, flip0 - > 0 to 1
signed main()
{
    cin >> n;
    char a[N], b;
    for (int i = 1; i <= n; i++)
        cin >> c[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> b;
        if (a[i] == b && b == '1')
        {
            constFlip.push_back(c[i]);
            cur1 += c[i];
        }
        else if (a[i] == '1' && b == '0')
        {
            flip1.push_back(c[i]);
            cur1 += c[i];
        }
        else if (a[i] == '0' && b == '1')
            flip0.push_back(c[i]);
    }
    sort(flip1.begin(), flip1.end(), greater<int>());
    sort(flip0.begin(), flip0.end());
    sort(constFlip.begin(), constFlip.end(), greater<int>());
    int si = 0;
//    cout << cur1 << endl;
    for (auto v : flip1)
    {
        si++;
        cur1 -= v;
        curSum = curSum + cur1;
    }
    for (auto v : flip0)
    {
        si++;
        cur1 += v;
        curSum = curSum + cur1;
    }
    int res = curSum;
    cout << res << endl;
    int i = 1;
    for (int i = 0 ; i < constFlip.size(); i++) {
        curSum -= constFlip[i] * si;
        ll temp = curSum;
        for (int j = i; j >= 0; j--)
            temp = temp + constFlip[j];
        res = min(res, temp);
    }
    cout << res;
}
