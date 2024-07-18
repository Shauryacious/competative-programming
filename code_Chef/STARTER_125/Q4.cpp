#include<iostream>
using namespace std;

int main() {
	// your code goes here
    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string s; cin>>s;
        int count = 0;
        for(auto ele : s){
            if(ele == '1'){
                count++;
            }
        }

        // cout<<endl<<count<<endl;


        if(count > k){
            for(int i=0; i<n; i++){
              if(s[i] == '1' && k){
                  s[i] ='0'; 
                  k--;
              } 
            }
            cout<<s<<endl;
        }
        else{
            for(int i=0; i< n-k; i++){
                cout<<'0';
            }
            cout<<endl;
        }
        
        // while(k--){
        //     if(s.length() != 1) s.pop_back();
        // }
        
        

        
    }
}

