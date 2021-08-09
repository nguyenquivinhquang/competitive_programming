#include <bits/stdc++.h>
 
#define openr(a) freopen(a, "r", stdin)
#define openw(a) freopen(a, "w", stdout)
#define reset(a) memset(a, 0, sizeof(a))
#define read(v) for(auto &x: v) cin >> x;
#define all(a) a.begin(),a.end()
#define fi first
#define se second
 
using namespace std;
 
typedef long long ll;
typedef signed long long int sll;
typedef unsigned long long int ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef pair<sll, sll> sii;
typedef tuple<sll, sll, sll> siii;
 
const sll maxn= 1e6;
const int inf= 1e9;
 
// knight moves
int xkt[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int ykt[] = {-1, 1, -2, 2, -2, 2, -1, 1};
 
// king moves
int xkg[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int ykg[] = {-1, 0, 1, -1, 1, -1, 0, 1};
 
// 4 directions
int dx[]= {0, 0, -1, 1};
int dy[]= {1, -1, 0, 0};
 
void dijkstra(vector<vector<ii>> &edges, vector<int> &d){
    d[1]= 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push(ii(0, 1));
    while(pq.size()){
        int u= pq.top().second;
        int du= pq.top().first;
        pq.pop();
        if(du != du) continue;
 
        for(auto &i: edges[u]){
            int v= i.se;
            int uv= i.fi;
            if(d[v] > du+uv){
                d[v]= du+uv;
                pq.push(ii(d[v], v));
            }
        }
    }
    return;
}
 
int main(){
    //openr("input.txt");
    //openw("output.txt");
    ios::sync_with_stdio(0), cin.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<ii>> edges(n+1, vector<ii> ());
    vector<int> d(n+1, inf);
    while(m--){
        int u, v; cin >> u >> v;
        edges[u].push_back(ii(1, v));
        edges[v].push_back(ii(1, u));
    }
    dijkstra(edges, d);
    if(d[n] != inf){
        vector<int> ans;
        ans.push_back(n);
        int u= n;
        while(u!= 1){
            for(auto &i: edges[u]){
                int v= i.se;
                int uv= i.fi;
                if(d[u]-uv== d[v]){
                    ans.push_back(v);
                    u= v;
                    break;
                }
            }
        }
        cout << ans.size() << "\n";
        reverse(all(ans));
        for(auto &i: ans) cout << i << " ";
    }
    else cout << "IMPOSSIBLE\n";
    return 0;
}