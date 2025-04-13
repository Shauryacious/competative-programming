typedef long long ll;

const ll MOD = 1e9 + 7;

ll mod_add(ll a, ll b, ll m){
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}

ll mod_sub(ll a, ll b, ll m){
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}

ll dp[101][2][10][2];
// dp[index][tight][last_digit][isValidNumber]


class Solution {

    ll f(ll idx, ll tight, ll prev, ll isValidNum, string s){
        ll n = s.size();
        if(idx == n){
            return isValidNum;
        }

        if(dp[idx][tight][prev][isValidNum] != -1){
            return dp[idx][tight][prev][isValidNum];
        }

        ll bound = tight ? s[idx] - '0' : 9;

        ll ans = 0;
        for(ll i=0; i<=bound; i++){
            ll newTight = tight && (i == bound);
            if(isValidNum == 0){
                if(i == 0){
                    ll temp = f(idx + 1, newTight, prev, 0, s);
                    ans = mod_add(ans, temp, MOD);
                }
                else{ // i != 0
                    ll temp = f(idx + 1, newTight, i, 1, s);
                    ans = mod_add(ans, temp, MOD);
                }
            }
            else{ // Valid No -> number is already started
                if(abs(prev - i) == 1){
                    ll temp = f(idx + 1, newTight, i, 1, s);
                    ans = mod_add(ans, temp, MOD);
                }
            }
        }

        return dp[idx][tight][prev][isValidNum] = ans;
    }

    ll check(string s){
        ll n = s.size();
        if(n == 1){
            return 1;
        }

        bool ok = true;
        for(ll i=1; i<n; i++){
            if(abs(s[i] - s[i-1]) != 1){
                ok = false;
                break;
            }
        }
        return ok ? 1 : 0;
    }

public:
    int countSteppingNumbers(string l, string r) {
        memset(dp, -1, sizeof(dp));
        ll R = f(0, 1, 0, 0, r);

        memset(dp, -1, sizeof(dp));
        ll L = f(0, 1, 0, 0, l);

        ll ans = mod_sub(R, L, MOD);
        if(check(l) == 1){
            ans = mod_add(ans, 1, MOD);
        }

        return ans;
    }
};