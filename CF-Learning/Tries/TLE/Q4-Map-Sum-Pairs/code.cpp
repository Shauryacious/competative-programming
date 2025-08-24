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



class MapSum {
    class TrieNode {
    public:
        unordered_map<char, TrieNode*> children;
        bool isSpecial;
        int sum;
        TrieNode() {
            isSpecial = false;
            sum = 0;
        }
    };

    class Trie {
    public:
        TrieNode* root;
        unordered_map<string, int> keyValues; // Track previous values
        Trie() {
            root = new TrieNode();
        }

        void insert(string s, int val) {
            int diff = val;
            if (keyValues.find(s) != keyValues.end()) {
                diff -= keyValues[s]; // Adjust sum by removing old value
            }
            keyValues[s] = val; // Update key-value map
            
            TrieNode* curr = root;
            for (auto ch : s) {
                if (curr->children.find(ch) == curr->children.end()) {
                    curr->children[ch] = new TrieNode();
                }
                curr = curr->children[ch];
                curr->sum += diff; // Adjust sum correctly
            }
            curr->isSpecial = true;
        }

        int getSum(string s) {
            TrieNode* curr = root;
            for (auto ch : s) {
                if (curr->children.find(ch) != curr->children.end()) {
                    curr = curr->children[ch];
                } else {
                    return 0;
                }
            }
            return curr->sum;
        }
    };

public:
    Trie* t;
    MapSum() {
        t = new Trie();
    }
    
    void insert(string key, int val) {
        t->insert(key, val);
    }
    
    int sum(string prefix) {
        return t->getSum(prefix);
    }
};