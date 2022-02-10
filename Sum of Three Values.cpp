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
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    unordered_map<int,vector<int>> mp;
    unordered_map<int,bool> ump;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]].push_back(i+1);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n-2;i++){
        int to_find = k - a[i];
        int lo = i+1;
        int hi = n-1;
        while(lo<hi){
            int sm = a[lo]+a[hi];
            if(sm==to_find){
                vector<int> ans(3);
                for(auto k:mp[a[i]]){
                    if(!ump[k]){
                        //cout<<k<<endl;
                        ans[0]=k;
                        ump[k]=true;
                        break;
                    }
                }
                for(auto k:mp[a[lo]]){
                    if(!ump[k]){
                        //cout<<k<<endl;
                        ans[1]=k;
                        ump[k]=true;
                        break;
                    }
                }
                for(auto k:mp[a[hi]]){
                    if(!ump[k]){
                        //cout<<k<<endl;
                        ans[2]=k;
                        ump[k]=true;
                        break;
                    }
                }
                
                sort(ans.begin(),ans.end());
                cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
                return;
            }
            else if(sm>to_find)hi--;
            else
                lo++;
        }
    }
    cout<<"IMPOSSIBLE\n";
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
