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
    string findOrder(vector<string> &words) {
        int n = words.size();
        unordered_map<char, set<char>> adj;
        unordered_map<char, int> indegree;

        for(auto word : words) {
            for(char c : word) {
                indegree[c] = 0; // Initialize indegree for each character
            }
        }

        for(int i=0; i<n-1; i++){
            string word1 = words[i];
            string word2 = words[i+1];
            int j = 0;
            while(j < min(word1.size(), word2.size()) && word1[j] == word2[j]) {
                j++;
            }

            // ❗ Prefix condition — invalid if word1 > word2 and common prefix
            if(j == word2.size() && word1.size() > word2.size()) {
                return "";
            }

            if(j < min(word1.size(), word2.size())) {
                char u = word1[j];
                char v = word2[j];
                if(adj[u].find(v) == adj[u].end()) {
                    adj[u].insert(v);
                    indegree[v]++;
                }
            }
        }

        queue<char> q;
        for(auto p : indegree) {
            if(p.second == 0) {
                q.push(p.first);
            }
        }

        string order = "";
        while(!q.empty()) {
            char u = q.front();
            q.pop();
            order += u;

            for(char v : adj[u]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }

        if(order.size() == indegree.size()) {
            return order;
        } else {
            return ""; // Cycle detected or not all characters are included
        }          
    }
};
