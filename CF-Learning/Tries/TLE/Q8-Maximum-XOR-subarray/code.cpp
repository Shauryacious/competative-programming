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


#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    int isSpecial;
    unordered_map<int, TrieNode*> children;
    TrieNode() {
        isSpecial = 0;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }

    void insert(int n) {
        TrieNode* curr = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (1 << i) & n ? 1 : 0;
            if (curr->children.find(bit) == curr->children.end()) {
                curr->children[bit] = new TrieNode();
            }
            curr = curr->children[bit];
        }
        curr->isSpecial = 1;
    }

    int getMaxXOR(int n) {
        TrieNode* curr = root;
        int maxXOR = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (1 << i) & n ? 1 : 0;
            int oppobit = bit ^ 1;
            if (curr->children.find(oppobit) != curr->children.end()) {
                maxXOR |= (1 << i);
                curr = curr->children[oppobit];
            } else {
                curr = curr->children[bit];
            }
        }
        return maxXOR;
    }
};

class Solution {
public:
    int maxSubarrayXOR(int n, int a[]) {
        Trie* t = new Trie();
        vector<int> preXor(n);
        preXor[0] = a[0];
        for (int i = 1; i < n; i++) {
            preXor[i] = preXor[i - 1] ^ a[i];
        }

        t->insert(0); // Handle subarrays starting at index 0
        int ans = 0;

        for (int i = 0; i < n; i++) {
            t->insert(preXor[i]);
            int curr = t->getMaxXOR(preXor[i]);
            ans = max(ans, curr);
        }

        return ans;
    }
};
