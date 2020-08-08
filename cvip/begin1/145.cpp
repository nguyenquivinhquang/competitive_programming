#include <iostream>
using namespace std;
 
const char mau[10][7] = { "khong ","mot ","hai ","ba ","bon ","nam ",
"sau ", "bay ", "tam ","chin " };
 
int c[10];
long n;

 
void get(int vt)
{
    if (vt == 7) return;
    switch (vt)
    {
    case 1: cout << "trieu ";
        break;
    case 4:
        if (!((c[vt] == 0) && (c[vt - 1] == 0) && (c[vt - 2] == 0)))
        cout << "nghin ";
        break;
    case 2:
        if (!(((c[vt + 2] == 0) && (c[vt + 1] == 0)) && (c[vt] == 0)))
            cout << "tram ";
        break;
    case 5:
        if (!(((c[vt + 2] == 0) && (c[vt + 1] == 0)) && (c[vt] == 0)))
            cout << "tram ";
        break;
 
    case 3: case 6:
        if (c[vt] != 0)
            cout << "muoi ";
        else
        {
            if (c[vt + 1] != 0)
                cout << "le ";
        }
        break;
    }
}
 
void so_to_mang() 
{
    int i;
    for (i = 1; i <= 7; i++)
        c[i] = 0;
    i = 7;
    while (n != 0)
    {
        c[i] = n % 10;
        n = n / 10;
        i--;
    }
}
 
void docso(long n)
{
    so_to_mang();
    int vtd = 8, i;
    for (i = 1; i <= 7; i++)
        if (c[i] != 0)
        {
            vtd = i;
            break;
        }
    if (vtd == 8)
    {
        cout << "khong";
        return;
    }
    for (i = vtd; i <= 7; i++)
    {
        
        switch (c[i])
        {
        case 1: case 2: case 3: case  4: case  6: case 7: case 8: case 9:
            if (!((c[i] == 1) && ((i == 6) || (i == 3))))
                cout << mau[c[i]];
            get(i);
            break;
        case 5:
            if (i == 7)
            {
                if (c[i - 1] == 0)
                    cout << "nam ";
                else
                    cout << "nam ";
            }
            else
            {
                if (i == 4)
                {
                    if (c[i - 1] == 0)
                        cout << "nam ";
                    else
                        cout << "nam ";
                }
                else
                    cout << mau[c[i]];
                get(i);
            }
            break;
        case 0:
            if (((i == 5) || (i == 2)) && ((c[i + 2] != 0) || ((c[i + 1] != 0))))
                cout << mau[c[i]];
            get(i);
            break;
        }
    }
}
 
void nhapdl() 
{
    cin>>n;
}
 
int main()
{
    nhapdl();
    docso(n);
    cout << endl;

    return 0;
}