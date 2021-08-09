#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    int m = a[n / 2];
    long long s = 0;
    for (int i = 0; i < n; i++)
        s += abs(a[i] - m);
    cout << s << endl;
}