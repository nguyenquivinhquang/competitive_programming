#include <bits/stdc++.h>
#define  pp pair<int, int>

using namespace std;
vector <pp> a;
vector <int> c(1000000,1);
int main()
{
    int n, x, y;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y;
        a.push_back({x, y});
    }
    sort(a.begin(), a.end());
    pp val={4,0};
    int res=0;  
    c[n-1]=1,c[n]=0;
    for (int i=n-2;i>=0;i--)
    {
        val={a[i].second,0};
        int pos = lower_bound(a.begin(), a.end(), val,[](pp lhs, pair<int, int> rhs) -> bool { return lhs.first < rhs.first; })-a.begin();
        c[i]=max(c[pos]+1,c[i+1]);
        res=max(res,c[i]);
    }
    cout<<res;

}