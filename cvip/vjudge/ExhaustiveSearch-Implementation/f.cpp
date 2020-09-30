#include <bits/stdc++.h>
#define N 2555
#define ll long long
#define pp pair<int,int>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
using namespace std;
int a[N], n, trace[100005], mode = -1, co = -1;
double mean = 0.0, median = 0.0;
int main()
{
    memset(trace, 0, sizeof(trace));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        trace[a[i]]++;
        mean += a[i];
    }
    printf("%.1lf\n", mean / n );
    sort(a + 1, a + 1 + n);
    if (n % 2 == 0)
        median = (a[n / 2] + a[n / 2 + 1]) / 2.0;
    else median = a[n / 2 + 1] / 2.0;
    printf("%.1lf\n", median);
    for (int i = 1; i <= 100000; i++)
        if (trace[i] > co)
        {
            mode = i, co = trace[i];
        }
    printf("%d\n", mode);
}