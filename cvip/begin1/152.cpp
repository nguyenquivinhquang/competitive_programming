#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
using namespace std;

long Dec_to_bin(long x)
{
    string res = "";
    while (x > 0)
    {
        if (x % 2 == 1)
            res = res + "1";
        else
            res = res + "0";
        x = x / 2;
    }
    stringstream geek(res); 
    int a = 0; 
    geek >> a;
    return a;
}
int main(){
    int n;
    while (cin>>n){
        cout<<Dec_to_bin(n)<<endl;
    }
}