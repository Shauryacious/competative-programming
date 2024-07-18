#include<iostream>
#include<vector>
using namespace std;

vector<int> vec(int n, int k){ //n=3 k=2
    bool flag = false;
    for(int GCD=n; GCD>0; GCD--){
        vector<int> v;
        cout<<GCD<<endl;
        for(int i=GCD; i<=n; i+=GCD){
          cout<<i<<endl;
            v.push_back(i);
            if(v.size() == k){
                flag = true;
                return v;
            }
        }
    }
    
    // if(flag == true) {
    //     for(int i=0; i<v.size(); i++){
    //         cout<<v[i];
    //     }
    // }
    //if(flag == false) return vector<int>();
}

int main() {
	// your code goes here
    int t; cin>>t;
    while(t--){
        int n, k; //n=3 k=2
        cin>>n>>k;
        
        // vector<int> v(n);
        // for(int i=0; i<n; i++){
        //     v[i] = i+1;
        // }
        
        // if(k > n){
        //   for(int i=0; i<k; i++){
        //       cout<<v[i];
        //       return 0;
        //   }  
        // }
        // bool flag = false;
        // for(int GCD=n; GCD>0; GCD--){
        //     vector<int> v;
            
        //     for(int i=GCD; i<=n; i+=GCD){
        //         v.push_back(i);
        //         if(v.size() == k){
        //             flag = true;
        //             break;
        //         }
        //     }
        // }
        
        // if(flag == true) {
        //     for(int i=0; i<v.size(); i++){
        //         cout<<v[i];
        //     }
        // }
        // else cout<<"";
        
        vector<int> subVec = vec(n, k);
        
        for(int i=0; i<subVec.size(); i++){
            cout<<subVec[i]<<" ";
        }
        
        cout<<endl;
    }
}
