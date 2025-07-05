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
#define INF 1e9

class Solution {
public:
    int minSteps(int n) {
        if(n==1) return 0;

        auto f = [&](int curr, int clip, auto && f) -> int {
            if(curr > n) return INF;
            if(curr == n) return 0;

            // copy the current value to the clipboard
            // but only when the current value is not equal to the clipboard value
            int copy = 1 + (curr == clip ? INF : f(curr, curr, f));

            // paste the value from the clipboard
            int paste = 1 + f(curr + clip, clip, f);

            // return the minimum of copy and paste operations
            return min(copy, paste);
        };

        return 1+ f(1, 1, f);
    }
};