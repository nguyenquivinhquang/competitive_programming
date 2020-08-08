#include <bits/stdc++.h>
#define maxn 1000
using namespace std;
char a[maxn];
map<char, int> trace[maxn];
int n, m;
void Gb()
{
    int dem = 0;
    for (int i = 1; i <= n; i++)
    {
        dem++;
        if (dem > m)
            dem = 0;
        trace[dem][a[i]]++;
    }
    int res = 0, temp, t = n / m;
    for (int i = 1; i <= m; i++)
    {
        temp = 0;
        for (auto j : trace[m])
            temp = max(temp, j.second);
        res += (t - temp);
    }
    cout << temp << endl;
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        Gb();
    }
}