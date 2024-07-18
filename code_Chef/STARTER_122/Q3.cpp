#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main() {
	// your code goes here
  int t; cin>>t;
  while(t--){
    vector<int> v(22);

    for(int i=0; i<22; i++){
      int a; cin>>a;
      int b; cin>>b;
      v[i] = a + b*20;
    }

    int max_idx = -1;
    int curr_max = INT_MIN;
    for(int i=0; i<22; i++){
      if(v[i] > curr_max){
        curr_max = v[i];
        max_idx = i;
      } 
    }

    cout<<max_idx+1<<endl;
  }
}