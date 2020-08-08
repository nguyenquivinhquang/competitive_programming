#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int mod = 1000000007;
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	long long int t;
	ifstream read("text.txt");
    ofstream write("a1.txt");
    read>>t;
	while(t--){
		ll n,k;
		read>>n>>k;
		ll a[k];
		ll val = n/k;	
		ll c = n%k;
		c = min(k/2,c);
		ll sum = val*k + c;
		write<<n<<" va "<<k<<": "<<sum<<endl;
		//write<<sum<<endl;
	}
	
}