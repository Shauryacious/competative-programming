#include<iostream>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        string s;
        cin>>s;
        bool flag = true;
        if(s.length() == 1){
            cout<<"NO"<<endl;
            continue;
        }
        for(int i=1; i<s.length(); i++){
            if(s[i-1] != s[i]){
                flag = false; ///
                
                break;
            }
        }
        if(flag == false){
            cout<<"YES"<<endl;
            cout<<s[s.length()-1];
            for(int i=0; i<s.length()-1; i++){
                cout<<s[i];
            }
            cout<<endl;
        } 
        else cout<<"NO"<<endl;
    }
}