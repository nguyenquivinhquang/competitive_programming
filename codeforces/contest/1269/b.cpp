#include <bits/stdc++.h>

#define maxn 2001

using namespace std;
int a[maxn], b[maxn], temp[maxn];
int n, m;
void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    sort(b, b + n + 1);
    sort(a, a + n + 1);
}
bool check(int x)
{
    for (int i = 1; i <= n; i++)
        temp[i] = (a[i] + x) % m;
    sort(temp, temp + n + 1);
    for (int i = 1; i <= n; i++)
        if (b[i] != temp[i])
            return false;
    return true;
}
int find_x(int x, int y)
{
    int t;
    if (x > y)
        return m - x + y;
    if (x < y)
        return x + y + 1;
    if (y == 0)
        return m - x;
}
int Giang_Bae()
{
    int t;
    int res = 2147483647;
    if (check(0)==true ) return 0;
    for (int i = 1; i <= n; i++)
        if (a[i] != b[i])
        {
            t = (b[i] - a[i]) % m;
            if (check(t) == true)
                res = min(res, t);
        }
  
    return res;
}
int main()
{
    input();

    cout << Giang_Bae();
}