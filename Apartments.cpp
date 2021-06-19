#include <bits/stdc++.h>
using namespace std;
const long long MOD= 1e9+7;
const int N = 1e5+10;

int main(){

	int n,m,k;
	cin>>n>>m>>k;
	vector<long long> houses(n);
	vector<long long> app(m);
	
	for(int i=0;i<n;i++){
		cin>>houses[i];
	}
	
	for(int i=0;i<m;i++){
		cin>>app[i];
	}
	sort(houses.begin(),houses.end());
	sort(app.begin(),app.end());
	int i=0,j=0;
	int ans=0;
	while(i<n && j<m){
		if(abs(houses[i]-app[j])<=k){
			i++;
			j++;
			ans++;
		}
		else{
		if(houses[i]-app[j]>k)
			j++;
		else
			i++;
	}
	}
	cout<<ans<<endl;

	return 0;
	}

	
	

	
	
		
