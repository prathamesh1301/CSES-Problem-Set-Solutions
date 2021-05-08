#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin>>n;
    int a[n];
    set<int > s1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s1.insert(a[i]);
    }
        cout<<s1.size()<<"\n";


    return 0;
}


