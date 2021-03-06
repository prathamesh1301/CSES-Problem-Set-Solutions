// Memoization
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld double
int mod=1e9+7;

const int array_size = 1e6+100;
bool primes[array_size];

ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
ll lcm(ll a, ll b){return ((a/gcd(a,b))*b);}
void sieve(){
  
   primes[0] = false;
   primes[1] = false;
   for(ll i = 2;i*i<=array_size;i++){
      if(primes[i]){
         for(ll j=i*i;j<=array_size;j+=i)
            primes[j] = false;
      }
   }
}

int find(vector<vector<char>>& a,int i,int j,int n,vector<vector<int>>& dp){
   if(i<0 || j<0 || i>=n || j>=n || a[i][j]=='*')return 0;
   if(dp[i][j]!=-1)return dp[i][j];
   if(i==n-1 && j==n-1)return 1;
   return dp[i][j] = (find(a,i+1,j,n,dp)+find(a,i,j+1,n,dp))%mod;
}
void solve(){
   int n;
   cin>>n;
   vector<vector<char>> a(n,vector<char>(n));
   vector<vector<int>> dp(n,vector<int>(n));
   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         cin>>a[i][j];
         dp[i][j]=-1;
      }
   }
   
   cout<<find(a,0,0,n,dp);
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    //memset(primes,true,sizeof(primes));
    //sieve();  
    //memset(dp,false,sizeof(dp));
    //precal();
    /*int t;

    cin>>t;

    while(t--)*/
        solve();
    return 0;


}

//Tabulation Approach:
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld double
int mod=1e9+7;

const int array_size = 1e6+100;
bool primes[array_size];

ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
ll lcm(ll a, ll b){return ((a/gcd(a,b))*b);}
void sieve(){
  
   primes[0] = false;
   primes[1] = false;
   for(ll i = 2;i*i<=array_size;i++){
      if(primes[i]){
         for(ll j=i*i;j<=array_size;j+=i)
            primes[j] = false;
      }
   }
}

void solve(){
   int n;
   cin>>n;
   vector<vector<char>> a(n,vector<char>(n));
   vector<vector<int>> dp(n,vector<int>(n));

   for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
         cin>>a[i][j];
      }
   }
   if(a[n-1][n-1]=='*'){
      cout<<0<<endl;
      return;
   }
   dp[n-1][n-1]=1;
   for(int i=n-2;i>=0;i--){
      if(a[i][n-1]=='*'){
         dp[i][n-1] = 0;
         
      }
      else{
         dp[i][n-1] = dp[i+1][n-1];
         
      }
   }
   for(int i=n-2;i>=0;i--){
      if(a[n-1][i]=='*'){
         dp[n-1][i] = 0;
         
      }
      else{
         dp[n-1][i] = dp[n-1][i+1];
         
      }
   }
   for(int i=n-2;i>=0;i--){
      for(int j=n-2;j>=0;j--){
         if(a[i][j] == '*')
            dp[i][j]=0;
         else
            dp[i][j] = (dp[i+1][j]+dp[i][j+1])%mod;
      }
   }
   cout<<dp[0][0];

}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    //memset(primes,true,sizeof(primes));
    //sieve();  
    //memset(dp,false,sizeof(dp));
    //precal();
    /*int t;

    cin>>t;

    while(t--)*/
        solve();
    return 0;


}
