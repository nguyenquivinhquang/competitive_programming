#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int,int>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
#define reset(a,val) memset(a,val,sizeof(a));
#define modulo int(1e9+7)
#define endl '\n'
using namespace std;
void solve()
{

}
int main()
{
    int count = 0;
    for (int i = 1; i <= 100000; i ++ )
        count += 100000 / i;
   	cout << count;
}