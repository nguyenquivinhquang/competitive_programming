#include <fstream>
#include <iostream>
#include<iomanip>
using namespace std;

int main()
{
    
    ifstream read("f.txt");
    ofstream write("g.txt");
    write<<fixed<<setprecision(5);
    int t;
    int n;
    read>>t;
    for (int i= 1; i <= t; i++)
    {
        read >> n;
        double sum = 0;
        double cal=1; double x;
        for (int j=1;j<=n;j++)
        {
            read>>x;
            sum+=x;
            cal*=x;
        }
        write<<sum<<" "<<cal<<endl;
    }
    write.close();

}