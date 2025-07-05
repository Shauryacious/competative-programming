ll f(int i, vector<ll>& a, ll rem) {
    if (i < 0 || rem == 0) {
        return *max_element(a.begin(), a.end());
    }
    ll need = max(0LL, a[i+1] - a[i] + 1);
    ll limit = min(need, rem);
    ll best = 0;
    for (ll j = 0; j <= limit; ++j) {
        a[i] += j;
        best = max(best, f(i - 1, a, rem - j));
        a[i] -= j;
    }
    return best;
}

void _Trojan_() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	for (auto &x : a) cin >> x;
	cout << f(n - 2, a, k) << "\n";
}