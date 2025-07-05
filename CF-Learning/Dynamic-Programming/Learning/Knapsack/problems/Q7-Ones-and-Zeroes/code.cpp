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
    int findMaxForm(vector<string>& v, int m, int n) {
        int N = v.size();
        vpii a(N);
        for(int i = 0; i < N; i++) {
            int cnt0 = count(v[i].begin(), v[i].end(), '0');
            int cnt1 = v[i].size() - cnt0;
            a[i] = {cnt0, cnt1};
        }

        int dp[605][105][105];

        auto f = [&](int i, int cm, int cn, auto && f) -> int {
            if(cm > m || cn > n) {
                return -INF; 
            }
            if(i == N){
                if(cm <= m && cn <= n) {
                    return 0;
                }
                else{
                    return -INF;
                }
            }

            if(dp[i][cm][cn] != -1) {
                return dp[i][cm][cn];
            }

            auto [cnt0, cnt1] = a[i];

            // Take
            int take = 1 + f(i +1, cm + cnt0, cn + cnt1, f);

            //skip
            int skip = f(i + 1, cm, cn, f);

            return dp[i][cm][cn] = max(take, skip);
        };


        memset(dp, -1, sizeof(dp));
        int ans = f(0, 0, 0, f);


        return ans < 0 ? 0 : ans;
    }
};