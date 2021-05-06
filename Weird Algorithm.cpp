#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<ctype.h>
#include<algorithm>
using namespace std;
int main(){
    long long n;
    cin>>n;
    cout<<n<<" ";
    while(n!=1){
        if(n%2==0){
            n=n/2;
        }else{
            n=3*n + 1;
        }
        cout<<n<<" ";
    }
    return 0;
}
