#include <iostream>
#include <string>
using namespace std;
int res[127];
int check(string a)
{
    int temp;
    for (int i = 0; i <= a.length() - 1; i++)
    {
        temp = a[i];
        res[temp]++;
    }
}

int main()
{
    for (int i=65;i<=122;i++)
        res[i]=0;
    string n;
    //cout << static_cast<char>(68) << static_cast<char>(43) << static_cast<char>(43) << endl;
    while (cin>>n)
    {

        check(n);
    }
    for (int i = 65; i <= 90; i++)
    {
        cout<<static_cast<char>(i)<<" "<<res[i]<<endl;
    }
    for (int i=97; i<=122;i++)
        cout<<static_cast<char>(i)<<" "<<res[i]<<endl;

    
}