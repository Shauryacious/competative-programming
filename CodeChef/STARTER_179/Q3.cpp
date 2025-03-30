#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <chrono>
#include <random>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <queue>
#include <stack>
#include <bitset>
#include <numeric>

using namespace std;

#define ll long long
#define vll vector<ll>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

ll N = 2e6 + 10;  
ll M = 1e9 + 7;
vll fact(N+1);
vll ifact(N+1);

ll mod_mul(ll a, ll b, ll M){
    a = a % M;
    b = b % M;
    return (((a * b) % M) + M) % M;
}

ll expo(ll a, ll n, ll M){
    ll ans = 1;
    while(n > 0){
        if((n & 1) == 1){  // i.e., Last bit is set
            ans = mod_mul(ans, a, M);
        }
        a = mod_mul(a, a, M);
        n >>= 1;
    }
    return ans;
}

void precompute(){
    fact[0] = 1;
    for(int i=1; i<=N; i++){
        fact[i] = mod_mul(i, fact[i-1], M);
    }

    ifact[N] = expo(fact[N], M-2, M);  // Modular inverse of fact[N-1] -> fermat's little theorem 
    for(int i=N-1; i>=0; i--){
        ifact[i] = mod_mul(i+1, ifact[i+1], M);
    }
}

ll nCr(ll n, ll r, ll M){
    if(r > n) return 0;
    ll ans = 1;
    ans = mod_mul(ans, fact[n], M);
    ans = mod_mul(ans, ifact[r], M);
    ans = mod_mul(ans, ifact[n-r], M);
    return ans;
}

void solve(){
    ll n;
    cin >> n;
    vll a(n);
    for (ll i = 0; i < n; i++){
        cin >> a[i];
    }
    
    ll i = 0, j = 0;
    ll ans = 0;
    // st1 will store the elements of the current window
    multiset<ll> st1;
    // st2 is used for the new window when a duplicate is found
    multiset<ll> st2;
    
    while(i < n){
        // Expand the current window if a[j] is not a duplicate in st1
        if(j < n && st1.find(a[j]) == st1.end()){
            st1.insert(a[j]);
            j++;
        }
        // When a duplicate is found in the current window:
        else if(j < n){

            // Save current window length
            ll len1 = st1.size();
            // Use a new pointer k (starting at j-1) and new set st2
            ll k = j-1;
            st2.insert(a[j]);  // start st2 with the duplicate element
            while(k < n){
                // When a duplicate is found in st2 (note: we already added a[j] so we skip comparing at k==j)
                if(st2.find(a[k]) != st2.end() && k != j){
                    
                    ll len2 = st2.size();
                    ll t = len1 + len2 - 1; // total length of the combined window (adjusted by -1)
                    ans += (t * (t - 1)) / 2; // contribution (nC2)
                    // Now make the new window our current window
                    st1 = st2;
                    st2.clear();
                    // Update pointers: i becomes the start of the old window, and j jumps to k
                    i = j;
                    j = k;
                    break;
                }
                else{
                    st2.insert(a[k]);
                    k++;
                }
            }
            // In case we reach the end without encountering a duplicate in st2,
            // we finalize the answer with the remaining window.
            if(k == n){
                ll len2 = st2.size();
                ll t = len1 + len2 - 1;
                ans += (t * (t - 1)) / 2;
                break;
            }
        }
    }
    
    cout << ans << "\n";
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif
    fastio();
    // precompute();
    ll t = 1; 
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}