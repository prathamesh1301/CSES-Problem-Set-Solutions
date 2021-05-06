#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<ctype.h>
#include<algorithm>
#include <unordered_map>
using namespace std;
int main(){
    string s;
    cin>>s;
    int a[4];
    unordered_map<char, int> umap;
    umap['A']=0;
    umap['C']=0;
    umap['T']=0;
    umap['G']=0;
 
    int n=s.length();
    int i=0;
    while(i<n){
        char x=s[i];
        int j=i+1;
        int ct=1;
        while(j<n){
            if(x==s[j]){
                ct++;
                j++;
            }
            else{
                break;
            }
        }
        i=j;
        if(ct>umap[x])
            umap[x]=ct;
    }
    unordered_map<char, int>:: iterator p;
    int maxx=-1;
    for(p = umap.begin();p!=umap.end();p++){
        if(maxx<p->second)
            maxx=p->second;
    }
    cout<<maxx;
 
    return 0;
}
