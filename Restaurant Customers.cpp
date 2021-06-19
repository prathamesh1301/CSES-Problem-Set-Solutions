#include <bits/stdc++.h>
using namespace std;
const long long MOD= 1e9+7;
const int N = 1e6+10;


int main(){
	int n;
	cin>>n;
	vector<pair<int,int>> a;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		a.push_back({x,1});
		a.push_back({y,-1});
	}
	sort(a.begin(),a.end());
	
	int ans=-1;
	int currentCustomer=0;
	for(int i=0;i<a.size();i++){
		currentCustomer+=a[i].second;
		if(currentCustomer>ans)
			ans=currentCustomer;
	}
	cout<<ans<<endl;

   	return 0;
	
	
}
	
	
		
