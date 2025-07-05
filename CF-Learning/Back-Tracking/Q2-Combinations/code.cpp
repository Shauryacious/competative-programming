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
    vector<vector<int>> combine(int n, int k) {
        vector<int> a(n);
        iota(a.begin(), a.end(), 1); 

        vector<vector<int>> ans;

        auto f = [&](int i, int j, vector<int>& curr, auto && f) -> void {
            if(curr.size() == k) {
                ans.push_back(curr);
                return;
            }

            if(i == n) return;

            // Include the current element
            curr.push_back(a[i]);
            f(i + 1, j + 1, curr, f);
            curr.pop_back();


            // Exclude the current element
            f(i + 1, j, curr, f);
        };

        vector<int> curr;
        f(0, 0, curr, f);

        return ans;
    }
};