#include <iostream>
#include <string>
using namespace std;
string a[1000];
int n;
void string_sort()
{
    string temp;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if ((i != j) && (a[i] < a[j]))
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
}
int main()
{
    string t;
    n=0;
    while (cin>>t){
        n++;
        a[n]=t;
    }
    string_sort();
    for (int i=1;i<=n;i++)
        cout<<a[i]<<endl;
    
   

}