#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m, testcase;
    cin >> testcase;
    while (testcase -- )
    {
        cin >> n >> m;
        if (n == 1 || m == 1 )
            cout << "YES";
        else if (n == 2 && m == 2)
            cout << "Yes";
        else cout << "No";
        cout << endl;

    }
}