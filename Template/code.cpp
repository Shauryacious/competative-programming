class Solution {
  public:
    bool sameFreq(string& s) {
        int freq[26];
        memset(freq, 0, sizeof(freq));

        for (char c : s) {
            freq[c - 'a']++;
        }

        set<int> st(freq, freq + 26);
        if(st.size() <= 1) return true;
        if(st.size() > 2) return false;

        int f1 = *st.begin();
        st.erase(st.begin());

        int f2 = *st.begin();
        st.erase(st.begin());

        return abs(f1 - f2) <= 1;
    }
};