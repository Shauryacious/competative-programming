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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();

        // Step 1: Create a mapping of email to index
        unordered_map<string, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string email = accounts[i][j];
                mp[email].push_back(i);
            }
        }

        // Step 2: DSU (Disjoint Set Union)
        vector<int> par(n), rank(n, 0);
        iota(par.begin(), par.end(), 0); // parent[i] = i initially

        function<int(int)> find = [&](int x) {
            if (par[x] == x) return x;
            return par[x] = find(par[x]);
        };

        auto Union = [&](int x, int y) {
            int px = find(x);
            int py = find(y);
            if (px == py) return;

            if (rank[px] > rank[py]) {
                par[py] = px;
            } else if (rank[py] > rank[px]) {
                par[px] = py;
            } else {
                par[py] = px;
                rank[px]++;
            }
        };

        for (auto& p : mp) {
            const vector<int>& indices = p.second;
            for (int i = 1; i < indices.size(); i++) {
                Union(indices[0], indices[i]);
            }
        }

        // Step 3: Map parent to emails
        unordered_map<int, set<string>> mergedAccounts;
        for (int i = 0; i < n; i++) {
            int pi = find(i);
            for (int j = 1; j < accounts[i].size(); j++) {
                mergedAccounts[pi].insert(accounts[i][j]);
            }
        }

        // Step 4: Create the answer
        vector<vector<string>> ans;
        for (auto& p : mergedAccounts) {
            int pi = p.first;
            vector<string> account(p.second.begin(), p.second.end());
            account.insert(account.begin(), accounts[pi][0]); // insert name
            ans.push_back(account);
        }

        return ans;
    }
};
