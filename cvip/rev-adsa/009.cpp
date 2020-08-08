#include <bits/stdc++.h>
#define maxn 100001
using namespace std;
int n, m;
int calo[maxn], f, l;
string temp;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> calo[i] >> temp;
    f = 1, l = n;
    while (f != l)
    {
        l--;
        if (l - f < 1)
            break;
        f++;
        if (abs(l - f) <= 1)
            break;
        int mid = (f + l) / 2;
        if (abs(l-f)==2 && f<m && m < l)
        {
            cout <<"YES";
            return 0;
        }
        if (m > mid)
            f++;
        else
            l--;
        if (f >= l)
            break;
    }
    if (f <= m && m <= l)
        cout << "YES";
    else
        cout << "NO";
}