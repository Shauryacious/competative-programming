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




//User function Template for C++
class Solution{
    class TrieNode{
    public:
        unordered_map<char, TrieNode*> children;
        bool isSpecial;
        int cnt;
        TrieNode(){
            isSpecial = false;
            cnt = 0;
        }
    };
    
    class Trie{
    public:
        TrieNode* root;
        Trie(){
            root = new TrieNode();
        }
        
        void insert(string s){
            TrieNode* curr = root;
            for(auto ch : s){
                if((curr->children).find(ch) == (curr->children).end()){
                    curr->children[ch] = new TrieNode();
                }
                curr = curr->children[ch];
                curr->cnt++;
            }
            curr->isSpecial = true;
        }
        
        vector<string> ans;
        
        void help(vector<string>& a, int n){
            for(auto s : a){
                TrieNode* curr = root;
                string temp = "";
                for(auto ch : s){
                    curr = curr->children[ch];
                    temp += ch;
                    if(curr->cnt == 1) break;
                }
                ans.push_back(temp);
            }
        }
    };
public:
    vector<string> findPrefixes(string arr[], int n){
        vector<string> a(n);
        for(int i=0; i<n; i++){
            a[i] = arr[i];
        }
        
        Trie* t = new Trie();
        
        for(auto s : a){
            t->insert(s);
        }
        
        t->help(a, n);
        
        return t->ans;
    }
};