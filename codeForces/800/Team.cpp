#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
  int t, question_count=0; cin>>t;
  while(t--){
    vector<int> v(3);
    int count=0;
    for(int i=0; i<3; i++){
      cin>>v[i];
      if(v[i] == 1) count++;
    }
    if(count >= 2) question_count++;
  }
  cout<<question_count<<endl;
}