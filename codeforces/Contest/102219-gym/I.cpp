#include <bits/stdc++.h>

#define openr(a) freopen(a, "r", stdin)
#define openw(a) freopen(a, "w", stdout)
#define reset(a) memset(a, 0, sizeof(a))
#define read(v) for(auto &x: v) cin >> x;

using namespace std;

typedef long long ll;
typedef signed long long int sll;
typedef unsigned long long int ull;
typedef pair<sll, sll> ii;
typedef tuple<sll, sll, sll> iii;

const sll maxn= 1e6;
const sll inf= 1e9;

void process(string &s, bool &check) {
    for(int i= 0; i< 10; i++) {
        if(check && s[i] != '.') {
            cout << s[i];
            return;
        }
        if(s[i]== '=') {
            check= 1;
        }
    }
    if(check) cout << "You shall pass!!!";
    return;
}

int main() {
    //openr("input.txt");
    //openw("output.txt");
    ios::sync_with_stdio(0), cin.tie(0);
    string H, T, P;
    cin >> H >> T >> P;

    bool check= 0;
    process(H, check);
    if(check) return 0;
    process(T, check);
    if(check) return 0;
    process(P, check);
    return 0;
}
