#include <bits/stdc++.h>

using namespace std;
int n, temp, start = 1, res = 0;
vector<int> a;
map<int, int> b;
void debug(int x, int y)
{
    for (int i = x; i <= y; i++)
        cout << a[i] << " ";
    cout << endl;
}
int main()
{
    freopen("test_input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    a.push_back(-1);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> temp, a.push_back(temp);
    for (int i = 1; i <= n; i++)
    {
        if (b[a[i]] == 0)
            res = max(res, i - start + 1);
        else
            res = max(res, i - max(b[a[i]], start)), start = max(b[a[i]] + 1, start);
        b[a[i]] = i;
        if (res == 147) debug(start, i);
    }
    cout << res;
}