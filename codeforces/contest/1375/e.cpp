#include <bits/stdc++.h>
#define maxn 1001
using namespace std;

int main()
{
    int a[maxn], b[maxn], n;
    vector<pair<int, int>> trace;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
            if (b[i] == a[j] && i != j)
            {
                swap(a[i], a[j]);
                trace.push_back({i, j});
                break;
            } else if (b[i]==a[j] && i==j) break;
    }
    cout << trace.size() << endl;
    for (auto v : trace)
    {
        cout << v.first << " " << v.second << endl;
    }
}