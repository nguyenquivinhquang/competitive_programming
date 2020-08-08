#include <bits/stdc++.h>

using namespace std;
int n;
vector<int> a;
int main()
{
    int temp, res = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        a.push_back(temp);
    }
    sort(a.begin(), a.end());
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= res)
            res++;
    }
    cout << res - 1;
}