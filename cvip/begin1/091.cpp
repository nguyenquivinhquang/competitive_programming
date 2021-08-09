    #include <iostream>
    #include <string>
    using namespace std;
    void aa(string x)
    {
        for (int i=0;i<=x.length()-1;i++)
            if (x[i]!=' ') cout<<x[i];
    }
    int main()
    {
        
        string n;
        while (getline(cin,n))
        {
            aa(n);
        }
    }