#include <iostream>

using namespace std;
int day, year, month;
int cal_date()
{
    int count;
    count = (year - 2000) * 365+(year-1996)/4;
    for (int i = 1; i < month; i++)
    {
        if (i % 2 == 0)
            day = day + 30;
        else
            day += 31;
    }
    day = day - 1;
    if (month > 2)
        day = day - 2;
    count = count + day;
    return count;
}
void print(int x)
{
    
    if (x==1) cout<<"Monday";
    if (x==2) cout<<"Tuesday";
    if (x==3) cout<<"Wednesday";
    if (x==4) cout<<"Thursday";
    if (x==5) cout<<"Friday";
    if (x==6) cout<<"Saturday";
    if (x==0) cout<<"Sunday";
}
int main()
{
    day = 4;
    month = 1;
    year = 2004;
    cout<<cal_date();
}