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
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();

        int dp[2501][2505];
        memset(dp, -1, sizeof(dp));

        auto f = [&](int i, int previdx, auto&& f) -> int {
            //Base Case: 
            if(i == n) return 0; 

            if(dp[i][previdx + 1] != -1) {
                return dp[i][previdx + 1];
            }


            int ans = 0;

            // If the current element is greater than the previous one
            if(previdx == -1 || a[i] > a[previdx]) {
                // Include the current element in the subsequence
                ans = 1 + f(i + 1, i, f);
            }

            // Exclude the current element from the subsequence
            ans = max(ans, f(i + 1, previdx, f));

            return dp[i][previdx + 1] = ans;
        };

        int ans = f(0, -1, f);

        return ans;
    }
};



class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();

        // State:
        // dp[i] = Longest Increasing Subsequence 
        // s.t. the Subsequence ends at a[i] 
        // & it is also increasing in nature
        vector<int> dp(n, 0);

        // Base Case:
        // dp[0] = 1;

        for(int i=0; i<n; i++){
            int maxx = 0;

            for(int j=0; j<i; j++){
                if(a[j] < a[i]){ // the prev element is less then the curr one
                    if(dp[j] > maxx){
                        maxx = dp[j];
                    }
                }
            }

            dp[i] = maxx+1;
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};