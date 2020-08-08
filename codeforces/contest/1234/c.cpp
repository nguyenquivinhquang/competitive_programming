#include <bits/stdc++.h>

using namespace std;
string b[2];
int i, j, n, testcase;
int main()
{
    cin >> testcase;
    while (testcase --)
    {
        cin >> n;
        cin >> b[0] >> b[1];

        for (int i = 0; i < n; i++)
        {
            if (b[0][i] == '1' || b[0][i] == '2') b[0][i] = '1';
            if (b[1][i] == '1' || b[1][i] == '2') b[1][i] = '1';
            if (b[0][i] != '1' && b[0][i] != '2') b[0][i] = '3';
            if (b[1][i] != '1' && b[1][i] != '2') b[1][i] = '3';
        }
        i = 0, j = 0;
        while ( i < n )
        {
            if ( b[0][i] == '1' &&  b[1][i] == '1')
            {
                i++;
            }
            else if ( b[0][i] == '3' &&  b[1][i] == '3')
            {
                i++;
                if (j == 0) j = 1;
                else j = 0;
            }
            else if (b[j][i]=='1') i++; else  
            break;
        }
        if (i == n  && j == 1 ) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    memset()
}