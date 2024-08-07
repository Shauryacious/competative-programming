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
    bool ans = false;
        
        ll n,s,m;
        cin>>n>>s>>m;
        
        ll end = 0;
        for(ll i = 0;i<n;i++)
        {
            ll l,r;
            cin>>l>>r;
            if(l-end>=s && end<=m)
            {
                ans = true;
            }
            end = r;
        }
        if(m-end>=s)
        {
            ans = true;
        }
        
        if(ans==true)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
}

int32_t main() {
    fastio();
    ll t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}