#include <bits/stdc++.h>
#define ii int
#define ll long long
#define vii vector<int>
#define vll vector<ll>
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007
using namespace std;

class Solution {
    void debug(int x) {
        cout<<"x: "<<x<<endl;
    }
public:
    int countPermutations(vii& comp) {
        int n = comp.size();
        multiset<int> ms;
        ms.insert(comp[0]);
        ll ans = 1;
        for (ii i = 1; i < n; i++) {
            auto it = ms.upper_bound(comp[i] - 1);
            ii cnt = distance(ms.begin(), it);
            if (!cnt) return 0;
            ans = (ans * cnt) % MOD;
            ms.insert(comp[i]);
        }
        return ans;
    }
};
©leetcode