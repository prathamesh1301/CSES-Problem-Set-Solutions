#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007

char ar[1001][1001];
char br[1001][1001];
bool vis[1001][1001];
int n , m;
vector<char> path;
 
bool isValid(int x , int y){
    
    if(x < 1 || x > n || y < 1 || y > m) return false;
    
    if(ar[x][y] == '#' || vis[x][y] == true) return false;
    
    return true;
}
 
bool bfs(int x , int y)
{
    queue<pair<int,int> > q;
    q.push({x , y});
    vis[x][y] = true;
    
    while(!q.empty()){
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        
        if(ar[a][b] == 'B'){
            while(1){
                path.push_back(br[a][b]);
            
                if(path.back() == 'L') b++;
                if(path.back() == 'R') b--;
                if(path.back() == 'U') a++;
                if(path.back() == 'D') a--;
                
                if(a == x && b == y)
                break;
            }
            return true;
        }
        
        //left
        if(isValid(a , b - 1)) br[a][b-1] = 'L' , q.push({a , b-1}) , vis[a][b-1] = true;
        
        //right
        if(isValid(a , b + 1)) br[a][b+1] = 'R' , q.push({a , b+1}) , vis[a][b+1] = true;
        
        //up
        if(isValid(a - 1, b)) br[a - 1][b] = 'U' , q.push({a - 1 , b}) , vis[a-1][b] = true;
        
        //down
        if(isValid(a + 1, b)) br[a + 1][b] = 'D' , q.push({a + 1 , b}) , vis[a+1][b] = true;
        
    }
    
    return false;
}
void solve(){
   cin>>n>>m;
    int x;
    int y;
    
    REP(i , n) REP(j , m){
        cin>>ar[i][j];
        if(ar[i][j] == 'A') x = i , y = j;
    }
    
    if(bfs(x , y) == true){
        cout<<"YES"<<endl<<path.size()<<endl;
        while(path.size() > 0) cout<<path.back() , path.pop_back();
    }
    else{
        cout<<"NO";
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
