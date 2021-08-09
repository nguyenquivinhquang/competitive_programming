#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
int n;
vector<string> ans;
void dq(int i, int sum, string x)
{
    if (i == 9)
    {
        if (sum == n)
            ans.push_back(x);
    }
    else
    {
        string temp;
        ostringstream convert;
        convert << i + 1;
        temp = convert.str();

        string temp2="";
        dq(i + 1, sum + i + 1, x + "+" + temp);
        dq(i + 1, sum - i - 1, x + "-" + temp);
        int j;
        for ( j=x.length()-1;j>=0;j--)
            {
                if ((x[j]=='+')||(x[j]=='-')) break;
                temp2=x[j]+temp2;

            }
        int pheptinh=1;
        if (x[j]=='-') pheptinh=-1; 
        
        int sum2=0;
        for (int i=0;i<temp2.length();i++){
            sum2=sum2*10+temp2[i]-48;
        }
        
        int b=abs(((sum2 * 10 + (i + 1))))*pheptinh;
        sum2=sum2*pheptinh;
        dq(i + 1, (sum-sum2)+b, x + temp);
    }
}
int main()
{
    cin >> n;
    dq(1, 1, "1");
    for (auto it = ans.begin(); it != ans.end(); ++it) 
        cout <<*it<<endl; 
}