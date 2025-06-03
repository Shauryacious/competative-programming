#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define pb push_back



class Solution {
  public:
    int countPairs(vector<vector<int>> &m1, vector<vector<int>> &m2, int x) {
        ii n = m2.size(), m = m2[0].size();
        ii count = 0;
        vii v;
        for (ii i = 0; i < n; i++) {
            for (ii j = 0; j < m; j++) {
                v.pb(m2[i][j]);
            }
        }

        for(ii i = 0; i < n; i++) {
            for (ii j = 0; j < m; j++) {
                ii t = x - m1[i][j];
                if(t < 0) continue;
                bool found = binary_search(v.begin(), v.end(), t);
                if(found) {
                    count++;
                }
            }
        }

        return count;
    }
};