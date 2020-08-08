#include <bis/stdc++.h>

using namespace std;

int main()
{
    int tescase;
    string a;
    cin >> tescase;
    while (tescase--)
    {
        int b[102], m = 0, res = 0;
        cin >> a;

        for (int i = 0; i < a.length(); i++)
            if (a[i] == '1')
                b[++m] = i;
        for (int i = 2; i <= m; i++)
            res += b[i] - b[i - 1] - 1;
        cout << res << endl;
    }
}