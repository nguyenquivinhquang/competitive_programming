#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T>
using indexed_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <class T, class X>
using indexed_map = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, t;
    char c;
    indexed_set<int> s;
    cin >> n;
    while (n--)
    {
        cin >> c >> t;
        if (c == 'I')
            s.insert(t);
        if (c == 'D')
            s.erase(t);
        if (c == 'K')
        {
            if (s.size() < t)
                cout << "invalid" << endl;
            else
                cout << *s.find_by_order(t - 1) << endl;
        }
        if (c == 'C')
            cout << s.order_of_key(t) << endl;
    }
}