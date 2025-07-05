#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define vpii vector<pii>
#define pb push_back
#define MOD 1000000007
#define ll long long
#define vll vector<ll>

class Solution {
public:
    ll maxGCDScore(vii& a, int k) {
        ii n = a.size();
        ll ans = 0;
        vpii dp1, dp2;

        for(ii j = 0; j < n; j++) {
            dp2.clear();
            dp2.pb({a[j], 0});
            if(k > 0) dp2.pb({a[j]*2, 1});

            for(auto &p : dp1) {
                ii g = gcd(p.first, a[j]);
                dp2.pb({g, p.second});
                if(p.second < k) dp2.pb({gcd(p.first, a[j]*2), p.second + 1});
            }

            sort(dp2.begin(), dp2.end(), [](pii &x, pii &y){
                return x.first < y.first || (x.first == y.first && x.second < y.second);
            });

            dp1.clear();
            for(auto &p : dp2) {
                if(dp1.empty() || dp1.back().first != p.first) dp1.pb(p);
            }

            for(auto &p : dp1) {
                if(p.second <= k) ans = max(ans, 1LL * p.first * (j + 1));
            }
        }
        return ans;
    }
};
