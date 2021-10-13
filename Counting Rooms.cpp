#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll M=1e9+7;

void dfs(vector<vector<char>>& a,int i,int j,int n,int m){
    if(i<0 || i>=m || j<0 || j>=n || a[i][j]!='.')return;
    a[i][j]='#';
    dfs(a,i,j+1,n,m);
    dfs(a,i,j-1,n,m);
    dfs(a,i+1,j,n,m);
    dfs(a,i-1,j,n,m);

}
void solve(){
    int m,n;
    cin>>m>>n;
    vector<vector<char>> a(m);
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            char c;
            cin>>c;
            a[i].push_back(c);
            
        }
    }
    int ct = 0;
    
    
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]=='.'){
                ct++;
                dfs(a,i,j,n,m);
            }
        }
    }
    cout<<ct<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //int t;
    //cin>>t;
    //while(t--)
        solve();



return 0;
}
