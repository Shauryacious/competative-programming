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
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        int n = a.size();

        sort(a.begin(), a.end());

        vvii ans;

        auto f = [&](int i, vii& v, auto&& f) -> void {
            if (i == n) {
                ans.pb(v);
                return;
            }

            // Include the current element
            v.pb(a[i]);
            f(i + 1, v, f);
            v.pop_back();

            // Skip duplicates
            while (i + 1 < n && a[i] == a[i + 1]) {
                i++;
            }

            // Exclude the current element
            f(i + 1, v, f);
        };

        vii v;
        f(0, v, f);

        return ans;
    }
};