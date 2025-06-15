#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define vpii vector<pii>
#define pb push_back
#define MOD 1000000007
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define all(x) (x).begin(), (x).end()

class Solution {
  public:
    int kokoEat(vector<int>& a, int k) {
        int n = a.size();
        sort(a.rbegin(), a.rend());


        auto f = [&](ll& s) -> bool {
            ll cnt = 0;
            for(ll i=0; i<n; i++){
                ll x = a[i];
                cnt += (x + s - 1) / s;
            }
            return cnt <= k;
        };

        int l = 1, r = 1e6 + 1;
        ll ans = 1;
        while(l <= r){
            ll m = (l + r) / 2;
            if(f(m)){
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return ans;
    }
};