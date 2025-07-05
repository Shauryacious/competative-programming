#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
// #include <bits/stdc++.h>

using namespace std;

// Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

// Macros
#define rep(i, j) for (int i = 0; i < j; i++)
#define invec(v, n) for (int i = 0; i < n; i++) cin >> v[i]

// Typedef
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;




void solve() {
int a1,a2,b1,b2;
        cin>>a1>>a2>>b1>>b2;
        
        int ans = 0;
        
        if(a1>b1 && a2>b2)
        {
            ans += 2;
        }
        else if(a1>=b1 && a2>b2)
        {
            ans += 2;
        }
        else if(a1>b1 && a2>=b2)
        {
           ans += 2;
        }
        
        
        if(a1>b2 && a2>b1)
        {
            ans += 2;
        }
        else if(a1>=b2 && a2>b1)
        {
           ans += 2;
        }
        else if(a1>b2 && a2>=b1)
        {
            ans += 2;
        }
        
        
        
        
        cout<<ans<<endl;
}

int32_t main() {
    fastio();
    ll t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
