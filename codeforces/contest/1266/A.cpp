#include <bits/stdc++.h>

using namespace std;
int check(string x)
{
    int sum = 0;
    int count_2 = 0;
    int count_0 = 0;
    int t;
    for (int i = 0; i < x.length(); i++)
    {
        t = x[i] - 48;
        sum += t;
        if (t == 0)
        {
            count_0++;
            count_2++;
        } else
        {
            if (t%2==0) count_2++;
        }
        
    }
    if ((count_0 > 0) && (count_2 > 1) && (sum % 3 == 0))
        return 1;
    return 0;
}

int main()
{
    string x;
    int n;
    
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        int temp = check(x);
        if (temp == 1)
            cout << "red";
        else
            cout << "cyan";
        cout << endl;
    }
}
