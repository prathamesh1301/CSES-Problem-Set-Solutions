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
    int N;
    cin>>N;
    vector<pair<pair<int,int>,int>> v(N);
    vector<int> ans(N,-1);
    for (int i = 0; i < N; i++) {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = i; // store the original index
    }
    sort(v.begin(), v.end());

    int rooms = 0, last_room = 0;
    priority_queue<pair<int, int>> pq; // min heap to store departure times.
    for (int i = 0; i < N; i++) {
        if (pq.empty()) {
            last_room++;
            // make the departure time negative so that we create a min heap
            // (cleanest way to do a min heap... default is max in c++)
            pq.push(make_pair(-v[i].first.second, last_room));
            ans[v[i].second] = last_room;
        }
        else {
            // accessing the minimum departure time
            pair<int, int> minimum = pq.top();
            if (-minimum.first < v[i].first.first) {
                pq.pop();
                pq.push(make_pair(-v[i].first.second, minimum.second));
                ans[v[i].second] = minimum.second;
            }

            else {
                last_room++;
                pq.push(make_pair(-v[i].first.second, last_room));
                ans[v[i].second] = last_room;
            }
        }

        rooms = max(rooms, int(pq.size()));
    }


    cout << rooms << "\n";
    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }
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
