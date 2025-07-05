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

// a = [2, 1, 3, 4]
//         A  B  C
// A = 2x1, B = 1x3, C = 3x4


class Solution {
  public:
    int matrixMultiplication(vector<int> &a) {
        int n = a.size();    

        int dp[101][101]; 
        memset(dp, -1, sizeof(dp)); 
        
        auto f = [&](int i, int j, auto && f) -> int {
            if(i == j) return 0; // No multiplication needed for single matrix

            if(dp[i][j] != -1) return dp[i][j]; 

            int ans = INF;

            for(int k = i; k <= j-1; k++) {
                int left = f(i, k, f); 
                int right = f(k+1, j, f);
                int cost = a[i-1] * a[k] * a[j]; 
                ans = min(ans, left + right + cost);
            }

            return dp[i][j] = ans; 
        };

        return f(1, n-1, f); // Start from the first matrix to the last
    }
};