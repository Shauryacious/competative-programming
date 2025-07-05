// Author : Shaurya Agrawal
// Linkedin: https://www.linkedin.com/in/shauryacious/
// Codeforces: https://codeforces.com/profile/Shauryacious
// Codechef: https://www.codechef.com/users/shauryacious27

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

typedef long long ll;
typedef vector<ll> vll;

// We want all the number of the type : x^2 + y^4 = n
// also the number n should be a Prime

// 1. Declare N before using it
ll N = 1e7 + 1;

// 2. Initialize isPrime after declaring N
vll isPrime_global(N, 1); 

// Function to construct Sieve of Eratosthenes
vll construct_seive(){
    // 3. Corrected for loop syntax: use semicolons instead of commas
    for(ll i = 2; i * i <= N; i++){ 
        if(isPrime_global[i] == 1){
            for(ll j = i * i; j <= N; j += i){
                isPrime_global[j] = 0;
            }
        }
    }
    return isPrime_global;
}

vll isType(N, 0); // Type[i] = 1 if i = x^2 + y^4

vll prefix_arr(N, 0); // prefix[i] = number of valid numbers <= i

// Function to precompute the necessary data
void preCompute(){
    // 4. Use the corrected sieve
    vll isPrime = construct_seive();

    // 5. Populate isType without shadowing and ensure no out-of-bounds
    for(ll i = 1; i * i <= N; i++){ // x^2
        for(ll j = 1; j * j * j * j <= N; j++){ // y^4
            ll sum = i * i + j * j * j * j;
            if(sum <= N){
                isType[sum] = 1;
            }
        }
    }

    // 6. Mark valid prime numbers that satisfy the condition
    vll a(N, 0); 
    for(ll i = 1; i <= N; i++){
        if(isPrime[i] == 1 && isType[i] == 1){
            a[i] = 1;
        }
    }

    // 7. Build the prefix sum array
    for(ll i = 1; i <= N; i++){
        prefix_arr[i] = prefix_arr[i-1] + a[i];
    }
}

void solve(){
    ll n; 
    cin >> n;
    cout << prefix_arr[n] << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    #ifndef ONLINE_JUDGE
        freopen("Error.txt", "w", stderr);
    #endif

    preCompute();
    ll t; 
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
