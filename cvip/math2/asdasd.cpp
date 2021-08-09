#include <bits/stdc++.h>

using namespace std;
#define ll long long 

ll n , t, k , s, c1 ,c2 , m , f1 , f2, l[10000002];
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k >> s >> c1 >> c2 >> m;
        for(int i = 0;i < m;i++) l[i] = 0;
        f1 = s;
        for(int i = 1;i <= n;i++){
            ll x = (c1 * f1 % m + c2 % m) % m;
            l[x]++;
            f1 = x;
        }
        l[s % m]++;
        ll cnt = 0;
        for(int i = 0;i < m;i++){
            if(k <= 0) break;
            for(int j = 1;j <= l[i];j++){
                cout << i << " " ;
                k--;
                if(k == 0) break;
            }
        }
        cout << "\n";
    }
}