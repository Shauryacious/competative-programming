#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
  int n; cin>>n;
  vector<int> arr(n);
  int max_sum = 0;
  for(int i=0; i<n; i++){
    cin>>arr[i];
    max_sum += arr[i];
  }

  sort(arr.begin(), arr.end());

  int count = 0;
  int half_sum = 0;
  for(int i=n-1; i>=0; i--){
    if(half_sum > max_sum/2){
      cout<<count;
      break;
    }
    half_sum += arr[i];
    count++;
    if(half_sum > max_sum/2){
      cout<<count;
      break;
    }
  }
}