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
    vector<vector<int>> combinationSum2(vector<int>& a, int t) {
        int n = a.size();

        sort(a.begin(), a.end());

        vector<vector<int>> ans;

        auto f = [&](int i, int curr, vii& v, auto && f) -> void {
            if(curr > t) return;

            if(i == n){
                if(curr == t){
                    ans.push_back(v);
                }
                return;
            }


            // Include the current element
            v.push_back(a[i]);
            f(i + 1, curr + a[i], v, f);
            v.pop_back();

            // Exclude the current element
            while(i + 1 < n && a[i] == a[i + 1]) i++; // Skip duplicates
            f(i + 1, curr, v, f);
        };

        vii v;
        f(0, 0, v, f);

        return ans;
    }
};