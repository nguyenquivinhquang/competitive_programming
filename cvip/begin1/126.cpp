#include <iostream>

using namespace std;
bool check(int x)
{
    if ((x % 2 == 0) || (x % 3 == 0) || (x % 5 == 0))
        return false;
    return true;
}

int main()
{
    int n; int j=0; int i=j;
    cin>>n;
    while (j<n){
        i++;
        if (check(i)==true) {
            cout<<i<<endl;;
            j++;
        }

    }

}