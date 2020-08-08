#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int a[1000];
    int n=0;
    string Hoai_Thuong;
    memset(a,0,sizeof(a));
    while (cin>>Hoai_Thuong){
        n++;
        a[Hoai_Thuong.length()]++;
    }
    cout<<n<<endl;
    for (int i=1;i<=10;i++)
        if (a[i]!=0)
            cout<<i<<":"<<a[i]<<endl;
}