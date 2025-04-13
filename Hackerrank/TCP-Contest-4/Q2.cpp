#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<ll>
#define all(x) x.begin(), x.end()
#define pb push_back
#define nl '\n'
#define invec(v, n) for (int i = 0; i < n; i++) cin >> v[i]
#define sz(x) ((int)(x).size())
#define INF 1e18

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vll a(n);
    invec(a, n);

    auto transform = [&](string &s) {
        int n = s.size(), i = 0;
        string res;
        while (i < n) {
            if (s[i] != '0' && s[i] != '1') {
                res.pb(s[i]);
                i++;
                continue;
            }
            res.pb(s[i]);
            char l = s[i];
            i++;
            if (i < n && s[i] == 'X') {
                int st = i;
                while (i < n && s[i] == 'X') i++;
                int len = i - st;
                if (i < n && s[i] == l && (len % 2 == 1)) {
                    char ch = (l == '0' ? '1' : '0');
                    for (int j = 0; j < len; j++) {
                        res.pb(ch);
                        ch = (ch == '0' ? '1' : '0');
                    }
                    res.pb(s[i]);
                    i++;
                } else {
                    for (int j = st; j < st + len; j++) res.pb(s[j]);
                }
            }
        }
        return res;
    };

    auto get = [&](vll &a, int l, int r) {
        ll mx = -INF, cur = 0;
        for (int i = l; i <= r; i++) {
            cur += a[i];
            mx = max(mx, cur);
            if (cur < 0) cur = 0;
        }
        return mx;
    };

    string t = transform(s);
    ll ans = -INF;
    int st = 0, lst = -1;
    char lstc = ' ';

    for (int i = 0; i < n; i++) {
        if (t[i] != 'X') {
            if (lst == -1) {
                lst = i;
                lstc = t[i];
            } else {
                int d = i - lst;
                if ((d % 2 == 0 && t[i] != lstc) || (d % 2 == 1 && t[i] == lstc)) {
                    ans = max(ans, get(a, st, i - 1));
                    st = i;
                }
                lst = i;
                lstc = t[i];
            }
        }

        if (t[i] != 'X' && i + 1 < n && t[i + 1] == 'X') {
            int l = i + 1, r = l;
            while (r < n && t[r] == 'X') r++;
            if (r < n && t[r] != 'X') {
                char lft = t[i], rt = t[r];
                int len = r - l;
                if (lft == rt && (len % 2 == 0)) {
                    ans = max(ans, get(a, st, r - 1));
                    st = r;
                    lst = -1;
                    i = r - 1;
                    continue;
                }
                if (lft != rt) {
                    ans = max(ans, get(a, st, l));
                    st = l;
                    lst = -1;
                    i = l - 1;
                    continue;
                }
            }
        }
    }

    ans = max(ans, get(a, st, n - 1));
    cout << ans << nl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
