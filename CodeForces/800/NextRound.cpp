#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
  int n, k;
  cin>>n>>k;
  vector<int> v(n);
  for(int i=0; i<n; i++){
    cin>>v[i];
  }


  int count = 0, sum=0;
  for(int i=0; i<n; i++){
    sum += v[i];
    if(v[i] >= v[k-1] && v[i]!= 0) count++;
  }
  if(sum != 0) cout<<count;
  else cout<<0;
}