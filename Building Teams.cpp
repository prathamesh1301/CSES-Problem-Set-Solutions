#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
using vi = vector<int>;
#define pb push_back

bool checkBipartiteDfs(vector<int> a[],vector<int>&color,int node){
    if(color[node]==-1)
        color[node]=0;
    for(int i=0;i<a[node].size();i++){
        if(color[a[node][i]]==-1){
                color[a[node][i]]=1-color[node];
            if(!checkBipartiteDfs(a,color,a[node][i])) return false;

        }else if(color[a[node][i]]==color[node]) return false;
    }
    return true;
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
   vector<int> color(n+1,-1);
    int f=0;
    for(int i=1;i<=n;i++){
        if(color[i]==-1){
            if(!checkBipartiteDfs(adj,color,i)){
                f=1;
                cout<<"IMPOSSIBLE\n";
                break;
            }

        }
    }
    if(f==0){
        for(int i=1;i<=n;i++){
            if(color[i]==1)
                cout<<2<<" ";
            else if(color[i]==0)
                cout<<1<<" ";
        }
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
