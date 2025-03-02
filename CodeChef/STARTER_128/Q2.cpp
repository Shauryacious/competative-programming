#include<iostream>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
       int n; cin>>n;
       vector<long long int> v(n);
       for(int i=0; i<n; i++){
           cin>>v[i]; 
       }
       cout<<is_sorted(v.begin(), v.end());
    }
}