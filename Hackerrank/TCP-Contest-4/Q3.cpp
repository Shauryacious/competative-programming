#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define pb push_back
#define nl "\n"
 
void solve() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll n, m;
    cin >> n >> m;
    vector<map<string, ll>> a(n);
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < m; j++) {
            string s;
            cin >> s;
            string name = "", num = "";
            bool flag = true;
            for (char c : s) {
                if (flag && c != '_') name += c;
                else if (c == '_') flag = false;
                else if (!flag) num += c;
            }
            ll num1 = stoll(num);
            a[i][name] = num1;
        }
    }
 
    set<string> st;
    map<string, ll> mp;
    for (auto &p : a[0]) {
        st.insert(p.first);
        mp[p.first] = p.second;
    }
 
    vector<string> ans;
    for (ll i = 0; i < n; i++) {
        if (st.empty()) break;
        ll currmx = -1;
        vector<string> temp, toRemove;
        for (auto name : st) {
            if (a[i].count(name))
                mp[name] = min(mp[name], a[i][name]);
        }
        for (auto name : st)
            currmx = max(currmx, mp[name]);
        for (auto name : st) {
            if (mp[name] == currmx) {
                temp.pb(name);
                toRemove.pb(name);
            }
        }
        for (auto name : toRemove)
            st.erase(name);
        sort(temp.begin(), temp.end());
        for (auto name : temp)
            ans.pb(name);
    }
    if (!st.empty()) {
        vector<string> remain(st.begin(), st.end());
        sort(remain.begin(), remain.end());
        for (auto name : remain)
            ans.pb(name);
    }
    for (auto name : ans)
        cout << name << " ";
    cout << nl;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
