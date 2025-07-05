#include<iostream>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n = s.length();
        int count = 1, k=1;
        for(int i=0; i<n-1; i++){
            if((s[i]=='0' && s[i+1]=='1') && k){
                count--;
                k--;
                //
            }
            if(s[i] != s[i+1]){
                ///
                count++;
            }
        }
        cout<<count<<endl;
    }
}