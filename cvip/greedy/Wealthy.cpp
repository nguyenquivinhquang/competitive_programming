#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <climits>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include <bitset>
#include <stack>
#include <queue>
#include <set>
#define fr(a) freopen(a,"r",stdin)
#define fw(a) freopen(a,"w",stdout)
#define rep(i,a,b,c) for(int i=a;i<b;i+=c)
#define repe(i,a,b,c) for(int i=a;i<=b;i+=c)
#define reset(a) memset(a,0,sizeof(a))
#define nl printf("\n")
#define ri(a) scanf("%d",&a)
#define rll(a) scanf("%lld",&a)
#define rllu(a) scanf("%llu",&a)
#define wi(a) printf("%d",a)
#define wll(a) printf("%lld",a)
#define wllu(a) printf("%llu",a)
using namespace std;
typedef long long int ll;
typedef unsigned long long int llu;
typedef long double lf;
typedef pair<ll,ll>pii;
typedef vector<int> vi;
typedef vector<ll> vii;

struct nha{
    int d,h,ind;
    bool operator< (const nha x) const{
        if(h>x.h) return true;
        if(h<x.h) return false;
        if(d>x.d) return true;
        return false;
    }
};

int minH_level[100];
int ans[100];
nha a[100];
int n;


int main(){
    //fr("wealthy.txt");
    //fw("out.txt");

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i].d >> a[i].h;
        a[i].ind = i;
    }

    sort(a,a+n);

    int maxLevel = 0;

    for(int i=0;i<n;i++){

        int curInd = a[i].ind;

        int curLevel = lower_bound(minH_level+1,minH_level+1+maxLevel,a[i].d) - minH_level;
        ans[curInd] = curLevel;
        minH_level[curLevel] = a[i].d;
        maxLevel = max(maxLevel,curLevel);

        //cout << a[i].d << ' ' << a[i].h << "\t" << curLevel << endl;

    }
    for(int i=0;i<n;i++) cout << ans[i] << endl;

    return 0;
}




