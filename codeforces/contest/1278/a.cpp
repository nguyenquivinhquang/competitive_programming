#include <bits/stdc++.h>

using namespace std;
string sort_string(string a)
{
    for (int i = 0; i < a.length(); i++)
        for (int j = 0; j < a.length(); j++)
        if (a[i]>a[j]) swap(a[i],a[j]);
    return a;
}
bool Hoai_Thuong(string a, string b)
{
    int check[1000];
    int sl[1000];
    string temp="";
    a=sort_string(a);
    for (int i = 0; i < b.length(); i++)
    {
        temp="";
        for (int j = i; j < a.length() + i; j++)
        {
            temp=temp+b[j];
        }
        temp=sort_string(temp);
        if (a==temp) return true;
    }
    return false;
}
int main()
{
    int n, t;
    string a, b;
    cin >> t;
    for (int i=1;i<=t;i++)
    {
        cin>>a>>b;
        if (Hoai_Thuong(a,b)==true) cout<<"YES"; else cout<<"NO";
        cout<<endl;
    }
}