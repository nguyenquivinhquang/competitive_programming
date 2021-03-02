#include <bits/stdc++.h>
#define ll long long
#define pp pair<int, int>
using namespace std;
const int N = 1000;
int n;
vector<int> vertice[N];
signed main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int x, y;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> x >> y;
        vertice[x].push_back(y);
        vertice[y].push_back(x);
    }

}
