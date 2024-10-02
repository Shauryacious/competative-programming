// Author : Shaurya Agrawal
// Linkedin: https://www.linkedin.com/in/shauryacious/
// Codeforces: https://codeforces.com/profile/Shauryacious
// Codechef: https://www.codechef.com/users/shauryacious27

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
typedef long long ll;

// Function to compute floor(sqrt(n)) accurately using binary search
ll integer_sqrt(ll n){
    if(n == 0 || n == 1){
        return n;
    }
    ll start = 1, end = 1e9 + 1, ans = 0;
    while(start <= end){
        ll mid = start + (end - start) / 2;
        if(mid <= n / mid){
            ans = mid;
            start = mid + 1;
        }
        else{
            end = mid -1;
        }
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        ll k;
        cin >> k;
        
        // Define search bounds
        ll low = 1;
        // Upper bound set to k + 2e9 to account for floor(sqrt(n)) <=1e9
        ll high = k + 2e9;
        ll ans = -1;
        
        while(low <= high){
            ll mid = low + (high - low) / 2;
            ll s = integer_sqrt(mid);
            ll f = mid - s;
            
            if(f == k){
                ans = mid;
                // Continue searching to the left for the smallest n
                high = mid - 1;
            }
            else if(f < k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        
        cout << ans << "\n";
    }
}
