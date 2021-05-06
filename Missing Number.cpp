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
    long long a[n];
    long long summ=0;
    for(int i=0;i<n-1;i++){
        cin>>a[i];
        summ+=a[i];
    }
    long long sumN=(n*(n+1))/2;
    cout<<sumN-summ;
 
 
    return 0;
}
