#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n, x; cin>>n>>x;
        vector<int> a;

        a.push_back(0);
        for(int i=0; i<n; i++){ 
            int ai;
            cin>>ai;
            a.push_back(ai);
        }
        int y = x - a[n];
        a.push_back(x+y);

        int maxi = INT_MIN;
        for(int i=0; i<a.size()-1; i++){
            int s = a[i+1]-a[i];
            maxi = max(s, maxi);
        }
        cout<<maxi<<endl;
    }
}