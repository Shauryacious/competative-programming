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
    bool isInterleave(string& s1, string& s2, string& s3) {

        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();

        if (n1 + n2 != n3){
            return false;
        }

        int dp[305][305];
        memset(dp, -1, sizeof(dp));

        // Since k = i + j;
        // hence it is a dependency of i and j.
        // so we will not require it in dp

        auto f = [&](int i, int j , int k, auto && f) -> bool {
            if(i > n1 || j > n2 || k > n3) {
                return false;
            }
            if(i == n1 && j == n2 && k == n3) {
                return true;
            }
            if(i < n1 && j < n2 && k < n3 && s1[i] != s3[k] && s2[j] != s3[k]) {
                return false;
            }

            if(dp[i][j] != -1) {
                return dp[i][j];
            }

            bool ans = false;

            if(i < n1 && j < n2 && k < n3 && s1[i] == s3[k] && s2[j] == s3[k]){
                ans |= f(i+1, j, k+1, f);
                ans |= f(i, j+1, k+1, f);
            }
            else if(i < n1 && k < n3 && s1[i] == s3[k]) {
                ans |= f(i+1, j, k+1, f);
            }
            else if(j < n2 && k < n3 && s2[j] == s3[k]) {
                ans |= f(i, j+1, k+1, f);
            }

            return dp[i][j] = ans;
        };

        return f(0, 0, 0, f);
    }
};