#include<iostream>
#include<numeric>
#include<time.h>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<deque>
#include<cstring>
#include<map>
#include<math.h>
#define ll long long
#define DB double
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define REP(i,a,b) for(int i=a-1;i>=b;i--)
#define F first
#define S second
#define pb push_back
#define endl "\n"
#define INF (ll)(1e18)
#define MOD (ll)(1e9+7)
#define AC ios::sync_with_stdio(0);cin.tie(0);

using namespace std;

vector<int> suf_arr(const string &s,int lim=256){
    int n=(int)s.size();
    vector<int> sa(n+1),rk(s.begin(),s.end()+1),y(n+1),cnt(max(lim,n+1));
    iota(sa.begin(),sa.end(),0);
    
    for(int j=0,p=0;p<=n;j=max(1,j*2),lim=p){
        p=j;iota(y.begin(),y.end(),n-j+1);
        for(int i=0;i<=n;i++) if(sa[i]>=j) y[p++]=sa[i]-j;
        fill(cnt.begin(),cnt.end(),0);
        for(int i=0;i<=n;i++) cnt[rk[i]]++;
        for(int i=1;i<lim;i++) cnt[i]+=cnt[i-1];
        for(int i=n;i>=0;i--) sa[--cnt[rk[y[i]]]]=y[i];
        swap(rk,y); rk[sa[0]]=0; ; p=1;
        for(int i=1;i<=n;i++){
            if(y[sa[i]]==y[sa[i-1]]&&y[sa[i]+j]==y[sa[i-1]+j]) rk[sa[i]]=p-1;
            else rk[sa[i]]=p++;
        }
    }
    
    sa.erase(sa.begin());
    return sa;
}

vector<int> lcp_arr(const vector<int> &sa,const string &s){
    vector<int> lcp(sa.size()),rk(sa.size());
    FOR(i,0,sa.size()) rk[sa[i]]=i;
    int k=0,n=(int)sa.size();
    for(int i=0;i<n;i++){
        int j;
        if(rk[i]) j=sa[rk[i]-1];
        else j=n;
        while(i+k<n&&j+k<n&&s[i+k]==s[j+k]) k++;
        lcp[rk[i]]=k; k=max(0,k-1);
    }
    return lcp;
}

ll ans[1000005];

int main(){
    AC;
    int n; string  s;
    cin>>n>>s;
    vector<int> sa=suf_arr(s),lcp=lcp_arr(sa,s);
    stack<pair<ll,ll> > st;
    ll sum=0;
    for (auto v : sa) cout << v << " ";
    FOR(i,0,n){
        ll tmp=0,cnt=1;
        while(st.size()&&st.top().F>lcp[i]){
            tmp+=st.top().F*st.top().S;
            cnt+=st.top().S;
            st.pop();
        }
        sum=sum-tmp+cnt*lcp[i];
        st.push({lcp[i],cnt});
        ans[sa[i]]+=sum;
    }
    sum=0;
    while(st.size()) st.pop();
    for(int i=n-2;i>=0;i--){
        ll tmp=0,cnt=1,now=lcp[i+1];
        while(st.size()&&st.top().F>now){
            tmp+=st.top().F*st.top().S;
            cnt+=st.top().S;
            st.pop();
        }
        sum=sum-tmp+cnt*now;
        st.push({now,cnt});
        ans[sa[i]]+=sum;
    }
    for(int i=0;i<n;i++) cout<<ans[i]+(n-i)<<endl;
}
/*

 
 
 */
