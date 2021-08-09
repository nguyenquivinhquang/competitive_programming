#include <bits/stdc++.h>

using namespace std;
vector<int> a, b, c;
int n, temp;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end());
    for (int i = 1; i <= n - 1; i++)
    {
        cin >> temp;
        b.push_back(temp);
    }
    sort(b.begin(), b.end());
    temp = a[n - 1];
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] != b[i])
        {
            temp = a[i];
            break;
        }
    }
    cout << temp << endl;
    for (int i = 1; i <= n - 2; i++)
    {
        cin >> temp;
        c.push_back(temp);
    }
    sort(c.begin(), c.end());
    temp = b[n - 2];
    for (int i = 0; i < n - 2; i++)
    {
        if (c[i] != b[i])
        {
            temp = b[i];
            break;
        }
    }
    cout << temp << endl;
}