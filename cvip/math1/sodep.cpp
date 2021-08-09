#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
int prime[200];
int cprime = 0;
bool dp[5000000];
void primecal(int n)
{

    vector<bool> mark(n + 1, true);
    mark[0] = mark[1] = false;

    for (int i = 2; i <= n; i++)
    {
        if (mark[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                mark[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (mark[i])
        {
            cprime++;
            prime[cprime] = i;
        }
    }
}
bool checkprime(int x, int k)
{
    for (int i = 1; i <= cprime; i++)
    {
        if ((x <= k) || (x <= prime[i]))
            return true;
        while (x % prime[i] == 0)
        {
            x = x / prime[i];
            if (x <= k)
                return true;
            if (dp[x] == true)
                return true;
        }
    }
    return false;
}
int main()
{
    primecal(1000000);
    /*int n, k;
    int res = 0;
    cin >> n >> k;
    memset(dp, false, n);
    primecal(k);

    for (int i = 2; i <= n; i++)
    {
        if (checkprime(i, k) == true)
        {
            dp[i] = true;
            res++;
        }
    }
    cout << res + 1 << endl;*/

    
    return 0;
}
