#include <iostream>
#include <cmath>
#include <sstream>
#include <vector>
using namespace std;
bool check(int i)
{
    string temp;
    ostringstream convert;
    convert << i;
    temp = convert.str();
    int n = temp.length();
    int sl = 0;
    for (int i = 0; i < n / 2; i++)
    {
        if (temp[i] == temp[n - i - 1])
            sl++;
    }
    if (sl >= n / 2)
        return true;
    else
        return false;
}
int main(){
    for (int i=0;i<=1000000;i++)
        if (check(i)==true) cout<<i<<endl;
}