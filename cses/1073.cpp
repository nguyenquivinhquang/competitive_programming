#include <bits/stdc++.h>
using namespace std;
multiset<int> s;
int main()
{
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        auto it = s.lower_bound(x + 1);
        if (it == s.end()) s.insert(x);
        else
        {
            s.erase(it);
            s.insert(x);
        }
    }
    cout << s.size() << endl;
}