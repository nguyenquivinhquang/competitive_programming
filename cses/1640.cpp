#include <bits/stdc++.h>
#define pp pair<int,int>
#define ll long long
using namespace std;
vector <pp> a;
int n, x;
int binary_search(int value, int index)
{
    int mid, l = 1, r = n;
    while (l<=r)
    {
        mid = (l + r ) / 2;
        if (value == a[mid].first)
        {
            if (a[mid].second != index) return a[mid].second;
            mid-- ;
            if (mid == 0) return -1;
            if (a[mid].second != index && a[mid].first == value) return a[mid].second;
            mid += 2;
            if (mid > n) return -1;
            if (a[mid].second != index && a[mid].first == value) return a[mid].second;
            return -1;
        }
        else if (value < a[mid].first ) r = mid - 1;
        else l = mid + 1;
    }
    return -1;
}
int main()
{
    cin >> n >> x;
    int temp;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        a.push_back({temp, i});
    }
    a.push_back({-1, 0});
    sort(a.begin(), a.end());
    for (int i = 1; i <= n; i++)
    {
        int pos = binary_search(x - a[i].first, a[i].second);
        if (pos != -1)
        {
            if ( pos < a[i].second) swap(pos, a[i].second);
            cout << a[i].second << " " << pos;
            return 0;
        }
    }
    cout << "IMPOSSIBLE";
}
/*
4 8
2 7 5 1
*/