// Author : Shaurya Agrawal
// Linkedin: https://www.linkedin.com/in/shauryacious/
// Codeforces: https://codeforces.com/profile/Shauryacious
// Love you mumma <3

#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<bitset>
#include<unordered_map>
#include<unordered_set>
#include<chrono>
#include<random>
#include<string>
#include<functional>
#include<iomanip>
#include<limits>
#include<array>
#include<utility>
#include<functional>
#include<iterator>
#include<cstring>

using namespace std;


#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define vpii vector<pii>
#define pb push_back
#define MOD 1000000007
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define all(x) (x).begin(), (x).end()
#define INF 1e18


// Recursion Solution
class Solution {
public:
    int maxSizeSlices(vector<int>& a) {
        int k = a.size();
        int n = k / 3;

        auto f = [&](int i, int last, int cnt, auto&& f) -> int {
            if (i >= last) {
                return 0;
            }

            if (cnt == 0) {
                return 0;
            }

            //Case 1: take the current slice
            int take = a[i] + f(i + 2, last, cnt - 1, f);

            //Case 2: do not take the current slice i.e. skip
            int skip = f(i + 1, last, cnt, f);

            return max(take, skip);
        };

        //Case 1: take the first slice -> cant take the last slice -> [0, k - 2]
        int takeFirst = f(0, k - 1, n, f);

        //Case 2: do not take the first slice -> can take the last slice -> [1, k - 1]
        int takeLast = f(1, k, n, f);

        return max(takeFirst, takeLast);
    }
};


// Recursion + dp Solution = Memoization
class Solution {
public:
    int maxSizeSlices(vector<int>& a) {
        int k = a.size();
        int n = k / 3;

        int dp[501][501];

        auto f = [&](int i, int last, int cnt, auto&& f) -> int {
            if (i >= last) {
                return 0;
            }

            if (cnt == 0) {
                return 0;
            }

            if (dp[i][cnt] != -1) {
                return dp[i][cnt];
            }

            //Case 1: take the current slice
            int take = a[i] + f(i + 2, last, cnt - 1, f);

            //Case 2: do not take the current slice i.e. skip
            int skip = f(i + 1, last, cnt, f);

            return dp[i][cnt] = max(take, skip);
        };

        //Case 1: take the first slice -> cant take the last slice -> [0, k - 2]
        memset(dp, -1, sizeof(dp));
        int takeFirst = f(0, k - 1, n, f);

        //Case 2: do not take the first slice -> can take the last slice -> [1, k - 1]
        memset(dp, -1, sizeof(dp));
        int takeLast = f(1, k, n, f);

        return max(takeFirst, takeLast);
    }
};

// Tabulation Solution
class Solution {
public:
    int maxSizeSlices(vector<int>& a) {
        int k = a.size();
        int n = k / 3;

        auto solve = [&](int start, int end) {
            vector<vector<int>> dp(k + 2, vector<int>(n + 1, 0));

            for (int i = end - 1; i >= start; --i) {
                for (int cnt = 1; cnt <= n; ++cnt) {
                    int take = a[i] + dp[i + 2][cnt - 1];
                    int skip = dp[i + 1][cnt];
                    dp[i][cnt] = max(take, skip);
                }
            }
            return dp[start][n];
        };

        int takeFirst = solve(0, k - 1);  // Exclude last
        int takeLast = solve(1, k);      // Exclude first

        return max(takeFirst, takeLast);
    }
};

Simplest Clean Solution | Recursion -> Memoization -> Tabulation | Logic Building 🎈

# Intuition
We need to choose `n = k/3` non-adjacent slices from a circular array to maximize the sum.  
Since it's circular, we cannot take both the first and last elements together.

# Approach
Try two cases:
1. Include the first slice → exclude the last → range [0, k-2]
2. Exclude the first slice → include the last → range [1, k-1]  
Use recursion, then memoization, and finally tabulation to optimize.

# Complexity
- Time complexity:  
  - Recursion: Exponential  
  - Memoization: $$O(k \cdot n)$$  
  - Tabulation: $$O(k \cdot n)$$  

- Space complexity:  
  - Recursion: $$O(k)$$ stack space  
  - Memoization/Tabulation: $$O(k \cdot n)$$


# Code
```cpp []

// Author : Shaurya Agrawal
// Linkedin: https://www.linkedin.com/in/shauryacious/
// Codeforces: https://codeforces.com/profile/Shauryacious
// Love you mumma <3


// Recursion Solution
class Solution {
public:
    int maxSizeSlices(vector<int>& a) {
        int k = a.size();
        int n = k / 3;

        auto f = [&](int i, int last, int cnt, auto&& f) -> int {
            if (i >= last) {
                return 0;
            }

            if (cnt == 0) {
                return 0;
            }

            //Case 1: take the current slice
            int take = a[i] + f(i + 2, last, cnt - 1, f);

            //Case 2: do not take the current slice i.e. skip
            int skip = f(i + 1, last, cnt, f);

            return max(take, skip);
        };

        //Case 1: take the first slice -> cant take the last slice -> [0, k - 2]
        int takeFirst = f(0, k - 1, n, f);

        //Case 2: do not take the first slice -> can take the last slice -> [1, k - 1]
        int takeLast = f(1, k, n, f);

        return max(takeFirst, takeLast);
    }
};


// Recursion + dp Solution = Memoization
class Solution {
public:
    int maxSizeSlices(vector<int>& a) {
        int k = a.size();
        int n = k / 3;

        int dp[501][501];

        auto f = [&](int i, int last, int cnt, auto&& f) -> int {
            if (i >= last) {
                return 0;
            }

            if (cnt == 0) {
                return 0;
            }

            if (dp[i][cnt] != -1) {
                return dp[i][cnt];
            }

            //Case 1: take the current slice
            int take = a[i] + f(i + 2, last, cnt - 1, f);

            //Case 2: do not take the current slice i.e. skip
            int skip = f(i + 1, last, cnt, f);

            return dp[i][cnt] = max(take, skip);
        };

        //Case 1: take the first slice -> cant take the last slice -> [0, k - 2]
        memset(dp, -1, sizeof(dp));
        int takeFirst = f(0, k - 1, n, f);

        //Case 2: do not take the first slice -> can take the last slice -> [1, k - 1]
        memset(dp, -1, sizeof(dp));
        int takeLast = f(1, k, n, f);

        return max(takeFirst, takeLast);
    }
};

// Tabulation Solution
class Solution {
public:
    int maxSizeSlices(vector<int>& a) {
        int k = a.size();
        int n = k / 3;

        auto solve = [&](int start, int end) {
            vector<vector<int>> dp(k + 2, vector<int>(n + 1, 0));

            for (int i = end - 1; i >= start; --i) {
                for (int cnt = 1; cnt <= n; ++cnt) {
                    int take = a[i] + dp[i + 2][cnt - 1];
                    int skip = dp[i + 1][cnt];
                    dp[i][cnt] = max(take, skip);
                }
            }
            return dp[start][n];
        };

        int takeFirst = solve(0, k - 1);  // Exclude last
        int takeLast = solve(1, k);      // Exclude first

        return max(takeFirst, takeLast);
    }
};


```

