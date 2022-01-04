#include<bits/stdc++.h>// bài 33
using namespace std;
int testcase;
 
int main(){
    cin>>testcase;
    for(int test=1;test<=testcase;test++){
        int n,x;
        cin>>n;
        int arr[1000];
        int dem=0;
        for(int i=1;i<=n;i++){
            cin>>x;
            arr[i]=x;
 
            if(x % 5 == 0 && x % 7 != 0){
                dem++;
            }
            
        }  
        cout << dem << " " << x << "\n";
 
 
    }
 
 return 0;
}