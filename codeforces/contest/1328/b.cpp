#include <bits/stdc++.h>
#define maxn 1000
#define ll long long
using namespace std;
ll n, k;
void output(int posa, int posb )
{
    for (int i = 1; i <= n; i++)
        if ( i == posa || i == posb )
            cout << 'b';
        else cout << 'a';
    
    cout << endl;
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        cin >> n >> k;
        ll posa = 0, posb, tich = 0;
        while ( tich < k)
        {
            posa++;
            tich = ((posa + 1) * posa) / 2 ;
        }
        tich = ((posa - 1) * posa) / 2 ;
        output(n - posa, n - (-tich + k) + 1);
    }
}