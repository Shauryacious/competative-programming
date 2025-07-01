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
    int countSubstrings(string s) {
        int n = s.size();

        int dp[1001][1001]; // dp[i][j] = 1 if s[i..j] is a palindrome, else 0
        memset(dp, 0, sizeof(dp));

        for(int l = 1; l <= n; l++){
            for(int i = 0; i+l-1 < n; i++){
                int j = i + l - 1;
                if(l == 1) {
                    dp[i][j] = 1; // single character is a palindrome
                } else if(l == 2) {
                    dp[i][j] = (s[i] == s[j]) ? 1 : 0; // two characters are a palindrome if they are equal
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]) ? 1 : 0; // check outer characters and inner substring
                }
            }
        }

        int count = 0;  
        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                count += dp[i][j]; // count all palindromic substrings
            }
        }

        return count;
    }
};