// Author : Shaurya Agrawal
// Linkedin: https://www.linkedin.com/in/shauryacious/
// Codeforces: https://codeforces.com/profile/Shauryacious
// Codechef: https://www.codechef.com/users/shauryacious27

#include <bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define nl "\n"

using ll = int;
using vi = vector<int>;

void solve() {
    int n; cin >> n;
    vi preH(n+1, 0), preP(n+1, 0), preS(n+1, 0);
    
    for(int i=0; i<n; i++){
        char c; cin >> c;
        preH[i+1] = preH[i] + (c == 'H');
        preP[i+1] = preP[i] + (c == 'P');
        preS[i+1] = preS[i] + (c == 'S');
    }

    int ans = 0;
    for(int i=1; i<n; i++){
        int left = max({preH[i], preP[i], preS[i]});
        int right = max({preH[n] - preH[i], preP[n] - preP[i], preS[n] - preS[i]});
        ans = max(ans, left + right);
    }

    cout << ans << nl;
}

int main() {
    fastio();
    solve();
    return 0;
}