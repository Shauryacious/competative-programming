#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define pb push_back
#define MOD 1000000007

class Solution {
public:
    string clearStars(string s) {
        map<int, vii> mp;
        int n = s.size();
        vii a(n, 1);
        for(int i=0; i<n; i++){
            char ch = s[i];
            int x = ch - 'a';
            if(ch == '*'){
                auto [ele : v] = *mp.begin();
                int idx = v.back(); 
                v.pop_back();
                if(v.empty()) {
                    mp.erase(ele);
                }
                a[idx] = 0; // Mark the index as cleared
                a[i] = 0; // Mark the current index as cleared
            } else {
                mp[x].pb(i);
            }
        }

        string ans = "";
        for(int i=0; i<n; i++){
            if(a[i] == 1) {
                ans += s[i];
            }
        }

        return ans;
    }
};