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
    int findCheapestPrice(int n, vector<vector<int>>& flights, int s, int e, int k) {
        vvpii adj(n);

        for(int i=0; i<flights.size(); i++){
            int u = flights[i][0], v = flights[i][1], w = flights[i][2];
            adj[u].pb({v, w});
        }

        vector<int> dist(n, INF);

        set<pair<int, pii>> pq; // {stop, {cost, node}}
        pq.insert({0, {0, s}}); // {stops, {cost, node}}
        dist[s] = 0;

        while(!pq.empty()) {
            auto it = *pq.begin();
            pq.erase(pq.begin());

            int stop = it.ff;
            int cost = it.ss.ff;
            int u = it.ss.ss;

            if(stop > k) continue; // If we have exceeded the number of stops

            for(auto p : adj[u]){
                int v = p.ff, w = p.ss;
                if(cost + w < dist[v]) {
                    if(pq.count({stop+1, {dist[v], v}})) {
                        pq.erase({stop+1, {dist[v], v}});
                    }
                    dist[v] = cost + w;
                    pq.insert({stop + 1, {dist[v], v}});
                }
            }
        }

        return dist[e] == INF ? -1 : dist[e];
    }
};