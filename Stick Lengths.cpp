#include <bits/stdc++.h>
using namespace std;
const long long MOD= 1e9+7;
const int N = 1e5+10;

long long computeCost(long long arr[], int N, long long X)
{
    long long cost = 0;
    for (int i = 0; i < N; i++)
        cost += abs(arr[i] - X);
    return cost;
}
 
// Method to find minimum cost to make all
// elements equal
long long minCostToMakeElementEqual(long long arr[], int N)
{
    long long low, high;
    low = high = arr[0];
 
    // setting limits for ternary search by
    // smallest and largest element
    for (int i = 0; i < N; i++) {
        if (low > arr[i])
            low = arr[i];
        if (high < arr[i])
            high = arr[i];
    }
 
    /* loop until difference between low and high
       become less than 3, because after that
       mid1 and mid2 will start repeating
    */
    while ((high - low) > 2) {
 
        // mid1 and mid2 are representative array
        // equal values of search space
        long long mid1 = low + (high - low) / 3;
        long long mid2 = high - (high - low) / 3;
 
        long long cost1 = computeCost(arr, N, mid1);
        long long cost2 = computeCost(arr, N, mid2);
 
        // if mid2 point gives more total cost,
        // skip third part
        if (cost1 < cost2)
            high = mid2;
 
        // if mid1 point gives more total cost,
        // skip first part
        else
            low = mid1;
    }
 
    // computeCost gets optimum cost by sending
    // average of low and high as X
    return computeCost(arr, N, (low + high) / 2);
}

int main(){

	int n;
	cin>>n;
	long long a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	long long ans=minCostToMakeElementEqual(a,n);
	cout<<ans<<endl;


	return 0;
}

	
	

	
	
		
