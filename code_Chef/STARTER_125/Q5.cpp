#include<iostream>
#include<vector>
using namespace std;

int main() {
	// your code goes here
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> v(n);
        int s = 0;
        for(int i=0; i<n; i++){
            cin>>v[i];
            s += v[i];
        }

        // for(int i=0; i<n; i++){
        //     cout<<v[i]<<" ";
        // }
        // cout<<s;
        
        if( s%2 != 0){ //odd
            cout<<"ALICE"<<endl;
        }
        else{
            if(n%2 != 0){
                cout<<"BOB"<<endl;
            }
            else {
                cout<<"DRAW"<<endl;
            }
        }
    }
}
