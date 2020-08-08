#include <bits/stdc++.h>
#define maxn 1001
using namespace std;

int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        int n, aa = 0, bb = 0, lasta = 0, lastb = 0;
        cin >> n;
        int l = 1, r = n, cnt = 0;
        int a[n + 10];
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        while (l <= r)
        {
            cnt++;
            lasta = 0;
            while (l <= r && lasta <= lastb)
                lasta += a[l], aa += a[l++];
            if (l > r)
                break;
            cnt++;
            lastb = 0;
            while (l <= r && lastb <= lasta)
                lastb += a[r], bb += a[r--];
        }
        cout << cnt << " " << aa << " " << bb << endl;
    }
}