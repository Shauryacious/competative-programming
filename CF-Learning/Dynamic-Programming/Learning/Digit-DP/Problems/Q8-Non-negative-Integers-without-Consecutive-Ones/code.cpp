class Solution {
    int dp[33][2][2];

    int f(int idx, int tight, int prev, string& s){
        if(idx == s.size()){
            return 1;
        }

        if(dp[idx][tight][prev] != -1){
            return dp[idx][tight][prev];
        }


        int bound = tight ? s[idx] - '0' : 1;

        int ans = 0;
        for(int i = 0; i <= bound; i++){
            int newTight = tight && (i == bound);
            if(prev){
                if(i == 0){
                    ans += f(idx + 1, newTight, 0, s);
                }
            }
            else{
                ans +=
            }
        }
    }
public:
    int findIntegers(int n) {
        // Convert integer n to string of binary
        string b = "";
        while (n > 0) {
            b = to_string(n % 2) + b;
            n /= 2;
        }


    }
};