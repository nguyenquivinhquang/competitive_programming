#pragma GCC optimize("O3")
#pragma GCC optimization("unroll-loops")
#include <bits/stdc++.h>
#define maxn 1000
#define ll long long
using namespace std;

int a[maxn], res[maxn];
int kq;
vector<int> b;
int merge(int l, int r, int mid)
{
    if (l == r)
        return 0;
    int left[maxn], right[maxn];

    int k = l;

    for (int i = 1; i <= mid - l + 1; i++)
        left[i] = a[k++];

    for (int i = 1; i <= r - mid; i++)
        right[i] = a[k++];
    k = l;

    int i = 1, j = 1;

    while (i <= mid - l + 1 && j <= r - mid)
    {
        if (left[i] <= right[j])
            a[k] = left[i], i++;
        else
            a[k] = right[j], kq += mid + j - k, j++;

        k++;
    }

    while (i <= mid - l + 1)
        a[k] = left[i++];
    while (j <= r - mid)
        a[k] = right[j++];
    return 0;
}

int mergesort(int l, int r)
{
    //cout << endl << l << " " << r << endl;
    int mid = (l + r) / 2;
    if (l < r)
    {
        mergesort(l, mid);
        mergesort(mid + 1, r);
    }
    merge(l, r, mid);
    return 0;
}
void debug(int n)
{

    for (int i = 1; i <= n; i++)
        cout << a[i] << endl;
}
int main()
{

    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // freopen("D:\\c++\\cvip\\dnq-1\\4.in", "r", stdin);
    // freopen("4.out", "w", stdout);

    int n, testcase, sum;
    cin >> testcase;

    while (testcase--)
    {
        kq = 0;
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        sum = 0;
        mergesort(1, n);
        //debug(n);
        cout << kq << endl;
    }
    return 0;
}