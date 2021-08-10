#include <bits/stdc++.h>
#define ll long long
#define pp pair<int, int>
using namespace std;
const int N = 1000;
vector<int> prefixFuntion(string &s) {
    int n = s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}
signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);

}
