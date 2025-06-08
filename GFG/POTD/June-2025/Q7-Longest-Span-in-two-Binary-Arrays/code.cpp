#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define pb push_back
#define MOD 1000000007

class Solution {
  public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2) {
        int n = a1.size();
        vii pre1(n, 0), pre2(n, 0);
        pre1[0] = a1[0];
        pre2[0] = a2[0];
        for (int i = 1; i < n; i++) {
            pre1[i] = pre1[i - 1] + a1[i];
            pre2[i] = pre2[i - 1] + a2[i];
        }

        vii diff(n, 0);
        for (int i = 0; i < n; i++) {
            diff[i] = pre2[i] - pre1[i];
        }

        map<int, int> mp;
        mp[0] = -1; 
        int mxlen = 0;
        for(int i = 0; i < n; i++){
            int curr = diff[i];
            if(mp.find(curr) != mp.end()) {
                int currlen = i - mp[curr];
                mxlen = max(mxlen, currlen);
            }
            else {
                mp[curr] = i;
            }
        }

        return mxlen;
    }
};