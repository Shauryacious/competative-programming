class Solution {
    int dp[10][2][10];
    int f(int idx, int tight, string& s, int cnt1){
        if(idx == s.size()){
            return cnt1;
        }

        if(dp[idx][tight][cnt1] != -1) return dp[idx][tight][cnt1];

        int bound = tight ? s[idx] - '0' : 9;

        int ans = 0;
        for(int i=0; i<=bound; i++){
            int newtight = tight && (i==bound);
            if(i==1){
                ans += f(idx+1, newtight, s, cnt1+1);
            }
            else{
                ans += f(idx+1, newtight, s, cnt1);
            }
        }

        return dp[idx][tight][cnt1] = ans;
    }
public:
    int countDigitOne(int n) {
        string s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return f(0, 1, s, 0);
    }
};