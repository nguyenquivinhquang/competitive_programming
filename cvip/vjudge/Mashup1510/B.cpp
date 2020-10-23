#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1050;
using namespace std;
vector<int> trace[N];
vector<int> cur;
int n, sum = 0;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) cur.push_back(i);
    for (int i = 1; i <= 2; i++) {
        bitset<N> fee;
        while (1) {
            char c;
            fee.reset();
            for (int i = 0; i < cur.size(); i++) {
                if (i + 1 == cur.size()) break;
                cout << "? " << cur[i] << " " << cur[i + 1] << endl;
                cin >> c;

                if (c == '<') swap(cur[i], cur[i + 1]);

                fee[cur[i]] = 1;
                trace[cur[i]].push_back(cur[i + 1]);

                i++;
            }
            int temp = -1;
            if (cur.size() % 2 == 1) temp = cur[cur.size() - 1];
            cur.clear();
            if (temp != -1) cur.push_back(temp);
            for (int i = 1; i <= n; i++)
                if (fee[i] == 1) cur.push_back(i);

            if (cur.size() == 1) break;
        }
        if (i == 2) {
            cout << "! " <<cur[0];
            return 0;
        }
        int val = cur[0];
        cur.clear();
        for (auto v : trace[val]) {
            cur.push_back(v);
        }
        for (int i = 1; i <= n; i++) trace[i].clear();
    }
}