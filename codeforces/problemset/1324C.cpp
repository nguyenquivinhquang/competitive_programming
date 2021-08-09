    #include <bits/stdc++.h>

    using namespace std;
    int testcase;
    int main()
    {
        cin >> testcase;
        char temp;
        string a;

        while (testcase--)
        {
            int pre = 0, res = 1;
            cin >> a;
            a = '1' + a + 'R';
            for (int i = 1; i < a.length(); i++)
            {
                if (a[i] == 'R')
                {
                    res = max(res, i - pre);
                    pre = i;
                }
            }
            cout << res << endl;
        }
    }