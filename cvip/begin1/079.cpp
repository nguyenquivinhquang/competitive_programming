#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string t;
    string res;
    for (int i = 1; i <= n; i++)
    {
        cin >> t >> res;
        string temp = "";
        bool check=false;
        int l = res.length();
        int j = 0;
        while (j < t.length())
        {
            temp = "";
            for (int k = 0; k < l; k++)
                temp = temp + t[j + k];
            if (temp == res)
            {
                cout << j+1 << " ";
                check=true;
            }
            j++;
        }
        cout<<endl;
    }
}