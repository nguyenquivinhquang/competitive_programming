#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

bool mark[1000000];
void eratos()
{
    for (int i = 2; i * i <= 1000000; i++)
    {
        if (mark[i])
        {
            for (int j = i * i; j <= 1000000; j += i)
            {
                mark[j] = false;
            }
        }
    }
}
int main()
{
    
    memset(mark,true,1000000);
    eratos();
    mark[1]=false;
    int n;
    cin>>n;
    int j=0;
    while (n>0){
        j++;
        if (mark[j]==true ){
            cout <<j<<endl;
            n--;
        }
    }

}