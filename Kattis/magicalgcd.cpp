#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#define el '\n'
#define mod %
#define ll long long
#define maxn 100000

/*12111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111*/
using namespace std;
int n = 0, m = 0;

ll Gcd(ll x, ll y)
{
    if (x < y)
        swap(x, y);
    ll r = x;
    while (y!=0)
        r = x mod y, x = y, y = r;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    //cout<<Gcd(30,60);
    ll t, test, x, res, g;
    cin >> t;

    while (t--)
    {
        cin >> n;
        map<ll, int> r;
        res = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> x;
            map<ll, int> p;
            res = max(res, x);
            p[x] = i;
            for (map<ll, int>::iterator it = r.begin(), jt; it != r.end(); it++)
            {
                g = Gcd(it->first, x);
                res = max(res, g * (i - it->second + 1));

                //cout << g << " " << i - it->second + 1 << el;

                jt = p.find(g);
                if (jt != p.end())
                    jt->second = min(jt->second, it->second);
                else
                    p[g] = it->second;
            }
            r = p;
            //cout<<"------"<<endl;
        }
        cout << res << el;
    }
}