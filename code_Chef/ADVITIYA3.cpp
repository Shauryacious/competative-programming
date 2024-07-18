#include<iostream>
#include<vector>
using namespace std;

int main() {
	// your code goes here
    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> v(n);
        vector<int> ans;
        for(int i=0; i<n; i++){
            cin>>v[i];
            if(v[i] >= k){
                int x = v[i]%k;
                ans.push_back(x);
            }
            else{
              ans.push_back(-1);
            }
        }
        int sol = INT_MAX;
        for(int i=0; i<n; i++){
          if(ans[i] < sol && ans[i] != -1){
            sol = ans[i];
          }
        }
        if(sol == INT_MAX) cout<<-1<<endl;
        else cout<<sol<<endl;
    }
}
