#include <bits/stdc++.h>

using namespace std;

signed main(){
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	int n;
	cin >> n;
	string a[n + 1];
	for (int i =1 ; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++){
		for (int j = a[i].length() - 1; j >= 0; j--)
			cout << a[i][j];
		cout <<"\n";
	}

}