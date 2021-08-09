#include <iostream>
#include <cmath>
#include <sstream>

using namespace std;
bool Hoai_Thuong(int i)
{
    string temp;
    ostringstream convert;
    convert << i;
    temp = convert.str();
    int n = temp.length();
    int sl = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (temp[i] == temp[n - i - 1])
            sl++;
    }
    if (sl >= n / 2)
        return true;
    else
        return false;
}

int main()
{
    int n; int res=0; int a;
    cin >>n;
    for (int i=1;i<=n;i++){
        cin>>a;
        if (Hoai_Thuong(a)==true) res=max(res,a);
    }

    cout<<res;
}