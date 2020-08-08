#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string t;
    string res = "";
    char a; int pos=0;
    for (int i = 1; i <= n; i++)
    {
        cin >> t >> a;
        res=""; pos=0;
        for (int i = 0; i < t.length(); i++)
            if (t[i] == a)
            {
                if (pos==0) cout<<i+1<<" ";
                pos=i;
                res = res + t[i];
                a=t[i+1];
            }

        cout << res << endl;
    }
}