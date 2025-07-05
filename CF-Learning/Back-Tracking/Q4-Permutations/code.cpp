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
#include<functional>
#include<iterator>
#include<cstring>

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
#define INF 1e9

class Solution {
public:
    vvii permute(vii& a) {
        int n = a.size();
        vvii ans;

        auto f = [&](vii& curr, int mask, auto &&f) -> void {
            if(curr.size() == n){
                ans.pb(curr);
                return;
            }

            for(int i = 0; i < n; i++){
                if((mask & (1 << i)) == 0){ // if i-th bit is not set yet
                    curr.pb(a[i]);
                    f(curr, mask | (1 << i), f);
                    curr.pop_back();
                }
            }
        };

        vii curr;
        f(curr, 0, f);
        return ans;
    }
};
