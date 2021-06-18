#include <bits/stdc++.h>
using namespace std;
const long long MOD= 1e9+7;
const int N = 1e6+10;


int main(){
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	int l=0;
	int r=n-1;
	int ans=0;
	while(l<=r){
		if(a[l]+a[r]>m){
			r--;
			ans++;
			//cout<<r<<endl;
		}
		else{
			//cout<<l<<" "<<r<<endl;
			l++;
			r--;
			ans++;
		}
		
	}
	cout<<ans<<endl;
   	return 0;
	
}
	
	
		
