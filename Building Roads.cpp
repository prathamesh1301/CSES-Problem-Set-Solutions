#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
using vi = vector<int>;
#define pb push_back

void dfs(vector<int> adj[],int node,vector<bool>&vis){
    vis[node]=true;
    for(auto i:adj[node]){
        if(!vis[i])
            dfs(adj,i,vis);
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> adj[n+1];
    while(m--){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n+1,false);

    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            dfs(adj,i,vis);
            ans.push_back(i);
        }
    }
    cout<<ans.size()-1<<"\n";
    for(int i=0;i<ans.size()-1;i++){
        cout<<ans[i]<<" "<<ans[i+1]<<"\n";
    }


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
