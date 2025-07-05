#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
  string s; cin>>s;
  int count=0;
  for(int i=0; i<s.length()-1; i++){
    if(s[i] == s[i+1]) count++;

    if(count>=6) {
      cout<<"YES"<<endl;
      return 0;
    }
    else if (s[i] != s[i+1]) count = 0;
  }
  cout<<"NO";
}
