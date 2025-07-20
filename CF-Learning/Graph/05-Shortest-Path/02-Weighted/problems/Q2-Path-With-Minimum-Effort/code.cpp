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
#define all(x) (x).begin(), (x).end()
#define INF 1e9

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        vvii ans(n, vii(m, INF));

        vii di = {-1, 0, 1, 0};
        vii dj = {0, 1, 0, -1};

        set<pair<int, pii>> pq; // {effort, {x, y}}
        pq.insert({0, {0, 0}});
        ans[0][0] = 0;

        while(!pq.empty()){
            auto [effort, pos] = *pq.begin();
            pq.erase(pq.begin());
            auto [i, j] = pos;

            for(int k = 0; k < 4; k++) {
                int ni = i + di[k], nj = j + dj[k];
                if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;

                int newEffort = max(effort, abs(g[ni][nj] - g[i][j]));
                if(newEffort < ans[ni][nj]) {
                    if(pq.count({ans[i][j], {i, j}})) {
                        pq.erase({ans[i][j], {i, j}});
                    }
                    ans[ni][nj] = newEffort;
                    pq.insert({newEffort, {ni, nj}});
                }
            }
        }

        return ans[n-1][m-1];
    }
};