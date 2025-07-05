#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int options(int sx, int sy, int mx, int my, int l){
  if(sx - l < 0) return 1;
  else if(sx + l > mx) return 1;
  else if(sy - l < 0) return 1;
  else if(sy + l > my) return 1;

  options(sx - l, sy, mx, my, l);
  options(sx + l, sy, mx, my, l);
  options(sx, sy - l, mx, my, l);
  options(sx, sy + l, mx, my, l);
}

int main() {
	// your code goes here
  int t; cin>>t;
  while(t--){
    int n, m, x, y, l;
    cin>>n>>m>>x>>y>>l;
    
    // vector<vector<int>> v(n, vector<int> (m, -1));
    // n = n-1;
    // m = m-1;
    // x = x-1;
    // y= y-1;
    // v[x][y] = 0;
    cout<<options(x, y, n, m, l)<<endl;
  }
}