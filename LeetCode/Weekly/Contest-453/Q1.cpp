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
#define INF 1000000000

class Solution {
public:
    bool canMakeEqual(vector<int>& a, int k) {
        int n = a.size();
        int cnt1 = count(all(a), 1);
        int cntm1 = n - cnt1;
        if(cnt1 == 0 || cntm1 == 0) {
            return true;
        }

        if((cnt1&1) && (cntm1&1)) {
            return false;
        }

        // atlease one of them is even
        vll v1, vm1;
        for(int i = 0; i < n; i++) {
            if(a[i] == 1) {
                v1.pb(i);
            } else {
                vm1.pb(i);
            }
        }

        int m1 = v1.size(), m2 = vm1.size();
        int sum1 = 0;
        if(m1%2 == 0){
            for(int i= 0; i < m1; i += 2) {
                sum1 += abs(v1[i] - v1[i + 1]);
            }
        }
        else {
            sum1 = INF;
        }

        int sum2 = 0;
        if(m2%2 == 0) {
            for(int i = 0; i < m2; i += 2) {
                sum2 += abs(vm1[i] - vm1[i + 1]);
            }
        }
        else{
            sum2 = INF;
        }

        if(min(sum1, sum2) <= k) {
            return true;
        }

        return false;
    }
};