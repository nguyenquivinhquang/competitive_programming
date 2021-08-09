#include <bits/stdc++.h>
#define int long long

using namespace std;

const int N = 100009;

int n;
int a[N], pos[N];
bool win[N];
signed main() {
	ios_base::sync_with_stdio(false);
	cin >> n;
	memset(win, false, sizeof(win)); // win[i] = true -> the current player has value i is a loser
	
	for (int i =1 ; i <= n; i++){
		cin >> a[i];
		pos[a[i]] = i;
	}
	win[n] = false;
	for (int i = n - 1; i >= 1; i--) {
		bool check = false; // false -> Alice is a loser
		int position = (i - pos[i] % i) % i;
		for (int j = 1; j <= n / i; j++) {
			int index =  abs(j * i + pos[i]);
			
			if ( index <= n && !win[a[index]] && a[index] > i ) {
				check = true;
				break;
			}
			index =  (- j * i + pos[i]);
			if ( index > 0 && !win[a[index]] && a[index] > i ) {
				check = true;
				break;
			}
		}
		win[i] = check;
	}
	for (int i = 1; i <= n; i++) {
		if (win[a[i]] == true) 
			cout << "A";
		else cout << "B";
	}

}