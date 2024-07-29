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
    int n; cin>>n;
    vi a(n);
    invec(a, n);
            unordered_map<int, int> freq;
            int p = a[0];
            int q;
            for(int i=0; i<n; i++){
                freq[a[i]]++;
                if(a[i] != p){
                    q = a[i];
                }
            }
            if(freq.size() == 1){
                cout<<"YES"<<endl;
                return;
            }
            else if(freq.size() == 2){
                if(abs(freq[p] - freq[q]) <= 1){
                    cout<<"YES"<<endl;
                    return;
                }
                else{
                    cout<<"NO"<<endl;
                    return;
                }
            }
            else{
                cout<<"NO"<<endl;
                return;
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