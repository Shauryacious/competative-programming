#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define vpii vector<pii>
#define pb push_back
#define MOD 1000000007

class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        int n = x.size();
        vpii v(n);
        for(int i = 0; i < n; i++) {
            v[i] = {y[i], x[i]};
        }

        sort(v.rbegin(), v.rend());

        map<int, int> mp;
        for(auto [y, x] : v) {
            if(mp.count(x)) continue;
            mp[x] = y;
            if(mp.size() == 3) {
                int sum = 0;
                for(auto [_, val] : mp) {
                    sum += val;
                }
                return sum;
            }
        }

        return -1; // If less than 3 distinct x values are found
    }
};