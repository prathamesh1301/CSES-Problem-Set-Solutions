#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<ctype.h>
#include<algorithm>
#include <unordered_map>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long x,y;
        cin>>x>>y;
        long long ans;
        if(x>y){
 
            if(x%2==0){
                ans=(x*x)-y+1;
 
            }
            else{
                ans=((x-1)*(x-1))+y;
            }
            cout<<ans<<"\n";
        }else{
 
            if(y%2==0){
                ans=((y-1)*(y-1))+x;
            }else{
                ans=(y*y)-x+1;
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
