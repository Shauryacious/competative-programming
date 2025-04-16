class Solution {
    int dp[10][2][2][1024];
    int f(int idx, int tight, int isValid, int mask, string& s) {
        if (idx == s.size()) {
            return isValid;
        }
        if (dp[idx][tight][isValid][mask] != -1) {
            return dp[idx][tight][isValid][mask];
        }
        int bound = (tight) ? s[idx] - '0' : 9;
        int ans = 0;
        for (int i = 0; i <= bound; i++) {
            int newTight = (tight && (i == bound));

        }
        return dp[idx][tight][isValid][mask] = ans;
    }
public:
    int numDupDigitsAtMostN(int n) {
        string R = to_string(n);
    }
};