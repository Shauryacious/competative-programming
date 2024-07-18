#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
	// your code goes here
    int t; cin>>t;
    while(t--){
      int n, k;
      cin>>n>>k;
      vector<int> v(n);
      
      int i = 0;
      while(i<n){
          if(i<=k/2){
              if(i%2 != 0){
                  v[i] = 2*i + 1;
              }
              else{
                  v[i] = 2*i;
              }
          }
          else{
            if(i< (k/2 + k/4)){
              v[i] = 2*i + 1;
            }
            else{
                v[i] = 2*i;
            }
          }
          i++;
      }

      for(int i=0; i<n; i++){
        cout<<v[i]<<" ";
      }

      cout<<endl;
    }
}