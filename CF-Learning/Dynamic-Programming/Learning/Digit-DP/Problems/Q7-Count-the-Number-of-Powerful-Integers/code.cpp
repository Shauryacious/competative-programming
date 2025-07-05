typedef long long ll;

class Solution {
    ll dp[16][2];

    ll f(ll idx, ll tight, string& s, string& suf, int& limit){
        if(idx == s.size()){
            return 1;
        }

        if(dp[idx][tight] != -1) return dp[idx][tight];

        int bound = tight ? s[idx] - '0' : 9;
        bound = min(bound, limit);

        int sufrange = s.size() - suf.size(); // assume s = "99999", and suf = "78" -> suffIdx starts from 3
                                              //             01234

        ll ans = 0;
        // TWO CASES:-
        // CASE 1: index in suffix range
        if(idx >= sufrange){
            if(tight == 0){ // We can fill the remaining positions with the suffix values
                return dp[idx][tight] = 1;
            }
            else{
                if(s[idx] < suf[idx - sufrange]){
                    return dp[idx][tight] = 0; //its tight, and we dont have the suffix digit to fill in the range (0 to bound)
                }
                else if(s[idx] == suf[idx - sufrange]){ // fill the suffix digit and check ahead
                    return dp[idx][tight] = f(idx+1, 1, s, suf, limit);
                }   
                else{ // s[idx] > suf[idx - sufrange]
                    return dp[idx][tight] = 1; // tho it was tight, but still since we can fill the remaining positions with the suffix values, return 1
                }
            }
        }
        // CASE 2: Not in the suffix range
        else{
            for(int i=0; i<=bound; i++){
                int newtight = tight && (i==(s[idx]-'0'));
                ans += f(idx+1, newtight, s, suf, limit);
            }
        }

        return dp[idx][tight] = ans;
    }
public:
    long long numberOfPowerfulInt(long long l, long long r, int limit, string suf) {
        memset(dp, -1, sizeof(dp));
        string R = to_string(r);
        ll ansR = f(0, 1, R, suf, limit);

        l--;
        string L = to_string(l);
        ll ansL = 0;
        if(L.size() >= suf.size()){
            memset(dp, -1, sizeof(dp));
            ansL = f(0, 1, L, suf, limit);
        }

        return ansR - ansL;
    }
};
