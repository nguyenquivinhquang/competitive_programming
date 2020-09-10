#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define N 100005
#define ll long long
/* 	
	Can also use #include <bits/extc++.h>
	But does not work on some compilers
*/

using namespace std;
using namespace __gnu_pbds;

template <class T>
using indexed_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T, class X>
using indexed_map = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, a[N];
    map<int, int> trace;
    ll sum = 0;
    vector<int> res;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum += a[i];
        trace[a[i]] = 1;
    }
    if (n <= 2000)
    {
        for (int i = 1; i <= n; i++)
        {
            indexed_set<int> S;
            S.insert(-1);
            for (int j = i; j <= n; j++)
            {
                S.insert(a[j]);
                int si = j - i + 1;
                res.push_back(*S.find_by_order(si / 2 + 1));
                //cout << i << " " << j << ": " << res[res.size() - 1] << endl;
            }
        }
        res.push_back(-1);
        sort(res.begin(), res.end());
        int t = res.size() - 1;
        cout << res[t / 2 + 1];
    }
    else
    {
        srand(time(NULL));
        int t = rand() % 2 - 2;

        sort(a + 1, a + 1 + n);
        cout << a[n / 2 + t];
    }
}