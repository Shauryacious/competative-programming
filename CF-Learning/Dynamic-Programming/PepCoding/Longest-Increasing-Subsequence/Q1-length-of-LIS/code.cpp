#include <vector>
#include <algorithm>
using namespace std;


// T.C. = O(n^2) using DP
// S.C. = O(n)
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

// T.C. = O(nlogn) using Binary Search -> Patience Sorting
// S.C. = O(n)
class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n = a.size();
        vector<int> lis;
        lis.push_back(a[0]);
        
        for (int i = 1; i < n; i++) {
            int idx = lower_bound(lis.begin(), lis.end(), a[i]) - lis.begin();
            
            if (idx == lis.size()) {
                // If a[i] is greater than all elements, append it
                lis.push_back(a[i]);
            } else {
                lis[idx] = a[i];
            }
        }
        
        return lis.size();
    }
};
