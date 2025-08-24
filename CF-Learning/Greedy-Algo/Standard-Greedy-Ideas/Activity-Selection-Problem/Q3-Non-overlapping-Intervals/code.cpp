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
#define vvpii vector<vpii>
#define pb push_back
#define MOD 1000000007
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define pll pair<ll, ll>
#define vpll vector<pll>
#define vvpll vector<vpll>
#define all(x) (x).begin(), (x).end()
#define INF 1e9
#define ff first
#define ss second


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();


        auto cmp = [&](auto& a, auto& b) {
            if(a[1] == b[1]) {
                return a[0] < b[0]; // If end times are equal, sort by start time
            }
            return a[1] < b[1]; // Sort by end time
        };
        sort(intervals.begin(), intervals.end(), cmp);


        //Initialize t with -INF and not with 0
        int mx = 0, t = -INF;

        for(auto i : intervals){
            int st = i[0], en = i[1];
            if(st >= t) {
                mx++;
                t = en; // Update the end time to the current interval's end time
            }
        }

        return n - mx; // Return the number of intervals to remove  
    }
};