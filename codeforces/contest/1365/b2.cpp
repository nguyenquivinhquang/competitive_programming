#include <bits/stdc++.h>
#define maxn 501
using namespace std;
int a[maxn], b[maxn], n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int j = 1; j <= n; j++)
            cin >> b[j];
        for (int k=1; k<=3; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= i; j++)
                if (a[i] < a[j] && b[i] != b[j])
                {
                    swap(a[i], a[j]);
                    swap(b[i], b[j]);
                }
        bool check = true;
        for (int i = 1; i < n; i++)
            if (a[i] > a[i + 1])
            {
                check = false;
                break;
            }
        if (check == false)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
}