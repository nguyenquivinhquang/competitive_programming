#include<bits/stdc++.h>

using namespace std;
int a[100];

int cc(int n, vector<int> tt) {
    
    for (int i = 1; i <= n; i++)
        a[i] = tt[i - 1];
    int cost = 0;
    for (int i = 1; i < n; i++) {
        int M = a[i], index = i;
        for (int j = i; j <= n; j++) 
            if (a[j] < M ) {
                M = a[j];
                index = j;
            }
        cost += index - i + 1;
        reverse(a + i, a  + index + 1);
    }
    return cost;
}
void solve() {
    int n, cost;
    cin >> n >> cost;
    vector<int> anagrama;
    vector<vector<int>> v;
    for (int i = 1; i <= n; i++)
        anagrama.push_back(i);
    
    do {
        auto arr = anagrama;
        if (cc(n, arr) == cost) {
            for (auto ou : arr)
                cout << ou << " ";
            cout << "\n";
            return;
        }
    } while (next_permutation(anagrama.begin(), anagrama.end()));
    cout << "IMPOSSIBLE \n";

}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    for (int i = 1 ; i <= testcase; i++) {
        cout << "Case #" << i <<": ";
        solve();
    }
}