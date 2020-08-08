#include <iostream>
#include <string>
using namespace std;

int main()
{
    int h, r;
    cin >> r >> h;
    string mid, trai,phai;
    trai = "*";
    phai = "*"; mid=trai;
    for (int i = 2; i < r; i++)
    {
        trai = trai + " ";
        mid = mid + "*";
        phai=" "+phai;
    }
    trai += " ";
    mid += "*";
    phai=" "+phai;
    cout<<mid<<endl;
    for (int i=2;i<h/2+1;i++){
        cout<<trai<<endl;
    }
    cout<<mid<<endl;
    for (int i=h/2+2;i<h;i++){
        cout<<phai<<endl;
    }
    cout<<mid;  
}