#include <bits/stdc++.h>


const int N = 1000005;

using namespace std;


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, ll> pii;
typedef vector<int> vi;

ll n, le[N], ri[N];
struct SuffixArray {
	vi sa, lcp;
	SuffixArray(string& s, int lim=256) { // or basic_string<int>
		int n = sz(s) + 1, k = 0, a, b;
		vi x(all(s)+1), y(n), ws(max(n, lim)), rank(n);
		sa = lcp = y, iota(all(sa), 0);
		for (int j = 0, p = 0; p < n; j = max(1, j * 2), lim = p) {
			p = j, iota(all(y), n - j);
			rep(i,0,n) if (sa[i] >= j) y[p++] = sa[i] - j;
			fill(all(ws), 0);
			rep(i,0,n) ws[x[i]]++;
			rep(i,1,lim) ws[i] += ws[i - 1];
			for (int i = n; i--;) sa[--ws[x[y[i]]]] = y[i];
			swap(x, y), p = 1, x[sa[0]] = 0;
			rep(i,1,n) a = sa[i - 1], b = sa[i], x[b] =
				(y[a] == y[b] && y[a + j] == y[b + j]) ? p - 1 : p++;
		}
		rep(i,1,n) rank[sa[i]] = i;
		for (int i = 0, j; i < n - 1; lcp[rank[i++]] = k)
			for (k && k--, j = sa[rank[i] - 1];
					s[i + k] == s[j + k]; k++);
	}
};
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    string str;
    cin >> n >> str;

    SuffixArray suf(str);
    vector<ll> a, sa;
    for (int i = 1; i < suf.lcp.size(); i++) {
        a.push_back(suf.lcp[i]);
        sa.push_back(suf.sa[i]);
    }
    vector<ll> res(n+1);

    stack<pii> l, r;
    ll sum = 0;
    for (int i = 0;  i < n; i++) {
        ll temp = 0, c = 1;
        while (l.size() && l.top().first > a[i]) {
            temp += l.top().first*l.top().second;
            c += l.top().second;
            l.pop();
        }
        sum=sum - temp + c*a[i];
        l.push({a[i], c });
        res[sa[i]] += sum; 
    }
    sum = 0;
    for (int i = n-2;  i >= 0; i--) {
        ll temp = 0, c = 1;
        while (r.size() && r.top().first > a[i+1]) {
            temp += r.top().first*r.top().second;
            c += r.top().second;
            r.pop();
        }
        sum = sum - temp + c*a[i+1];
        r.push({a[i+1], c});
        res[sa[i]] += sum; 
    }
    
    
    for (int i = 0; i < n; i++) 
        cout << res[i] + (n-i)<< "\n";
}
