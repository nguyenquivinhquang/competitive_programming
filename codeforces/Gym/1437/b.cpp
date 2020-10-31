#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 10009;

using namespace std;
int n;
char a[N];
int pre[0][2];

signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
 	int testcase;
 	cin >> testcase;
 	int n, res = 0;
 	string x;
 	while(testcase--) {
 	    cin >> n;
 	    res = 0;
 	    cin >> x;
 	    for (int i = 1; i < x.length(); i++)
 	    	if (x[i] == x[i-1])
 	    		res++;
 		res = (res + 1) / 2;
 		cout << res << "\n";
 		
 	}


}