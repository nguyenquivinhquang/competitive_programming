#include <bits/stdc++.h>
#define maxn 101
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define inputfile freopen(input.txt, r, stdin)
#define outputfile freopen(out.txt, w, stdout)
using namespace std;
int main()
{
    int testcase;
    string x;
    cin >> testcase;
    while (testcase--)
    {
        int count = 0, c1 = 0, c0 = 0;
        cin >> x;
        for (int i = 0; i < x.length(); i++)
            if (x[i] == '0')
                c0++;
            else
                c1++;
        count = min(c1, c0);
        if (count % 2 == 0)
            cout << "NET";
        else
            cout << "DA";
        cout << endl;
    }
}