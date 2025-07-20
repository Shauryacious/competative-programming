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
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        vector<vector<int>> revadj(n);

        vector<int> indeg(n, 0);
        
        for(int u=0; u<n; u++){
            for(auto v : adj[u]){
                revadj[v].pb(u);
                indeg[u]++;
            }
        }

        queue<int> q;

        for(int i=0; i<n; i++){
            if(indeg[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.pb(u);

            for(auto v : revadj[u]){
                indeg[v]--;
                if(indeg[v] == 0){
                    q.push(v);
                }
            }
        }

        sort(all(ans));
        return ans;
    }
};
