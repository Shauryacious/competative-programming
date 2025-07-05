// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<map>
#include<set>
#include<unordered_set>
#include<algorithm>
#include<cmath>
#include<climits>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
using namespace std;

//Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);

//Macros
#define rep(i,j) for(int i=0;i<j;i++)
#define rrep(i,j) for(int i=j-1;i>=0;i--)
#define all(x) x.begin(), x.end()
#define invec(v, n) for(int i=0; i<n; i++) cin>>v[i];

//Typedef
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef map<int,int> mii;

void solve(){
    int n, m; cin>>n>>m;
    string x, s; cin>>x>>s;

    int count = 0;
    int i = 5;
    while(i--){
        if(x.find(s) != string::npos){ // if s is a substring of x
            break;
        }
        else{
            count++;
            x += x;
        }
    }
    if(x.find(s) != string::npos){
        cout<<count<<endl;
    }
    else{
        cout<<-1<<endl;
    }
          
}


int32_t main(){
    fastio()
    int t;
    cin>>t;
    while(t--){
    solve();
    }
    return 0;
}