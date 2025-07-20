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




class Node{
public:
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};


class Solution {
  public:
    void correctBST(Node* root) {
        Node* first = NULL;
        Node* mid = NULL;
        Node* last = NULL;
        Node* prev = new Node(INT_MIN);

        auto dfs = [&](Node* u, auto && dfs) -> void {
            if (!u) return;

            dfs(u->left, dfs);

            if(prev->data > u->data){
                if(!first) {
                    first = prev;
                    mid = u;
                } else {
                    last = u;
                }
            }

            prev = u;
            dfs(u->right, dfs);
        };

        dfs(root, dfs);

        //if both first and last are found, swap their data
        if(first && last) {
            swap(first->data, last->data);
        } 
        
        // if only first -> swap first and mid
        else if(first && mid) {
            swap(first->data, mid->data);
        }
    }
};