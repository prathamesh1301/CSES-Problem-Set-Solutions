#include <bits/stdc++.h>
using namespace std;
const long long MOD= 1e9+7;
const int N = 1e5+10;


int main(){


	long long n,target;
	cin>>n>>target;
	vector<int> arr(n);
	map<int,int> mp;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		mp.insert({arr[i],i+1});
	}
	vector<int> ans;
	for(int i=0;i<n;i++){
		long long diff=target-arr[i];
		if(mp.count(diff)){
			if(mp[diff]==i+1)
				continue;
			ans.push_back(i+1);
			ans.push_back(mp[diff]);
			break;
		}
	}
	if(ans.size()>0){
		sort(ans.begin(),ans.end());
		cout<<ans[0]<<" "<<ans[1]<<endl;
	}
	else{
		cout<<"IMPOSSIBLE"<<endl;
	}
	




	
   	return 0;
	}
	
	

	
	
		
