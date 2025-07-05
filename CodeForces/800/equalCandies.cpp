//https://codeforces.com/problemset/problem/1676/B

#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin>>v[i];
        }

        sort(v.begin(), v.end());
        int cng = 0;
        for(int i=0; i<n; i++){
            cng += abs(v[i]-v[0]);
        }

        cout<<cng<<endl;
    }
}