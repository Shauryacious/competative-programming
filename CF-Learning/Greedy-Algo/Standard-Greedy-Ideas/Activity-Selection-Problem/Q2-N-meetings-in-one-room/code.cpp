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
#define INF 1e18
#define ff first
#define ss second



class Solution {
  public:
    int maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vpii a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {start[i], end[i]};
        }

        auto cmp = [&](auto& a, auto& b) -> bool {
            if(a.second == b.second) {
                return a.first < b.first; // If end times are equal, sort by start time
            }
            return a.second < b.second;
        };

        sort(a.begin(), a.end(), cmp);

        // for(int i = 0; i < n; i++) {
        //     cout << a[i].first << " " << a[i].second << endl;
        // }


        //start time with -1
        int ans = 0, t = -1;
        for (int i = 0; i < n; i++) {
            if(a[i].ff > t) {
                ans++;
                t = a[i].ss; // Update the end time to the current meeting's end time
            }
        }

        return ans;
    }
};