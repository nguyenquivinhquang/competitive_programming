#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long
#define openr() freopen("input.txt","r",stdin)
#define mp make_pair
#define fi first
#define se second
 
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
 
typedef long long  ll;
const int inf=1e9;
const int maxn=200001;
struct line
{
    ll l;
    ll r;
    ll w;
    bool operator < (const line &a)
    {
        return r<a.r;
    }
};
vector<line>v;
ll dp[maxn];
 
 
ll bin(ll id) {
    int l=0,r=id-1;
    ll ans=0;
    while(l<=r) {
        int mid=(l+r)/2;
        if(v[mid].r> v[id].l) r=mid-1;
        else
        {
            ans=max(ans,dp[mid]);
            l=mid+1;
        }
    }
    return ans;
} 
int n, T; 
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n >> T;
    
    // v.resize(n);
    // for(int i=0;i<n;i++)    cin>>v[i].l>>v[i].r>>v[i].w;
    
    for (int i = 1; i <= n; i++) {
        int d, h, t; cin >> h >> d >> t;
        for (int j = 1; j <= t; j++) {
            int x; cin >> x;
            if (x > T) continue;
            line temp = {x, x + d, h};
            v.push_back(temp);
        }
    }
    sort(v.begin(),v.end());
    n = v.size();
    for(int i=0;i<n;i++) {
        if(i==0) {
            dp[i]=v[i].w;
            continue;
        }
        ll sum1 = dp[i-1];
        ll sum2 = v[i].w+ bin(i);
        dp[i]=max(sum1,sum2); }
    cout<<dp[n-1];
 
    return 0;
}
