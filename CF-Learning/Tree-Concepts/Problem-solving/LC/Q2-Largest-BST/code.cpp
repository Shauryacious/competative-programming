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


struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int largestBst(Node *root) {
        map<Node*, int> size;
        map<Node*, int> mx;
        map<Node*, int> mn;
        size[NULL] = 0;

        auto dfs = [&](Node* u, auto&& dfs) -> void {
            if(u == NULL){
                size[u] = 0;
                mx[u] = -INF;
                mn[u] = INF;
                return;
            }

            dfs(u->left, dfs);
            dfs(u->right, dfs);

            size[u] = 1 + size[u->left] + size[u->right];
            mx[u] = max(u->data, max(mx[u->left], mx[u->right]));
            mn[u] = min(u->data, min(mn[u->left], mn[u->right]));
        };
        
        dfs(root, dfs);

        map<Node*, bool> isBSTmp;

        auto isBST = [&](Node* u, auto && isBST) -> bool {
            if(u == NULL) return true;

            if(isBSTmp.find(u) != isBSTmp.end()) return isBSTmp[u];
            
            bool ans = false;
            if(mx[u->left] < u->data && u->data < mn[u->right]){
                ans = isBST(u->left, isBST) && isBST(u->right, isBST);
            }
            return isBSTmp[u] = ans;
        };

        int ans = 0;
        auto dfs2 = [&](Node* u, auto && dfs2) -> void {
            if(u == NULL) return;
            
            dfs2(u->left, dfs2);
            dfs2(u->right, dfs2);

            if(isBST(u, isBST)) {
                ans = max(ans, size[u]);
            }
        };

        dfs2(root, dfs2);

        return ans;
    }
};