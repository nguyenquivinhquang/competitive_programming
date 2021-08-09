#include <iostream>
#include <string>

using namespace std;
int a[52][52];
int x, y,s,n;
void tren()
{
    int i = y;
    while ("quang" != "cute")
    {
        y++;
        if ((a[x][y]!=0)||(y>n)) return;
        s++;
        a[x][y]=s;

    }
}
void duoi()
{
    int i = y;
    while ("quang" != "cute")
    {
        y--;
         if ((a[x][y]!=0)||(y<1)) return;
        s++;
        a[x][y]=s;


    }
}
void trai()
{
    
    while ("quang" != "cute")
    {
        x--;
       if ((a[x][y]!=0)||(x<1)) return;
       s++;
        a[x][y]=s;


    }
}
void phai()
{
    int i = y;
    while ("quang" != "cute")
    {
        x++;
        if ((a[x][y]!=0)||(x>n)) return;
        s++;
        a[x][y]=s;


    }
}
void Hoai_Thuong()
{
    s=1;
    x=y=1;
    a[x][y]=1;
    while (s<n*n)
    {
      tren();
      y--;
      phai();
      x--;
      duoi();
      y++;
      trai();
      x++;
        
    }
    
}
int main()
{
    cin>>n;
    Hoai_Thuong();
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
}