// Author : Shaurya Agrawal
// Linkedin: https://www.linkedin.com/in/shauryacious/
// Codeforces: https://codeforces.com/profile/Shauryacious
// Love you mumma <3

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<random>
#include<string>
#include<functional>
#include<iomanip>
#include<limits>
#include<array>
#include<utility>

using namespace std;


#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define vpii vector<pii>
#define pb push_back
#define MOD 1000000007
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define all(x) (x).begin(), (x).end()

class Solution {
  public:
    int smallestDivisor(vector<int>& a, int k) {
        ll n = a.size();
        ll l = 1, r = 1e6, ans = 1;

        auto f = [&](ll x) -> bool {
            ll sum = 0;
            for (ll i = 0; i < n; i++) {
                sum += (a[i] + x - 1) / x; 
            }

            return sum <= k;
        };

        while (l <= r) {
            ll mid = l + (r - l) / 2;
            if(f(mid)){
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
