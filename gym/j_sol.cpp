#include <bits/stdc++.h>

using namespace std;
#define ll long long
vector<tuple<char, bool, char> > a;
vector<char> base;
map<char , int> pos;
int main()
{
    string s;
    for(int i = 1;i <= 5;i++){
        getline(cin, s);
        a.push_back(make_tuple(s[0] , s[1] == '>' , s[2]));
    }
    base.push_back('A');
    base.push_back('B');
    base.push_back('C');
    base.push_back('D');
    base.push_back('E');
    bool codapan = false;
    while(next_permutation(base.begin() , base.end())){
        bool bo = false;
        for(int i = 0;i < 5;i++)
            pos[base[i]] = i;
        for(int i = 0;i < 5;i++){
                char l = get<0>(a[i]) , r = get<2>(a[i]);
            bool x = get<1>(a[i]);
            if(x && pos[l] < pos[r]) bo = true;
            if(!x && pos[r] < pos[l]) bo = true;
        }
        if(!bo){
            for(int i = 0;i < 5;i++) cout << base[i];
            codapan = true;
            break;
        }
    }
    if(!codapan)cout << "impossible";
    return 0;
}
