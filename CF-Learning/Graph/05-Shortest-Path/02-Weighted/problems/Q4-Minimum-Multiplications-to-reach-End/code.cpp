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
#define ff first
#define ss second

class Solution {
  public:
    int minimumMultiplications(vector<int>& a, int s, int e) {
        int N = 1e5;
        vii dist(N, INF);
        dist[s] = 0;

        set<pii> pq; //{dist, node}
        pq.insert({0, s});

        while(!pq.empty()){
            auto it = *pq.begin();
            pq.erase(pq.begin());

            int d = it.ff, u = it.ss;

            for(auto x : a){
                int v = (u * x) % N;
                if(d + 1 < dist[v]){
                    if(pq.count({dist[v], v})){
                        pq.erase({dist[v], v});
                    }

                    dist[v] = d + 1;
                    pq.insert({dist[v], v});
                }
            }
        }

        if(dist[e] == INF) {
            return -1; // If the end node is unreachable
        }
        return dist[e];
    }
};
