#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
  long long int n, k; cin>>n>>k;

  if(n==1){
    cout<<n;
    return 0;
  }
  
  if(n%2 == 0){
    if(k > n/2){
      long long int ans = 2*(n-k);
      cout<<(n - ans);
    }
    else if(k <= n/2){
      cout<<(2*k - 1);
    }
  }
  else if(n%2 != 0){
    if( k == n){
      cout<<(n-1);
    }
    else if(k > n/2+1){
      long long int ans = 2*(n-k);
      cout<<(n-1 - ans);
    }
    else if(k <= n/2+1){
      cout<<(2*k-1);
    }
  }
}