
#include <bits/stdc++.h>
#define maxn 100005
#define ll long long
using namespace std;

ll a[maxn], res[maxn];
ll kq;
vector<int> b;
ll merge(ll l, ll r, ll mid)
{
    if (l == r)
        return 0;
    ll left[maxn], right[maxn];

    ll k = l;

    for (ll i = 1; i <= mid - l + 1; i++)
        left[i] = a[k++];

    for (ll i = 1; i <= r - mid; i++)
        right[i] = a[k++];
    k = l;

    ll i = 1, j = 1;

    while (i <= mid - l + 1 && j <= r - mid)
    {
        if (left[i] <= right[j])
            a[k] = left[i], i++;
        else
            a[k] = right[j], kq += mid + j - k, j++;

        k++;
    }

    while (i <= mid - l + 1)
        a[k++] = left[i++];
    while (j <= r - mid)
        a[k++] = right[j++];
    return 0;
}

int mergesort(ll l, ll r)
{
    //cout << endl << l << " " << r << endl;
    ll mid = (l + r) / 2;
    if (l < r)
    {
        mergesort(l, mid);
        mergesort(mid + 1, r);
    }
    merge(l, r, mid);
    return 0;
}
void debug(ll n)
{

    for (int i = 1; i <= n; i++)
        cout << a[i] << endl;
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);
    //freopen("D:\\c++\\cvip\\dnq-1\\4.in", "r", stdin);
    //freopen("4.out", "w", stdout);

    ll n, testcase, sum;
    cin >> testcase;

    while (testcase--)
    {
        kq = 0;
        cin >> n;
        for (ll i = 1; i <= n; i++)
            cin >> a[i];
        sum = 0;
        mergesort(1, n);
        //debug(n);
        cout << kq << endl;
    }
    return 0;
}
