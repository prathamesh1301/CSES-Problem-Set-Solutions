#include <bits/stdc++.h>
using namespace std;
#define MAX 1000
 
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
        string ans="";
        if(x>y){
            int t=x;
            x=y;
            y=t;
        }
        if(2*x<y)
            ans="NO";
        else{
            x%=3;
            y%=3;
            if((x==0 && y==0) || (x==2 && y==1) || (x==1 && y==2 ))
                ans="YES";
            else
                ans="NO";
        }
        cout<<ans<<endl;
    }
          return 0;
    }
