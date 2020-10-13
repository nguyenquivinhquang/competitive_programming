#include <bits/stdc++.h>
#define maxn 300005
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
void solve()
{
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);


    ll n, testcase, sum;
    string x;
    kq = 0;
    cin >> n >> x;
    set<int> t[500];
    for (int i = 0; i < n; i++)
        t[x[i]].insert(i);
    int b = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        a[++b] = *t[x[i]].begin();
        t[x[i]].erase(t[x[i]].begin());
    }

    sum = 0;
    mergesort(1, n);
    //debug(n);
    cout << kq << endl;
    return 0;
}