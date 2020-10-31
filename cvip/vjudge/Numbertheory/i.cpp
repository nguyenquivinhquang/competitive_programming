#include <bits/stdc++.h>

#define ll long long 

using namespace std;
int gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);

    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }
    cout << "a is " << a << " b is  " << b <<" " << x0 << " " << y0 << endl;
    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    int k = -100;
    int x  = x0, y = y0;
    //cout << x0 << " " << y0 << endl;
 	while(x0 <= 0 || y0 <= 0) {
 	    x0 = x + k * (b / g);
 	    y0 = y - k * (a / g);
 	   	//cout << x0 << " " << y0  << endl;
 	    k++;
 	    if (k >= 100) return false;
 	}
 	
    return true;
}

signed main(){
	//ios_base::sync_with_stdio(false), cin.tie(NULL);
	int n, a = 0, b = 0, g;
	cin >> n;
	for (int i = 1; i <= sqrt(n) + 1; i++){
		//cout << i << endl;
		if (n % i != 0)
			continue;
		//int x, y, g;
		//cout << t << endl;
		int g = n - 1;
		if (find_any_solution(i, n / i, n - 1, a, b, g)){
			if (a == 0 || b == 0) continue;
			cout << "YES \n2 \n";
			cout << a << " " << i <<" " << b <<" " <<  n / i << endl;
			exit(0);
		}
	}
	cout << "NO";
	 // find_any_solution(2, 3, 5, a, b , g);
	 // cout << b;
	//s cout << a << " " <<

}