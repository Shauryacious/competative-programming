typedef long long ll;

ll mod_add(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    return (a + b) % m;
}

ll mod_sub(ll a, ll b, ll m) {
    a = a % m;
    b = b % m;
    return ((a - b + m) % m);
}

class Solution {
public:
    int MOD = 1e9 + 7;
    int dp[23][2][401];

    int f(int idx, int tight, int curr, string& s, int& mns, int& mxs){
        int n = s.length();
        if(idx == n){
            return (mns <= curr && curr <= mxs) ? 1 : 0;
        }

        if(dp[idx][tight][curr] != -1) return dp[idx][tight][curr];

        int bound = tight ? s[idx] - '0' : 9;
        int ans = 0;

        for(int i=0; i<=bound; i++){
            int newt = tight && (i == bound);
            ans = mod_add(ans, f(idx+1, newt, curr+i, s, mns, mxs), MOD);
        }

        return dp[idx][tight][curr] = ans;
    }

    int check(string l, int& mns, int& mxs){
        int sum = 0;
        for(auto ch : l) sum += ch - '0';
        return (mns <= sum && sum <= mxs) ? 1 : 0;
    }

    int count(string l, string r, int mns, int mxs) {
        memset(dp, -1, sizeof(dp));
        int x = f(0, 1, 0, l, mns, mxs);
        memset(dp, -1, sizeof(dp));
        int y = f(0, 1, 0, r, mns, mxs);

        int ans = mod_sub(y, x, MOD);
        int correction = check(l, mns, mxs);
        return mod_add(ans, correction, MOD);
    }
};
