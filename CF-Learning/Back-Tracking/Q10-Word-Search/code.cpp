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
    bool exist(vector<vector<char>>& a, string word) {
        int n = a.size(), m = a[0].size();

        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};

        auto f = [&](int i, int j, int idx, auto && f) -> bool {
            if(idx == word.size()) return true;

            char temp = a[i][j];
            a[i][j] = '#'; // Mark as visited
            bool ans = false;

            for(int k = 0; k < 4; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                if(a[ni][nj] == '#') continue; // Already visited
                if(idx + 1 < word.size() && a[ni][nj] == word[idx + 1]){
                    ans |= f(ni, nj, idx + 1, f);
                }
            }

            a[i][j] = temp; // Unmark

            return ans;
        };

        bool ans = false;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(a[i][j] == word[0]){
                    ans |= f(i, j, 0, f);
                }
            }
        }

        return ans;
    }
};