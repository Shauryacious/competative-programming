class Solution {
    vector<long long> fact = {
    1,        // 0!
    1,        // 1!
    2,        // 2!
    6,        // 3!
    24,       // 4!
    120,      // 5!
    720,      // 6!
    5040,     // 7!
    40320,    // 8!
    362880,   // 9!
    3628800   // 10!
};

    int INF = 1e9;
public:
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        vector<int> f(26, 0);
        for(char c : s) {
            f[c - 'a']++;
        }

        char ch = 'a';
        bool odd = false;
        for(int i = 0; i < 26; i++) {
            if(f[i] % 2 == 1) {
                odd = true;
                ch = 'a' + i;
                break;
            }
        }

        string ans = "";

        for(int i = 0; i < 26; i++) {
            ans += string(f[i] / 2, 'a' + i);
        }

        // cout<<ans<<endl;

        int len = ans.size();
        int possibilities = INF;
        if(len <= 10){
            possibilities = fact[len];
        }
        // cout<<possibilities<<endl;

        if(k > possibilities) {
            return "";
        }

        string curr = "";
        int cnt = 0;

        if(k == 1) {
            string rev = ans;
            reverse(rev.begin(), rev.end());

            if(odd) {
                ans += ch;
            }

            ans += rev;

            return ans;
        }

        do{
            cnt++;
            if(cnt >= k) {
                curr = ans;
                break;
            }
        }while(next_permutation(ans.begin(), ans.end()));

        if(curr == "") {
            return "";
        }

        string rev = curr;
        // cout<<"REV: "<<rev<<endl;
        reverse(rev.begin(), rev.end());

        if(odd) {
            ans += ch;
        }

        ans += rev;

        return ans;
    }
};