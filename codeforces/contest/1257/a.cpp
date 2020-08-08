#include <bits/stdc++.h>
#define maxn 100
#define ll long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int main()
{
    int testcase, n, k, a, b;
    cin >> testcase;
    while (testcase--)
    {
        cin >> n >> k >> a >> b;
        if (a > b)
            swap(a, b);
        while (b < n && k > 0)
        {
            b++, k--;
        }
        while (a > 1 && k > 0)
        {
            a--, k--;
        }
        cout << abs(a - b) << "\n";
    }
}