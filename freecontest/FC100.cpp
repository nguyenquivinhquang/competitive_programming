#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
string check = "Free Contest 100";

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    string t;
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while (getline(cin, t)) {
        if (t == check) {
            cout << "Let’s start!\n";
            break;
        } else
            cout << "Wait\n";
    }
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/