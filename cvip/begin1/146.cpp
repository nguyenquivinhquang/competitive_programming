#include <iostream>
#include <string.h>
using namespace std;
long long format(string x)
{
    if (x=="mot") return 1;
    if (x=="hai") return 2;
    if (x=="ba") return 3;
    if (x=="bon") return 4;
    if (x=="tu") return 4;
    if (x=="nam") return 5;
    if (x=="sau") return 6;
    if (x=="bay") return 7;
    if (x=="tam") return 8;
    if (x=="chin") return 9;
    if (x=="khong") return 0;
    if ((x=="muoi")||(x=="nghin")||(x=="trieu")||(x=="ti")) return 0;
    if (x=="le") return 0;
    return 0;
}
long long don_vi(string x){
    if (x=="ty") return 1000000000;
    if (x=="trieu") return 1000000;
    if ((x=="ngan")||(x=="nghin")) return 1000;
    if (x=="tram") return 100;
}
int main()
{
    string a[20];
    
    int n=1;
    long long kq=0,temp=0;
    while (cin>>a[n])
    {
        
        n++;
    }
    n--;
    int i=1;
    while (i<=n)
    {
        if ((a[i]=="ty")||(a[i]=="trieu")||(a[i]=="ngan")||(a[i]=="nghin"))
        {
            temp=temp*don_vi(a[i]);
            kq=kq+temp;
            temp=0;
        } else if ((a[i]!="muoi") && (a[i] !="tram"))
        {
            temp=temp*10+format(a[i]);
        }
        i++; 
    }
    if (a[n]=="muoi") temp=temp*10;
    kq=kq+temp;
    
   cout<<kq; 

}