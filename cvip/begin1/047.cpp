#include <iostream>

using namespace std;

int main(){
    long long res=0;
    for (int k=1;k<=10;k++){
        for (int l=1;l<=15;l++) res=res+(k-l)*(k-l)*k*k*k;
    }
    cout<<res;
}