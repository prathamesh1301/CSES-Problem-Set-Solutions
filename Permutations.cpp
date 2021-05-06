#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<ctype.h>
#include<algorithm>
#include <unordered_map>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> o;
    vector<int> e;
    if(n==3 || n==2)
        cout<<"NO SOLUTION";
    else if(n==1)
            cout<<"1";
    else{
    for(int i=1;i<n;i++){
        if(i%2==0)
            e.push_back(i);
        else
            o.push_back(i);
    }
    if(n%2==0){
        for(int i=0;i<e.size();i++)
        cout<<e[i]<<" ";
 
        cout<<n<<" ";
        for(int i=0;i<o.size();i++)
            cout<<o[i]<<" ";
        }
        else{
            for(int i=0;i<e.size();i++)
        cout<<e[i]<<" ";
 
 
    for(int i=0;i<o.size();i++)
        cout<<o[i]<<" ";
 
        cout<<n<<" ";
    }
        }
 
    return 0;
}
