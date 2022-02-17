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
   int n,k;
   cin>>n>>k;
   vector<int> price(n);
   vector<int> pages(n);
   for(int i=0;i<n;i++)
      cin>>price[i];
   for(int i=0;i<n;i++)
      cin>>pages[i];
   int dp[n+1][k+1];
   for(int i=0;i<=n;i++)
      dp[i][0]=0;
   for(int i=0;i<=k;i++)
      dp[0][i]=0;
   for(int i=1;i<=n;i++){
      for(int j=1;j<=k;j++){
         if(price[i-1]<=j)
            dp[i][j] = max(pages[i-1]+dp[i-1][j-price[i-1]] , dp[i-1][j]);
         else
            dp[i][j] = dp[i-1][j];
         
      }
   }
   cout<<dp[n][k]<<endl;

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
