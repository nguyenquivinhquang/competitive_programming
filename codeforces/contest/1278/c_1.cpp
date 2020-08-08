#include <bits/stdc++.h>

using namespace std;

int n = 100001;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[2 * n];
        for (int i = 0; i < 2 * n; i++)
            cin >> a[i];
        int d = 0;

        for (int i = 0; i < 2 * n; i++)
        {
            if (a[i] == 1)
                d++;
            else
                d--;
        }

        map<int, int> freq;
        freq[0] = n - 1;
        int sum = 0;
        for (int i = n; i < 2 * n; i++)
        {
            sum += (a[i] == 1);
            sum -= (a[i] == 2);
            if (!freq.count(sum))
                freq[sum] = i;
        }

        int ans = freq.count(d) ? freq[d] - n + 1 : 2 * n;

        sum = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            sum += (a[i] == 1);
            sum -= (a[i] == 2);
            if (freq.count(d - sum))
                ans = min(ans, freq[d - sum] - i + 1);
        }

        cout << ans << endl;
    }

    return 0;
}