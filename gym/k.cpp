#include <bits/stdc++.h>
#define maxn 100002
using namespace std;
string a, b;
vector <char> x,y;
bool check(vector<char> &x, vector<char> &y)
{
    if (x.size()==0) return 1;
    bool check=true;
    for (int i=1;i<x.size();i++)
    {
        if (x[i]!=y[i-1])
            check=false;
    }
    if (check==true) return check;
    return 1;
}
int main()
{
    int testcase, n;
    char temp;
    cin >> testcase;
    while (testcase--)
    {
        x.clear(),y.clear();
        cin >> n;
        cin >> a;
        cin >> b;
        for (int i = 0; i < a.length(); i++)
            if (a[i] != b[i])
            {
                x.push_back(a[i]);
                y.push_back(b[i]);
            }
        //cout << x << " " << y;
        if (check(x, y) == 1)
            cout << "YES";
        else
            cout << "NO";
        cout << "\n";
    }
}