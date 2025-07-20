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
    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();

        vector<int> vis(n, 0), currpath(n, 0), safe(n, 0);

        auto dfs = [&](int u, auto && dfs) -> void {
            vis[u] = 1;
            currpath[u] = 1;

            if(adj[u].size() == 0){
                safe[u] = 1;
                currpath[u] = 0;
                return;
            }

            int issafe = 1;
            for(auto v : adj[u]){
                if(vis[v] && currpath[v]){ // cycle detected
                    safe[u] = 0;
                    currpath[u] = 0;
                    return;
                }
                if(!vis[v]){
                    dfs(v, dfs);
                }
                issafe &= safe[v];
            }

            safe[u] = issafe;

            currpath[u] = 0;
        };

        for(int i = 0; i < n; i++){
            if(!vis[i]){
                dfs(i, dfs);
            }
        }


        vector<int> ans;
        for(int i = 0; i < n; i++){
            if(safe[i]){
                ans.pb(i);
            }
        }
        return ans;
    }
};