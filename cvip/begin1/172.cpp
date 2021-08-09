#include <iostream>
#include <string>

using namespace std;
struct Hoai_Thuong
{
    string name;
    string address;
    int count ;
};
void write(Hoai_Thuong ticket)
{
    cout << ticket.name << endl;
    cout << ticket.address << endl;
    cout << ticket.count << endl;
}

Hoai_Thuong a[100];
int n=1;

bool check(Hoai_Thuong temp)
{
    for (int i=1;i<=n;i++){
        if (a[i].name==temp.name) return false;
    }
    return true;
}
int main()
{
    Hoai_Thuong temp;
    string hih;
    while (getline(cin,temp.name))
    {
        getline(cin,temp.address);
        cin>>temp.count;
        if (check(temp)==true)
        {
            a[n]=temp;
            n++;
        }
        getline(cin,hih);
    }
    
    for (int i=1;i<n;i++){
        write(a[i]);
    }
}