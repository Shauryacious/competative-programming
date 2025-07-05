#include <iostream>
#include <vector>

using namespace std;

#define ll long long
#define vll vector<ll>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

#define rep(i, j) for (ll i = 0; i < j; i++)
#define invec(v, n) for (ll i = 0; i < n; i++) cin >> v[i]

const ll N = 1e5 + 10;
const ll M = 1e9 + 7;
vll fact(N + 1);
vll ifact(N + 1);

// Modular multiplication
ll mod_mul(ll a, ll b, ll M) {
    a = a % M;
    b = b % M;
    return (((a * b) % M) + M) % M;
}

// Modular addition
ll mod_add(ll a, ll b, ll M) {
    a = a % M;
    b = b % M;
    return (((a + b) % M) + M) % M;
}

// Exponentiation by squaring
ll expo(ll a, ll n, ll M) {
    ll ans = 1;
    while (n > 0) {
        if (n & 1) ans = mod_mul(ans, a, M);
        a = mod_mul(a, a, M);
        n >>= 1;
    }
    return ans;
}

// Precompute factorial and inverse factorial arrays
void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
        fact[i] = mod_mul(i, fact[i - 1], M);
    }

    // Using Fermat's little theorem for inverse of fact[N]
    ifact[N] = expo(fact[N], M - 2, M);
    for (int i = N - 1; i >= 0; i--) {
        ifact[i] = mod_mul(ifact[i + 1], i + 1, M);
    }
}

// nCr function using precomputed factorials
ll nCr(ll n, ll r, ll M) {
    if (r > n || r < 0) return 0;
    return mod_mul(fact[n], mod_mul(ifact[r], ifact[n - r], M), M);
}

// Solve the problem using the "wrong" formula
void solve() {
    ll t; cin >> t;
    vll N(t); invec(N, t);
    vll K(t); invec(K, t);

    for (int i = 0; i < t; i++) {
        // For each pair (N[i], K[i]), apply the wrong formula
        // C[n][k] = C[n][k-1] + C[n-1][k-1]
        // Compute the wrong binomial coefficient based on the problem
        ll term1 = nCr(N[i]-1, K[i], M);        // C[n][k-1]
        ll term2 = nCr(N[i] - 1, K[i] - 1, M);    // C[n-1][k-1]
        ll ans = mod_add(term1, term2, M);        // Add them modulo M

        cout << ans << endl;
    }
}

int main() {
    fastio();
    precompute();
    solve();
    return 0;
}