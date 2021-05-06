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
    long long a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    long long ct=0;
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            long long diff=a[i]-a[i+1];
            ct+=diff;
            a[i+1]=a[i];
            }
 
    }
    cout<<ct;
    return 0;
}
