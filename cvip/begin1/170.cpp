#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    int Hoai_Thuong[300];
    cin >> a >> b;
    int point = 0;
    for (int i = 0; i < a.length(); i++)
    {
        if (a[i] == b[point])
        {
            Hoai_Thuong[point] = i;
            point++;
        }
    }
    
    if (point-1 == b.length()-1)
    {
        cout<<"true"<<endl;
        for (int i = 0; i < point; i++)
            cout<<Hoai_Thuong[i]<<" ";
    } else cout<<"false";
}