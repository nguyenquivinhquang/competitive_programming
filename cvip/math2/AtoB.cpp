#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#define mod %
#define maxn 100000
#define el '\n'
#define modulo 1000000007
#define ll long long
//111111111111111111111111111111111111111111111111111

using namespace std;
vector<ll> St(4 * maxn, 0);
vector<ll> a(maxn, 0);
int n;

void update(int id, int l, int r, int i, int v)
{
    if (i < l || i > r)
        return;
    if (l == r)
    {
        St[id] = v;
        return;
    }
    //cout<<id<<el;
    int mid = (l + r) / 2;
    update(id * 2, l, mid, i, v);
    update(id * 2 + 1, mid + 1, r, i, v);
    St[id] = (St[id * 2] * St[id * 2 + 1]) mod modulo;
}
void build(int id, int l, int r)
{
    if (l > r)
        return;
    if (l == r)
    {
        St[id] = a[l] mod modulo;
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    St[id] = ((St[id * 2] mod modulo)  * (St[id * 2 + 1]) mod modulo) mod modulo;
}
ll get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
    {
       
        return 1;
    }
    if (u <= l && r <= v)
    {
        return St[id] mod modulo;
    }
    int mid = (l + r) / 2;
    return (get(id * 2, l, mid, u, v)* get(id * 2 + 1, mid + 1, r, u, v)) mod modulo;
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    build(1, 1, n);
    int x, y, t, q;
    cin >> q;
   
    for (int i = 1; i <= q; i++)
    {
        cin >> t;
        if (t == 1)
        {
            cin >> x;
            cout <<(get(1,1,n,1,x-1)*get(1,1,n,x+1,n)) mod modulo << el; 
        } else
        {
            cin>>x>>y;
            update(1,1,n,x,y);
            a[x]=y;
        }
        
    }
}