typedef long long ll;

#define ff first
#define ss second

class Hash {
    const ll M = 1e9 + 7;
    const ll B1 = 5689;
    const ll B2 = 1987;
    
    vector<pair<ll, ll>> hash;
    vector<pair<ll, ll>> Bpower;
    
public:
    Hash(string s) {
        int n = s.length();
        hash.assign(n+1, {0, 0});
        Bpower.assign(n+1, {1, 1});
        
        for (ll i = 1; i <= n; i++) {
            char ch = s[i-1];
            ll curr_val = ch - 'a' + 1;
            
            hash[i] = {
                (((hash[i-1].ff * B1) % M) + curr_val) % M,
                (((hash[i-1].ss * B2) % M) + curr_val) % M
            };
            
            Bpower[i] = {
                (Bpower[i-1].ff * B1) % M,
                (Bpower[i-1].ss * B2) % M
            };
        }
    }
    
    pair<ll, ll> get(ll l, ll r) {
        l++; r++;
        ll len = r - l + 1;
        
        ll hash1 = ((hash[r].ff - (Bpower[len].ff * hash[l-1].ff) % M) + M) % M;
        ll hash2 = ((hash[r].ss - (Bpower[len].ss * hash[l-1].ss) % M) + M) % M;
        
        return {hash1, hash2};
    }
};

// https://leetcode.com/problems/longest-happy-prefix/

class Solution {
public:
    string longestPrefix(string s) {
        int n = s.length();
        ll l1 = 0, r1 = n-2;
        ll l2 = 1, r2 = n-1;

        Hash h(s);

        string ans = "";

        for(ll i=0; i<n-1; i++){
            pair<ll, ll> hash1 = h.get(l1, r1);
            pair<ll, ll> hash2 = h.get(l2, r2);

            int len = r2-l2+1;

            if(hash1 == hash2){
                ans = s.substr(l1, len);
                return ans;
            }
            r1--;
            l2++;
        }

        return ans;
    }
};