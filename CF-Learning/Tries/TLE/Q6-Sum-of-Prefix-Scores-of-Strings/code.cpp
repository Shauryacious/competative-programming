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



class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    int cnt = 0;
};

// Class that implements the Trie (prefix tree) data structure
class Trie {
public:
    // Root node of the Trie
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string& s) {
        TrieNode* curr = root;
        for(auto ch : s){
            if(curr->children.find(ch) == curr->children.end()){ // Not found
                curr->children[ch] = new TrieNode(); 
            }

            curr = curr->children[ch]; // Move to the child node
            curr->cnt++; // Increment the count of words passing through this node
        }
    }


    int getPrefixScoreSum(string s) {
        int ans = 0;
        TrieNode* curr = root;
        for(auto ch : s){
            if(curr->children.find(ch) == curr->children.end()){ // If character not found, break
                break;
            }

            curr = curr->children[ch]; // Move to the child node
            ans += curr->cnt;
        }

        return ans; 
    }
};

class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;  

        // Insert all words into the Trie
        for (auto word : words) {
            trie.insert(word);
        }

        // Calculate the sum of prefix scores for each word
        vector<int> ans;
        for (auto word : words) {
            // For each word, calculate the sum of scores for its prefixes using the Trie
            ans.pb(trie.getPrefixScoreSum(word));
        }

        return ans;
    }
};