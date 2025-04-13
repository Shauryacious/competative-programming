class Solution {
public:
    string smallestPalindrome(string s) {
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
        string rev = ans;
        reverse(rev.begin(), rev.end());

        if(odd) {
            ans += ch;
        }

        ans += rev;


        // cout<<ch<<endl;
        return ans;
    }
};