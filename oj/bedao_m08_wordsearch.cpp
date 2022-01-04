#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

int res, si;
vector<int> prefix_function(string &s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
int n, m, q;
vector<string> str;
char a[N][N];
// bool check(int x, int )
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> m >> n >> q;
    string b;
    for (int i = 1; i <= n; i++) {
        string x = "";
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j]; 
            x.push_back(a[i][j]);
        }
        if (x == "") continue;
        str.push_back(x);
        reverse(x.begin(), x.end());
        str.push_back(x);
    }
    for (int j = 1; j <= m; j++) {
        string x = "";
        for (int i = 1; i <= n; i++) {
            x.push_back(a[i][j]);
        }
        if (x == "") continue;
        str.push_back(x);
        reverse(x.begin(), x.end());
        str.push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            string s; 
            // if (i != 1 && j != 1) continue;
            int x = i, y = j;
            while(x <= n && y <= m) {
                s.push_back(a[x][y]);
                x++, y++;
            }
            if (s != "") {
                str.push_back(s);
                reverse(s.begin(), s.end());
                str.push_back(s);
            }
            s= ""; 
            // if (i != 1 && j != 1) continue;
            x = i, y = j;

            while(x <= n && y > 0) {
                s.push_back(a[x][y]);
                x++, y--;
            }
            if (s == "") continue;
            str.push_back(s);
            reverse(s.begin(), s.end());
            str.push_back(s);
        }
    }

    while(q--) {
        cin >> b;
        si = b.length();
        bool check = false;
        for (auto v : str) {
            string temp =  b + '#' + v;
            vector<int> t = prefix_function(temp);
            
            for (auto v : t)
                if (v == si) {
                    check = true;
                    break;
                }
            if (check == true) break;
        } 
        if (check) cout << "YES\n";
        else cout << "NO\n";
    } 
}
