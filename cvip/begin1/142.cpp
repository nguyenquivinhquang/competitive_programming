#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int a[10000];
    int n = 1;
    while (cin >> a[n])
    {
        n++;
    }
    sort(a, a + n );
    int res = 1;
    for (int i = 2; i <= n-1; i++)
    {
        if (a[i] != a[i - 1])
        {
            res++;
            
        }
    }
    cout << res;
}