#include <iostream>
using namespace std;

int mod=1000000007;
int frac(int n, int k)
{
    long long int cal = 1;
    for (int i = n - k + 1; i <= n; i++)
    {
        long long int q = ((double)cal * (double)i / (double)mod);
        cal = cal * i - mod * q;
        cal = (cal % mod + mod) % mod;

    }
    return cal;
}
int main()
{
    int n, k, t;
    cin >>t; 
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> k;
        cout<< frac(k,n)<<endl;
    }
    return 0;
}
    