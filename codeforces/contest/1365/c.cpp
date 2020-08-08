#include <bits/stdc++.h>
#define maxn 100001

using namespace std;
int b[maxn], n, temp;
map<int, int> trace, a;
int find(int x, int y)
{
    if (x <= y)
        return y - x;
    return n - x + y;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        a[temp] = i - 1;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        trace[find(i - 1, a[temp])]++;
    }
    int res = 0;
    for (auto v : trace)
        res = max(res, v.second);
    cout << res;
}