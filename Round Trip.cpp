#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
using vi = vector<int>;
#define pb push_back

bool dfs(vector<int> adj[], vector<bool>& vis,int node,vector<int>& ans,int par){
    vis[node] = true;
    ans.push_back(node);
    for(auto k:adj[node]){
        if(!vis[k]){

            if(dfs(adj,vis,k,ans,node)) return true;
        }
        else if(par != k){
            ans.push_back(k);
            return true;
        }
    }
    ans.pop_back();
    return false;
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
    bool f = false;
    for(int i=1;i<=n;i++){

        if(!vis[i]){
            if(dfs(adj,vis,i,ans,-1)){
                int size = ans.size();
                vector<int> tmp;
                tmp.push_back(ans[size-1]);
                for(int i=size-2;i>=0;i--){
                    if(ans[size-1]==ans[i]){
                        tmp.push_back(ans[i]);
                        break;
                    }
                    else
                        tmp.push_back(ans[i]);
                }
                f =true;
                
                cout<<tmp.size()<<endl;
                
                for(int i=0;i<tmp.size();i++){
                    cout<<tmp[i]<<" ";
                }
                cout<<endl;
                break;
            }
        }

    }
    if(!f)
        cout<<"IMPOSSIBLE\n";
        
    

    

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
