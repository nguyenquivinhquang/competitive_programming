#include <bits/stdc++.h>
#define N 1000
using namespace std;
void q1()
{
    string a, res = "", t = "";
    bool trace[200];
    memset(trace, 0, sizeof(trace));
    cin >> a;
    for (int i = 0; i < a.length(); i++) {
        if (trace[a[i]] == 0) {
            t = t + a[i];
            trace[a[i]] = 1;
        }
        else {
            if (res.length() < t.length())
                res = t;
            t = "";
            memset(trace, 0, sizeof(trace));
        }
    }
    if (res.length() < t.length())
        res = t;
    cout << res;
}
void q2()
{

    int temp, n, k, a[N];
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (a[i] + a[j] == k && i != j) {
                cout << i - 1 << " " << j - 1 << endl;
                return;
            }
}
void q3()
{
    int n, m, a[N], b[N];
    vector<int> c;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 1; j <= m; j++)
        cin >> b[j];
    int i = 1, j = 1;
    while (i <= n && j <= m) {
        if (a[i] < b[j])
            c.push_back(a[i++]);
        else
            c.push_back(b[j++]);
    }
    while (i <= n) {
        c.push_back(a[i++]);
    }
    while (j <= m) {
        c.push_back(b[j++]);
    }
    //cout << c.size();
    double median;
    if ((n + m) % 2 == 0)
        median = (c[(n + m) / 2] + c[(n + m) / 2 - 1]) / 2.0;
    else
        median = c[(n + m) / 2];
    printf("%.1f", median);
}
int main()
{
    //q2();
    q3();
}