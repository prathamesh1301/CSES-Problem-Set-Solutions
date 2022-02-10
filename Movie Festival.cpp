#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld double
int M=1e9+7;

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

bool comp(pair<int,int> a,pair<int,int> b){
    if(a.second==b.second)
        return a.first<b.first;
    return a.second<b.second;
}
void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> vi;
    for(int i=0;i<n;i++){
        int u,v;
        cin>>u>>v;
        vi.push_back({u,v});
    }
    sort(vi.begin(),vi.end(),comp);
    int ans = 1;
    int pre = vi[0].second;
    for(int i=1;i<n;i++){
        if(pre<=vi[i].first){
            ans++;
            pre = vi[i].second;
        }
    }
    cout<<ans<<endl;

}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    //memset(primes,true,sizeof(primes));
    //sieve();  
    //memset(dp,false,sizeof(dp));
    //precal();
    //int t;

    //cin>>t;

    //while(t--)
        solve();
    return 0;


}
