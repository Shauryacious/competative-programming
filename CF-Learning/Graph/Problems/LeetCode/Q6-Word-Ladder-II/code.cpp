#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>

class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& words) {
        set<string> st(words.begin(), words.end());
        if(st.find(ew) == st.end()) return 0; // end word must be in dictionary

        ii d = 1;
        queue<string> q;
        q.push(bw);

        while(!q.empty()) {
            ii sz = q.size();
            while(sz--) {
                string s = q.front();
                q.pop();
                if(s == ew) {
                    return d;
                }
                ii n = s.size();

                for(ii i = 0; i < n; i++) {
                    for(char c = 'a'; c <= 'z'; c++) {
                        string t = s;
                        t[i] = c;
                        if(st.find(t) != st.end()) {
                            q.push(t);
                            st.erase(t);
                        }
                    }
                }
            }
            d++;
        }
        return 0;
    }
};
