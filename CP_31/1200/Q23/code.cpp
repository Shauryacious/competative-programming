class Solution {
    int dp[10][2][2];
    int f(int idx, int tight, int isValidNum, string& s, unordered_set<int>& st){
        int n = s.size();
        if(idx == n){
            return 1;
        }

        if(dp[idx][tight][isValidNum] != -1) return dp[idx][tight];

        int bound = tight ? s[idx] - '0' : 9;

        int ans = 0;
        for(int i=0; i<=bound; i++){
            int newtight = tight && (i == bound);
            if(st.find(i) != st.end()){ // only proceed if i is in digit set
                if(isValidNum == 0){
                    if(i==0){
                        f(idx+1, newtight, 0, s, st);
                    }
                    else{
                        f(idx+1, newtight, 1, s, st);
                    }
                }
                else{
                    f(idx+1, newtight, 1, s, st);
                }
            }
        }

        return dp[idx][tight][isValidNum] = ans;
    }
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        unordered_set<int> st;
        for(auto s : digits){
            st.insert(stoi(s));
        }

        string str = to_string(n);
        memset(dp, -1, sizeof(dp));

        return f(0, 1, 0, str, st);
    }
};
