#include <bits/stdc++.h>
#define maxn 1000
using namespace std;
char a[maxn];
int n, m;
void Gb()
{
    int dem = 0;
    map <char, int> trace[maxn];
    int res = 0, temp, t = n / m;

    for (int i = 1; i <= n; i++)
    {
        dem++;
        if (dem > m) dem = 1;
        trace[dem][a[i]]++;
    }
    char kq = '1';
    for (int i = 1; i <= m; i++)
    {
        temp = 0;
        for (auto j : trace[i])
        {
            if (temp < j.second)
            {
                temp = j.second;
                kq = j.first;
            }
            //cout << j.first << " " << j.second << endl;
        }
        //cout << temp <<endl;
        res += (t - temp);
        for (int i = 1; i <= t; i++)
            a[m * (i - 1) + 1] = kq;


    }
    cout << res << endl;
}
void pa()
{
    int res = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] != a[n + 1 - i])
        {
            res++;
            a[n + 1 - i] = a[i];
        }
    for (int i = 1; i <= n; i++)
        cout << a[i];
    cout << endl;
    cout << res << endl;
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase --)
    {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        Gb();
        pa();
    }
}