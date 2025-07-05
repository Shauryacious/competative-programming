#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int cnt = 0, times = n, ans = INT_MAX;
    while (times--) {
        vector<int> temp(a.begin(), a.end());
        sort(temp.begin(), temp.end());
        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) pos[a[i]] = i;
        
        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (temp[i] != a[i]) {
                int ind = pos[temp[i]];
                swap(a[i], a[ind]);
                pos[a[i]] = i;
                pos[a[ind]] = ind;
                swaps++;
            }
        }
        swaps = (swaps > 0) ? swaps - 1 : 0;
        int curr = swaps + cnt;
        ans = min(ans, curr);
        
        vector<int> b(n);
        for (int i = 0; i < n; i++) b[i] = a[(i + 1) % n];
        a = b;
        cnt++;
    }
    
    cout << ans << "\n";
    return 0;
}