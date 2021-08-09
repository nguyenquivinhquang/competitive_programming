#include <iostream>

using namespace std;
int main()
{
    int n,a,b;
    cin>>n;
    for (int i=1;i<=n;i++){
        cin>>a>>b;
        cout<<a*b<<" "<<(a+b)*2<<endl;
    }
    
    return 0;
}