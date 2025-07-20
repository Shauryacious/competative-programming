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
#define vvpii vector<vpii>
#define pb push_back
#define MOD 1000000007
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvpll vector<vpll>
#define all(x) (x).begin(), (x).end()
#define INF 1e18
#define ff first
#define ss second



class Solution {
  public:
    int maxRectSum(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();

        auto kadane = [&](vii& a) -> int {
            int n = a.size();
            int mx = a[0], sm = a[0];
            for(int i = 1; i < n; i++){
                if(sm + a[i] >= a[i]){
                    sm += a[i];
                } else {
                    sm = a[i];
                }
                mx = max(mx, sm);
            }
            return mx;
        };

        int ans = -INF;
        // cs = column start 
        // ce = column end
        for(int cs = 0; cs < m; cs++){
            vii arr(n, 0);
            for(int ce = cs; ce < m; ce++){
                for(int i = 0; i < n; i++){
                    arr[i] += g[i][ce];
                }
                int currSum = kadane(arr);
                ans = max(ans, currSum);
            }
        }

        return ans;
    }
};
