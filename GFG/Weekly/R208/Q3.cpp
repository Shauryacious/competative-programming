#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& a, int k) {
        int n = a.size();
        if (n < 2) return 0;              // no even-length subsequence possible
        
        // dp[i][j] = length of the longest valid subsequence
        // ending at i, whose previous element was at j (j < i).
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // best[i] = the longest subsequence length ending exactly at i
        // (regardless of what j it came from), or 0 if none.
        vector<int> best(n, 0);
        
        auto ok = [&](int x, int y){
            return abs(x - y) <= k;
        };
        
        int answer = 0;
        
        // 1) Initialize all length-2 subsequences (pairs j→i)
        for (int j = 0; j < n; j++) {
            for (int i = j + 1; i < n; i++) {
                if (ok(a[j], a[i])) {
                    dp[i][j] = 2;
                    best[i] = max(best[i], 2);
                    answer = max(answer, 2);
                }
            }
        }
        // 13 19 5 2 4 6 6 3 9
        // 7
        
        // 2) Build up longer subsequences in O(n^2) using the `best[]` array
        for (int i = 0; i < n; i++) {
            // extend any subsequence that ended at j < i
            if (best[i] > 0) {
                // (we already counted pairs in step 1)
            }
            for (int j = 0; j < i; j++) {
                if (!ok(a[j], a[i])) continue;
                if (best[j] > 0) {
                    // Append a[i] onto the best subsequence ending at j
                    int len = best[j] + 1;
                    dp[i][j] = max(dp[i][j], len);
                    // Only even-length subsequences count toward the result
                    if ((dp[i][j] & 1) == 0) {
                        answer = max(answer, dp[i][j]);
                    }
                }
            }
            // 3) Update best[i] to include all dp[i][*]
            for (int j = 0; j < i; j++) {
                best[i] = max(best[i], dp[i][j]);
            }
        }
        
        return answer;
    }
};

// Example usage and basic tests
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution sol;
    vector<int> arr1 = {1, 2, 3};
    cout << sol.longestSubsequence(arr1, 1) << "\n";    // expected 2

    vector<int> arr2 = {25, 5, 25, 5};
    cout << sol.longestSubsequence(arr2, 20) << "\n";   // expected 4

    // edge cases
    vector<int> arr3 = {7};
    cout << sol.longestSubsequence(arr3, 5) << "\n";    // expected 0

    vector<int> arr4 = {};
    cout << sol.longestSubsequence(arr4, 10) << "\n";   // expected 0

    return 0;
}
