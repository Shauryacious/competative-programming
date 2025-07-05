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

// Will give MLE due to large recursion depth and string concatenation
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        vector<map<string, int>> dp(n + 1);

        auto isPalindrome = [&](string& s) -> bool {
            int l = 0, r = s.size() - 1;
            while (l < r) {
                if (s[l] != s[r]) return false;
                l++;
                r--;
            }
            return true;
        };

        auto f = [&](int i, string curr, auto && f) -> int {
            if(i == n){
                return isPalindrome(curr) ? curr.size() : 0;
            }
            if (dp[i].count(curr)) return dp[i][curr];

            int ans = 0;

            // Include the current character
            ans = max(ans, f(i + 1, curr + s[i], f));

            // Exclude the current character
            ans = max(ans, f(i + 1, curr, f));

            return dp[i][curr] = ans;
        };

        return f(0, "", f);
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        // dp[i][j] = length of longest palindromic subsequence in s[i..j]
        int dp[1001][1001]; 
        memset(dp, 1, sizeof(dp));

        for(int l = 1; l <= n; l++){
            for(int i = 0; i+l-1 < n; i++){
                int j = i + l - 1;
                if(l == 1) {
                    dp[i][j] = 1;
                }
                else if(l == 2) {
                    // two characters are a palindrome if they are equal
                    // if not then length is 1
                    dp[i][j] = (s[i] == s[j]) ? 2 : 1;
                }
                else{
                    if(s[i] == s[j]) {
                        // if outer characters are equal, add 2 to the length of inner substring
                        dp[i][j] = 2 + dp[i + 1][j - 1];
                    } else {
                        // if not equal, take the maximum of excluding either character
                        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                    }
                }
            }
        }

        // The answer is the length of the longest palindromic subsequence in the whole string
        return dp[0][n - 1];
    }
};