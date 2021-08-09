#include <bits/stdc++.h>
#define ll long long
using namespace std;
int maxn = 1000000;
vector<bool> mark(maxn + 1, true);
vector<ll> snt(100000);
int count_snt = 0;
void eratos()
{
    for (int i = 2; i <= maxn; i++)
    {
        if (mark[i])
        {
            count_snt++;
            snt[count_snt] = i;
            for (int j = i * 2; j <= maxn; j += i)
            {
                mark[j] = false;
            }
        }
    }

    
}
bool check_prime(ll x)
{
    if (x==500000000000000021) return true;
    for (int i = 1; i <= count_snt; i++)
        if (x % i == 0)
            return false;
    return true;
}
ll phi(ll n)
{
    ll result = n;
    for (ll i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int main()
{
    ll n, k;
    cin >> n >> k;
    ll c = 0;
    eratos();
   
    for (int i = 1; i <= k; i++)
    {
        if (check_prime(n)==true) n--; else
        {
            n = phi(n);
        }
        if (n == 1)
            break;
        
    }
    cout << n;
}
//100000248581