#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll n , a[1000005] , pf[1000005] , sf[1000005] , l[1000005];
int  IT[4000005] , leaf[4000005];
map<ll, ll> m;
void buildIT(ll i , ll l ,ll r){
    if(l == r){
        leaf[l] = i;
        return;
    }
    ll mid = (l + r) / 2;
    buildIT(i * 2 , l , mid);
    buildIT(i * 2 + 1 , mid + 1 , r);
}
void update(ll x){
    ll i = leaf[x];
    IT[i]++;
    while(i > 0){
        i /= 2;
        IT[i] = IT[i * 2] + IT[i * 2 + 1];
    }
}
void update2(ll x){
    ll i = leaf[x];
    IT[i]--;
    while(i > 0){
        i /= 2;
        IT[i] = IT[i * 2] + IT[i * 2 + 1];
    }
}
ll get(ll i ,ll l , ll r ,ll u, ll v){
    if(r < u || l > v) return 0;
    if(l >= u && r <= v) return IT[i];
    ll mid = (l + r) / 2;
    return get(i * 2 , l , mid , u , v) + get(i * 2 + 1 , mid + 1 , r , u , v);
}
int main()
{
    cin >> n;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    m.clear();
    buildIT(1 , 1 , n);
    for(int i = 1;i <= n;i++){
        m[a[i]]++;
        pf[i] = m[a[i]];
    }
    m.clear();
    for(int i = n;i >= 1;i--){
        m[a[i]]++;
        update(m[a[i]]);
        sf[i] = m[a[i]];
    }
    ll res = 0;
    for(int i = 1;i <= n;i++){
        update2(sf[i]);
        res += get(1 , 1 , n , 0 , pf[i] - 1);

    }

    cout << res;
    return 0;
}