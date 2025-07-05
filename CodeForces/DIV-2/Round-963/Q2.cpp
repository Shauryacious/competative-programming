#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

// Macros
#define rep(i, j) for (int i = 0; i < j; i++)
#define invec(v, n) for (int i = 0; i < n; i++) cin >> v[i]

// Typedef
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

void solve() {
    ll n;
    cin >> n;
    vll a(n);
    invec(a, n);

    ll oddCount = 0;
    ll maxOdd = -1;
    vll evenVector;
    
    // Separate even and odd numbers, and find the maximum odd number
    for (ll i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            evenVector.push_back(a[i]);
        } else {
            maxOdd = max(maxOdd, a[i]);
            oddCount++;
        }
    }

    sort(evenVector.begin(), evenVector.end()); // Sort the even numbers vector

    ll evenCount = evenVector.size();

    // If there are no odd or no even numbers, no operations are needed
    if (oddCount == 0 || evenCount == 0) {
        cout << 0 << endl;
        return;
    }

    ll operations = 0;
    ll currentSum = maxOdd;

    // Process even numbers
    for (ll i = 0; i < evenCount; i++) {
        ll even = evenVector[i];
        if (currentSum > even) {
            currentSum += even;
            operations++;
        } else {
            cout<<(2+evenCount)-1<<endl;
            return;
        }
    }

    cout << operations << endl;
}

int32_t main() {
    fastio();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
