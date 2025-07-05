#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
  int t; cin>>t;
  while(t--){
    string str;
    cin>>str;
    int n = str.length(); 
    if(n > 10){
      cout<<str[0]<<n-2<<str[n-1]<<endl;
    }
    else cout<<str<<endl;
  }
  
}