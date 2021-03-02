#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
int trace[1 << 17];
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    memset(trace, 0, sizeof(trace));

    int q, val;
    string command;
    cin >> q;
    while (q--) {
        cin >> command >> val;
        if (command == "add") trace[val]++;
        else if (command == "del") trace[val]--; 
        else {
            int c = 0;
            for (int i = 0; i <= val; i++)
                if ((i & val) == i) 
                    c += trace[i];
            cout << c << "\n";
        }
    }
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/