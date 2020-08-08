#include <iostream>
#include <string>
using namespace std;

string Hoai_Thuong(string x)
{
    if (x[x.length() - 1] == 'y')
    {
        x.erase(x.length() - 1, 1);
        x = x + "ies";
        return x;
    }
    if (x[x.length() - 1] == 's')
    {
        
        x = x + "es";
        return x;
    }
    string temp = "";
    temp = temp + x[x.length() - 2] + x[x.length() - 1];
    if ((temp == "ch") || (temp == "sh"))
    {
       
        x = x + "es";
        return x;
    }
    x=x+"s";
    return x;
}
int main()
{
    string x;
    while (cin>>x){
        cout<<Hoai_Thuong(x)<<endl;
    }
}