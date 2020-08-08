#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string n;
    int sc, sl;
    sc = 0;
    sl = sc;
    int i;
    cin >> n;

    for (i = 0; i < n.length(); i++)
    {
        if ((n[i]-48)%2==0) sl=sl*10+n[i]-48; else sc=sc*10+n[i]-48;
    }
    cout<<sl<<" "<<sc<<endl;
    cout<<sl-sc;
}