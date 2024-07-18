#include<iostream>
#include<string>
using namespace std;

std::string convertToLowerCase(const std::string& input) {
    std::string result = input;

    for (char& c : result) {
      if(c == ' ') continue;
        c = std::tolower(c);
    }

    return result;
}

bool checkPalindrome(string s)
{
    // Write your code here.
    string r = convertToLowerCase(s);
    cout<<r<<endl;
    string q = s;
    reverse(s.begin(), s.end());
    if(q == s) return true;
    return false;
}
int main(){
  int t; cin>>t;
  while(t--){
    string s;
    cin>>s;
    cout<<checkPalindrome(s)<<endl;
  }
}
