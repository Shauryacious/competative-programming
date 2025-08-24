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
    class TrieNode {
    public:
        bool isSpecial;  
        vector<TrieNode*> children; 
        TrieNode() {
            isSpecial = false;
            children.resize(26, NULL);
        }
    };

    class Trie{
    public:
        TrieNode* root;
        Trie(){
            root = new TrieNode();
        }

        // Inster a new word into the Trie
        void insert(string s){
            TrieNode* curr = root; 
            for(auto ch : s){
                int idx = ch - 'a';
                if(curr->children[idx] != NULL){ //is present
                    curr = curr->children[idx];
                }   
                else{
                    curr->children[idx] = new TrieNode();
                    curr = curr->children[idx];
                }
            }

            // after the complete string is scanned, curr is at the last node
            curr->isSpecial = true;
        }

        bool isAllPrefixPresent(string s){
            TrieNode* curr = root;
            bool present = true;
            for(auto ch : s){
                int idx = ch-'a';
                curr = curr->children[idx]; //make curr point to the curr char node
                present &= curr->isSpecial; 
                if(present == false){
                    break;
                }
            }

            return present; //if till the end all the prefixes were present then present will be true, else it will become false in between somewhere
        }
    };


public:
    string longestWord(vector<string>& words) {
        Trie* t = new Trie();
        for(auto s : words){
            t->insert(s);
        }


        string ans = "";
        for(auto word : words){
            if(t->isAllPrefixPresent(word)){
                if(word.length() > ans.length()) ans = word;
                else if(word.length() == ans.length()){
                    ans = min(ans, word); //lexicographically minimum -> T.C. = |s| = 30
                }
            }
        }

        return ans;
    }
};