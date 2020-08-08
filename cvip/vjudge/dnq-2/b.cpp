#include <bits/stdc++.h>
#define ll long long
#define mod %

using namespace std;
ll n, m;
ll a[100];
vector<int> l, r;
int main()
{
    cin >> n >> m;
    //freopen("oupt.txt","w",stdout);
    for (ll i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    ll lim_trai = n / 2, kq = 0;
    ll sum = 0;
    l.push_back(0), r.push_back(0);
    ll maxn_l = 0, maxn_r = 0;

    for (ll i = 1; i <= lim_trai; i++)
    {
        ll c = 0;
        for (ll j = 0; j <= maxn_l; j++)
        {
            sum = (l[j] + a[i]) mod m;
            l.push_back(sum);
            kq = max(kq, sum);
            //cout<<sum<<endl;
            c++;
        }
        maxn_l += c;
    }
    sort(l.begin(), l.end());
    //cout<<"quangcutevaidai<3333333333333333333333333333333333333333333333333333333"<<endl<<endl;
    for (ll i = lim_trai + 1; i <= n; i++)
    {
        ll c = 0;
        for (ll j = 0; j <= maxn_r; j++)
        {
            sum = (r[j] + a[i]) mod m;
            kq = max(kq, sum);
            r.push_back(sum);
            //cout<<sum<<endl;
            c++;
        }
        maxn_r += c;
    }
    for (ll i = 1; i <= maxn_r; i++)
    {
        ll temp = m - r[i] -1;
        auto pos = upper_bound(l.begin(), l.end(), temp);
        //cout<<*pos<<endl;
        //while (*pos>temp) pos--;
        pos--;
        kq = max(kq, (*pos + r[i]) mod m);
    }
    //cout<<maxn_l<<endl;
    cout << kq;
}