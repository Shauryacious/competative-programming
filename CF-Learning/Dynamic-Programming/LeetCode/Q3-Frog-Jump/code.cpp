#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define pb push_back

class Solution {
    int dp[2001][2001]; // dp[stone_index][previous_jump_length]
public:
    bool canCross(vii& stones) {
        int n = stones.size();

        map<ii, ii> mp; // {stone_no, stone_idx}
        for (int i = 0; i < n; i++) {
            mp[stones[i]] = i;
        }
        //csi = current stone index
        //csn = current stone number
        //pj = previous jump length
        //cj = current jump length
        //nsn = next stone number = csn + cj
        // nsi = next stone index = mp[nsn]
        memset(dp, -1, sizeof(dp));
        auto f = [&](int csi, int pj, auto && f) -> bool {
            if(csi == n - 1) return true; // Reached the last stone

            if(dp[csi][pj] != -1) return dp[csi][pj]; // Already computed

            int csn = stones[csi];

            bool ans = false;
            for(int cj = pj-1; cj <= pj+1; cj++){
                if(cj <= 0) continue; // jump length must be positive
                int nsn = csn + cj; // next stone number
                if(mp.find(nsn) == mp.end()) continue; // next stone doesn't exist
                int nsi = mp[nsn]; // get the index of the next stone

                ans |= f(nsi, cj, f); 
            }

            return dp[csi][pj] = ans; // Store the result in dp array
        };

        return f(0, 0, f); 
    }
};