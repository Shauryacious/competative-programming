#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
#define pb push_back
typedef __int128 int128;
const ll mod = 1e9+7;
ll pow2[200000 + 5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    pow2[0] = 1;
    for (int i = 1; i <= 200000; i++)
        pow2[i] = (pow2[i - 1] * 2) % mod;

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<vll> adj(n + 1);
        vll deg(n + 1, 0);

        for (ll i = 0; i < n - 1; i++) {
            ll u, v;
            cin >> u >> v;
            adj[u].pb(v);
            adj[v].pb(u);
            deg[u]++;
            deg[v]++;
        }

        ll mxdeg = *max_element(deg.begin(), deg.end());

        ll leafCount = 0;
        for (ll i = 2; i <= n; i++) {
            if (deg[i] == 1) leafCount++;
        }

        if (leafCount >= 3) {
            cout << 0 << '\n';
            continue;
        }

        if (leafCount <= 1) {
            cout << pow2[n] << '\n';
            continue;
        }

        // If the undirected tree is a simple path (two leaves and max degree 2), the answer is always 4
        if (mxdeg == 2) {
            cout << pow2[2] << endl;
            continue;
        }

        ll leaf1 = -1, leaf2 = -1;
        for (ll i = 2; i <= n; i++) {
            if (deg[i] == 1) {
                if (leaf1 == -1) leaf1 = i;
                else leaf2 = i;
            }
        }

        auto thread_length = [&](ll leaf) {
            ll cnt = 0;
            ll cur = leaf, prev = -1;
            while (cur != -1 && deg[cur] <= 2) {
                cnt++;
                if (cur == 1) break;
                ll nxt = -1;
                for (ll v : adj[cur])
                    if (v != prev) nxt = v;
                prev = cur;
                cur = nxt;
            }
            return cnt;
        };

        ll c1 = thread_length(leaf1);
        ll c2 = thread_length(leaf2);
        ll cnt = min(c1, c2);

        if (c1 == c2) {
            ll rem = n - 2 * cnt + 1;
            cout << pow2[rem] << '\n';
        } else {
            ll rem = n - 2 * cnt;
            ll ans = (pow2[rem] + pow2[rem - 1]) % mod;
            cout << ans << '\n';
        }
    }
    return 0;
}
