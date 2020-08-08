#include <bits/stdc++.h>
#define maxx 1000009
#define ss set<int>
using namespace std;
int a[200];
vector<ss> c(200);
ss y;
void reset()
{
    for (int i = 2; i <= 199; i++)
        a[i] = -1;
}
bool pre(string &x)
{
    bool check_temp = false;
    int bd,kt;
    int temp = x[0];
    if (c[temp].size() == 0)
        return false;
    
    int pos = -1;
    for (int i = 0; i < x.length(); i++)
    {
        int temp = x[i];
        check_temp = false;
        
        for (auto j : c[temp])
        {
            if (j > pos)
            {
                pos = j;
                check_temp = true;
                break;
            }
        }
        if (i==0) bd=pos;
        if (check_temp == false)
            return false;
    }
    cout << "Matched "<<bd<<" "<<pos;
    return true;
}
int main()
{
    //freopen("output.txt","w",stdout);
    string x;
    int n, index;
    char temp;
    cin >> x;

  

    for (int i = 0; i < x.length(); i++)
    {
        index = x[i];

        c[index].insert(i);
    }
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        bool check = true;
        int pos = 0;
        if (pre(x) == false)
            cout << "Not matched";
        cout << endl;
    }
}