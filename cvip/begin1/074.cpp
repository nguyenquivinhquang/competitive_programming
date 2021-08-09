#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string t;
    string res = "";
    char a;
    int pos = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> t >> a;
        res = "";   
        pos = 0; int j=t.length();
        while ("quang" != "cute")
        {
            res=t[j]+res;
            if (t[j]==a) {
                cout<<j+1<<" "<<res<<endl;
                break;
            }
            j--;
        }

        
    }
}