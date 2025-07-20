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
    // Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int n, vector<int> adj[]) {
        vii par(n), rank(n);
        
        //1) Initialize each parent by itself
        iota(par.begin(), par.end(), 0);
        
        auto find = [&](int x, auto && find) -> int {
            if(par[x] == x) return x;
            
            return par[x] = find(par[x], find);
        };
        
        auto Union = [&](int x, int y) -> void {
            int px = find(x, find);
            int py = find(y, find);
            
            if(px == py) return;
            
            if(rank[x] > rank[y]){
                par[py] = px;
            }
            else if(rank[y] > rank[x]){ //y papa banega
                par[px] = py;
            }
            else{
                par[py] = px;
                rank[px]++;
            }
        };
        
        for(int u=0; u<n; u++){
            for(auto v : adj[u]){
                if(u < v){ // for not double count -> as undirected graph
                    int pu = find(u, find);
                    int pv = find(v, find);
                    
                    if(pu == pv) return true;
                    
                    //if not then union it
                    Union(pu, pv);
                }
            }
        }
        
        return false;
    }
};