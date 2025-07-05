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
    vector<string> ratInMaze(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        vector<char> dir = {'D', 'U', 'R', 'L'};

        vector<string> ans;

        auto f = [&](int i, int j, string s, auto && f) -> void {
            if(i == m-1 && j == n-1){
                ans.pb(s);
                return;
            }

            for(int k = 0; k < 4; k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                if(a[ni][nj] == 0) continue;

                a[ni][nj] = 0; // mark as visited
                s.pb(dir[k]);
                f(ni, nj, s, f); // recursive call
                s.pop_back(); 
                a[ni][nj] = 1; // unmark as visited
            }
        };
        

        if(a[0][0] == 0 || a[m-1][n-1] == 0) {
            return ans; // if start or end is blocked
        }

        a[0][0] = 0; // mark start as visited
        f(0, 0, "", f); // start from (0, 0) with empty path
        a[0][0] = 1; // unmark start as visited

        sort(all(ans)); // sort the paths lexicographically
        return ans;
    }
};