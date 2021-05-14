#include <iostream>
#define ll long long
#define mod %
using namespace std;

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
ll fast_exp(ll x, ll sm, ll modul)
{
    ll a, b;
    if (sm==0) return 1;
    if (sm == 1)
        return x % modul;
    if (sm % 2 == 0)
    {
        a = fast_exp(x, sm / 2, modul) % modul;
        a = (a * a) % modul;
        return a;
    }
    else
    {

        a = fast_exp(x, sm / 2, modul) % modul;
        a = (a * a) % modul;
        a = (a * x) % modul;
        return a;
    }
}
ll Hoai_Thuong(ll x, ll y) 
{
    if (x == 1)
        return 1;
    if (y == 1)
        return  0;
    if (x<=2) return fast_exp(x,Hoai_Thuong(x-1,y),y);
    ll sm = y;
    ll p=phi(y);
    ll mu = Hoai_Thuong(x - 1,p);
    
    return fast_exp(x,mu+p,y);
}

int main()
{
    
    ll n, m;
    
    cin>>n>>m;
    //cout <<phi(12);
    //cout<<fast_exp(2,1843201,6912000);
    ll t=Hoai_Thuong(n,  m);
    cout << t% m;
}
