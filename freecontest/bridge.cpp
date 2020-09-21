#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define N 100005
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
/* 	
	Can also use #include <bits/extc++.h>
	But does not work on some compilers
*/

using namespace std;
using namespace __gnu_pbds;

template <class T>
using indexed_multiset = tree<T, null_type, greater_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T, class X>
using indexed_map = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
using namespace std;
pp a[N];
int n;
ll res = 0;
indexed_multiset<int> y;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a + 1, a + 1 + n);
    y.insert(a[1].second);
    for (int i = 2; i <= n; i++)
    {
        int count = y.order_of_key(a[i].second);
        res = res + count;
        y.insert(a[i].second);
    }
    cout << res << endl;
}