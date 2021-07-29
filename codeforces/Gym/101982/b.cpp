#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
const int N = 10000000;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef pair<int, int> pii;
typedef vector<int> vi;
const int MAX_PR = N;
bitset<MAX_PR> isprime;
ll square_fee[N];
int mark[N+10], square_free[N+10];
 
void sieve() {
   for(int i=1; i<=N; i++) square_free[i]=1;
 
   for(int i=2; i<=N; i++) {
       if(!mark[i]) {
           for(int j=i; j<=N; j+=i) mark[j]++, square_free[j]*=i;
       }
   }
}
int x, step = 0;
map<int,int> trace;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
	
	sieve();
	
    int a,b,c,d,x,y,s,t;
    cin >> a >> b >> c >> d;
    ll ans = 0;
    for (int x = 2; x <= N; x++)  {
		if (square_free[x] != x) continue;

        ll z=d/x, y=(c-1)/x;
        ll q=b/x, p=(a-1)/x;

        if(mark[x] % 2 == 1) ans += (z - y) * (q - p);
        else      ans -= (z - y) * (q - p);
    }
	ans = ((d - c + 1) * (b - a + 1)) - ans;
	
	cout << ans;
}	
