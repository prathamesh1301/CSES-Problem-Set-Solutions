#include <bits/stdc++.h>
using namespace std;
 
long long maxd(long long a,long long b){
        if(a>b)
            return a;
        return b;
    }
int main(){
    long long n;
    cin>>n;
    long long a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    long long maxx=-1000000000;
    long long curr=-1000000000;
    for(int i=0;i<n;i++){
        curr=maxd(a[i],curr+a[i]);
        if(maxx<curr)
            maxx=curr;
 
}
cout<<maxx<<"\n";
    return 0;
}
