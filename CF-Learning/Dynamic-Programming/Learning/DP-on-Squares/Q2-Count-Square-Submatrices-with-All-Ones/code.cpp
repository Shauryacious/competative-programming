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
    int countSquares(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vvii dp(n+1, vii(m+1, 0));

        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                if(i==n-1 && j==m-1){
                    dp[i][j] = g[i][j];
                }
                else if(i == n-1){
                    dp[i][j] = g[i][j];
                }
                else if(j == m-1){
                    dp[i][j] = g[i][j];
                }
                else{
                    if(g[i][j] == 0){
                        dp[i][j] = 0;
                    }
                    else{
                        int right = dp[i][j+1];
                        int down = dp[i+1][j];
                        int diagonal = dp[i+1][j+1];

                        dp[i][j] = 1 + min({right, down, diagonal});
                    }
                }
            }
        }

        int ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans += dp[i][j];
            }
        }

        return ans;
    }
};