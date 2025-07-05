#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
  string str;
  cin>>str;
  int n = str.length();

  for(int i=0; i<n; i++){
    if(str[i] == 'H' || str[i] == 'Q' || str[i] == '9'){
      cout<<"YES";
      return 0;
    }
  }
  cout<<"NO";
}