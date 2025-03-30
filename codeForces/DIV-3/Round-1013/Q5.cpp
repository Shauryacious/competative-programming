#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MAXN 10000007

vector<int> primes; 
vector<int> is_prime(MAXN, 1); 
vector<int> prime_count(MAXN, 0); 

void sieve() {
    is_prime[0] = is_prime[1] = 0;
    for (ll i = 2; i < MAXN; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (ll j = i * 2; j < MAXN; j += i) {
                is_prime[j] = 0;
            }
        }
    }
    for (ll i = 1; i < MAXN; i++) {
        prime_count[i] = prime_count[i - 1] + is_prime[i];
    }
}

void solve() {
    ll n;
    cin >> n;
    ll ans = 0;

    for (ll a = 1; a <= n; a++) {
        ll max_f = n / a; 
        ans += prime_count[max_f]; 
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve();

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
