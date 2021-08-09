#include <iostream>
#include <cmath>
#define ll long long
#define lf long double
using namespace std;

int main(){
    //fr("crypto.txt");
    //fw("out.txt");

    lf n,p,tmp,rs;
    ll intResult;

    while(cin >> n >> p){
        tmp = 1.0/(n*1.0);
        rs = pow(p*1.0,tmp);
        intResult = round(rs);
        cout << intResult << endl;
    }


    return 0;
}