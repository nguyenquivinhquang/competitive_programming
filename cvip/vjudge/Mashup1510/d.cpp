#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>


const int N = 2000;
using namespace std;
int n, a[N], res = 0, q, l ,r;

signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++){
    	cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    	for (int j = 1; j < i; j++)
    		if (a[i] < a[j]) res++;
    res %= 2;
    cin >> q;
    while( q-- ){
    	cin >> l >> r;
    	int t = (r - l +1);
    	t = (t * (t - 1)) / 2;
    	t %=2;
    	res = (res + t) % 2;
    	if (res) cout << "odd\n"; else cout << "even\n";
     }
}