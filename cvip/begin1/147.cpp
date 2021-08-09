#include <iostream>

using namespace std;
long hoai_thuong(long x){
    if (x==0) return 0;
    if (x==1) return 1;
    if (x%2==0) x=hoai_thuong(x/2); else
    {
        x=hoai_thuong(x/2)+hoai_thuong(x/2+1);
    }
    return x;
    
}
int main()
{
    long n;
    
    while(cin >> n)
    cout<<hoai_thuong(n)<<endl;
}