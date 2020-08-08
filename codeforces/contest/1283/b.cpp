#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll cal(int n, int k)
{
    int res=n/k*k;
    res+=min(n%k,k/2);
    return res;
}
int main()
{
    //ifstream read("text.txt");
    //ofstream write("a2.txt");
    int t, n, k;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> k;
        cout << cal(n, k) << endl;
    }
}