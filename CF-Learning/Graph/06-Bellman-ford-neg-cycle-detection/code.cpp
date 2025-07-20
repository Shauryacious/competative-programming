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
    vector<int> bellmanFord(int n, vector<vector<int>>& edges, int s) {
        vii dist(n, 1e8);
        dist[s] = 0;

        for(int i = 0; i < n - 1; i++){ // n-1 times perform relaxation
            for(auto& edge : edges){
                int u = edge[0], v = edge[1], w = edge[2];
                if(dist[u] != 1e8 && dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Check for negative weight cycle -> perform one more relaxation
        for(auto& edge : edges){
            int u = edge[0], v = edge[1], w = edge[2];
            if(dist[u] != 1e8 && dist[u] + w < dist[v]){
                return {-1}; // Negative weight cycle detected
            }
        }
        
        // If no negative weight cycle, return the distances
        return dist;
    }
};
