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

vector<int> toVec(int n){
   vector<int> a;
   while(n>0){
      int r = n%10;
      a.push_back(r);
      n/=10;
   }
   return a;
}
int find(int n,vector<int>& dp){
   if(n==0)return 0;
   if(n<=9)return 1;
   if(dp[n]!=-1)return dp[n];
   vector<int> a = toVec(n);
   int ans = INT_MAX;
   for(int i=0;i<a.size();i++){
      if(n-a[i]>=0 && a[i]>0)
         ans = min(ans,1+find(n-a[i],dp));
   }
   return dp[n]=ans;
}
void solve(){
   int n;
   cin>>n;
   vector<int> dp(n+1,-1);
   cout<<find(n,dp);

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
