#include <iostream>
using namespace std;

long long int mulmod(long long int val, long long int n, long long int mod)
{
    long long int q = ((double)val * (double)n / (double)mod);
    long long int res = val * n - mod * q;
    res = (res % mod + mod) % mod;
    return res;
}
int main()
{
    long long a, b, c, kq; kq=1;
    cin >> a>> b>> c;
    for (int i = 1; i <= b; i++)
    {
        kq = mulmod(kq, a, c);
    }
    cout << kq<<endl;
    return 0;
}