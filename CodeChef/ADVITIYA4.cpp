#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
  int t; cin>>t;
  while(t--){
      int n, q;
      cin>>n>>q;

      string s; 
      cin>>s;
        int streak = 1;
        int max_streak = 1;
        for(int i=1; i<n; i++){
          if(s[i-1] == s[i]) streak++;
          else{
            streak = 1;
          }
          if(streak > max_streak) max_streak = streak;
        }
        cout<<max_streak<<" ";

          for(int i=n; i<(n+q); i++){
            char x;
            cin>>x;
            s+=x;


              if(s[i-1] == s[i]) streak++;
              else{
                streak = 1;
              }
              max_streak = max(streak, max_streak);


        cout<<max_streak<<" ";
          }
        cout<<endl;
  }
}
