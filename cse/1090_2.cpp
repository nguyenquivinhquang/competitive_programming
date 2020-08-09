#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#include <functional> // for less
#include <iostream>

using namespace __gnu_pbds;
using namespace std;

// a new data structure defined. Please refer below
// GNU link : https://goo.gl/WVDL6g
typedef tree<int, null_type, less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    new_data_set;

int main()
{
    new_data_set a;
    int n, x, temp;
    cin >> n >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        a.insert(temp);
    }
    cout << *a.find_by_order(3);
}