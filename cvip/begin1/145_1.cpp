#include <iostream>

using namespace std;

int a[100];
int n = 0;
string chu_so(int x)
{
    string temp;
    if (x == 1)
        temp = "mot";
    if (x == 2)
        temp = "hai";
    if (x == 3)
        temp = "ba";
    if (x == 4)
        temp = "bon";
    if (x == 5)
        temp = "nam";
    if (x == 6)
        temp = "sau";
    if (x == 7)
        temp = "bay";
    if (x == 8)
        temp = "tam";
    if (x == 9)
        temp = "chin";
    if (x == 0)
        temp = "khong";
    return temp;
}
string read_digit(int x)
{
    string kq;
    if (x >= 100)
    {
        kq = kq + chu_so(x / 100) + " tram";
        x = x % 100;
    }
    if (x >= 10)
    {

        if ((x / 10) != 1)
            kq = kq + " " + chu_so(x / 10) + " muoi";
        else
            kq = kq + " muoi";

        x = x % 10;
    }
    if (x <= 10)
        kq = kq + " " + chu_so(x);
    while (kq[0] == ' ')
    {
        kq.erase(0, 1);
    }
    return kq;
}
string hihi(int i)
{
    if (i==1) return "";
    if (i==2) return "nghin";
    if (i==3) return "trieu";
    if (i==4) return "ti";
    if (i==5) return "ti ti";
}
void cal_digit(long long x)
{
    while (x > 0)
    {
        a[n] = x % 1000;
        x = x / 1000;
        n++;
    }
    n--;
    
}
int main()
{
    long long quangcute;
    //cout << read_digit(118);
    cin>>quangcute;
    cal_digit(quangcute);
    for (int i=n;i>=0;i--)
        cout<<read_digit(a[i])+" "+hihi(i+1)+" ";
            
}