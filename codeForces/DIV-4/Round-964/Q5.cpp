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

vector<ll> powersOf3;
vector<ll> prefix;   

// Function to populate powers of 3 less than or equal to 2 * 10^5
vector<ll> populatePowersOf3() {
    vector<ll> powersOf3;
    ll power = 1;
    while (power <= 6 * 1e5) {
        powersOf3.push_back(power);
        power *= 3;
    }
    return powersOf3;
}


// Function to find the next power of 3 greater than or equal to a given number
ll nextPowerOf3(const vector<ll>& powersOf3, ll number) {
    if(number == 1) return 1;

    auto it = lower_bound(powersOf3.begin(), powersOf3.end(), number);
    ll ans =0;
    if (it != powersOf3.end()) {
        ans = distance(powersOf3.begin(), it);
    }
    if(number%3==0){
        return ans+1;
    }

    return ans;
}


void precompute() {
    prefix.push_back(0);
    for(ll i=0;i<=1e5;i++){
        auto num = lower_bound(powersOf3.begin(), powersOf3.end(), i);
        prefix.push_back(prefix.back() + distance(powersOf3.begin(), num));
    }
}


void solve() {
    ll l, r; cin >> l >> r;
    ll ans = 0;
    ans += 2*nextPowerOf3(powersOf3, l);
    ans += prefix[r] - prefix[l];

    cout << ans << endl;
}

int32_t main() {
    fastio();
    powersOf3 = populatePowersOf3();
    // for(auto x: powersOf3){
    //     cout << x << " ";
    // }
    // cout << endl;
    precompute();
    
    // for(int i=0; i<=10; i++){
    //     cout << i << " ";
    // }
    // cout << endl;

    // for(int i=0; i<=10; i++){
    //     cout << prefix[i] << " ";
    // }
    ll t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}