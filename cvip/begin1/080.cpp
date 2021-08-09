#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string t;
    string res, b;
    for (int i = 1; i <= n; i++)
    {
        cin >> t >> res >> b;
        string temp = "";
        bool check = false;
        int l = res.length();
        int j = 0;
        while (j < t.length())
        {
            temp = "";
            int k = 0;
            for (k = 0; k < l; k++)
                temp = temp + t[j + k];
            if (temp == res)
            {
                for (int c = 0; c < j; c++)
                    cout << t[c];
                cout << b;
                for (int c = j + k; c < t.length(); c++)
                    cout << t[c];
                check=true;
                break;
            }
            j++;
        }
        if (check==false) cout<<t;
        if (i != n)
            cout << endl;
    }
}