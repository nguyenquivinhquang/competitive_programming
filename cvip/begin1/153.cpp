#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int a[31];
    int res[31], pos[31], kq[31];
    int n;
    int max_res = 0;
    n = 1;
    while (cin >> a[n])
    {
        n++;
    }
    n--;
    for (int i = n; i >= 1; i--)
    {

        res[i] = 1;
        for (int j = i; j <= n; j++)
        {
            if (a[j] > a[i])
                if (res[j] + 1 > res[i])
                {
                    res[i] = res[j] + 1;
                    pos[i] = j;
                }
        }
        max_res = max(max_res, res[i]);
    }
    int i;
    for (i = 1; i <= n; i++)
        if (res[i] == max_res)
            break;
    int temp = res[i]; cout<<a[i]<<" ";
    for (int j = i; j <= n; j++)
    {
        if (res[j] == temp - 1)
        {
            cout << a[j] << " ";
            temp = res[j];
        }
    }
}