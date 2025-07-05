int MOD = 1e9 + 7;

class Solution {
public:
    int countNumbers(string l, string r, int b) {
        int left = stoi(l);
        int right = stoi(r);
        // vector<int> v; // numbers with base b]

        int cnt = 0;
        for(int i = left; i <= right; i++) {
            int num = i;
            string s = "";
            while(num > 0) {
                s += to_string(num % b);
                num /= b;
            }
            reverse(s.begin(), s.end());

            if(is_sorted(s.begin(), s.end())) {
                cnt += 1;
                cnt %= MOD;
            }
            // v.push_back(stoi(s));
        }

        return cnt;
    }
};