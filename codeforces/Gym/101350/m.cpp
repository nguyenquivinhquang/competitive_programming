#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
 
#define openr(a) freopen(a, "r", stdin)
#define openw(a) freopen(a, "w", stdout)
#define reset(a) memset(a, 0, sizeof(a))
#define read(v) for(auto &x: v) cin >> x;
#define all(a) a.begin(),a.end()
#define fi first
#define se second
 
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef signed long long int sll;
typedef unsigned long long int ull;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef pair<sll, sll> sii;
typedef tuple<sll, sll, sll> siii;
 
#define ordered_set tree<ii, null_type,less<ii>, rb_tree_tag,tree_order_statistics_node_update>
 #define double long double
const sll maxn= 1e6;
const sll inf= 1e9;
const sll MOD= inf + 7;
 
// knight moves
int xkt[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int ykt[] = {-1, 1, -2, 2, -2, 2, -1, 1};
 
// king moves
int xkg[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int ykg[] = {-1, 0, 1, -1, 1, -1, 0, 1};
 
// 4 directions
int dx[]= {0, 0, -1, 1};
int dy[]= {1, -1, 0, 0};
char dc[] = {'R', 'L', 'U', 'D'};
 
unordered_map<string,  double> dic;
 
int main(){
    //openr("input.txt");
    //openw("output.txt");
    ios::sync_with_stdio(0), cin.tie(0);
    int tc; cin >> tc;
    
    while(tc--){
        dic["JD"]= 1;
        int a, b; cin >> a >> b;
        for(int i= 0; i< a; i++){
            string c;   double v; cin  >> c >> v;
            dic[c]= v;
        }
         double ans= 0.0;
 
        for(int i= 0; i< b; i++){
            string c;  double v; cin >> v >> c;
            ans+= v*dic[c];
        }
        cout << fixed << setprecision(8) << ans << "\n";
        dic.clear();
    }
    return 0;
}