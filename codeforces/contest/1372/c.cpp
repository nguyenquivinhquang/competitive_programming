#include <bits/stdc++.h>
#define maxn 200001
using namespace std;
int solve()
{
    int n, a[maxn], s = 1;
    bool check_increase = true, same_pos = false;
    cin >> n;
    a[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
        if (a[i] == i)
            s++;
        else
            break;
    for (int i = n; i >= 1; i--)
        if (a[i] == i)
            n--;
        else
            break;
    for (int i = s; i <= n; i++)
    {

        if (a[i] < a[i - 1])
            check_increase = false;
        if (a[i] == i)
            same_pos = true;
    }
    if (check_increase == true)
        return 0;
    if (same_pos == true)
        return 2;
    return 1;
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        printf("%d \n", solve());
        //cout << solve() << endl;
    }
}