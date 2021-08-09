#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000009;

using namespace std;

int n;
ll curSum = 0;
ll res = 1;
int a[N];
signed main(){
    ios_base::sync_with_stdio(false);cin.tie(0); 
    cin>>n;   
    for (int i = 1; i <= n; i++) 
        cin>>a[i];
    sort(a + 1, a + n +1);
 
    for (int i = 1; i <= n; i++) {
        if (res < a[i]) return cout<< res , 0;
        res += a[i];
    }
    cout<<res;
}