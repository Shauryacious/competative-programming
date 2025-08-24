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
  public:
    int longestKSubstr(string& s, int k) {
        int n = s.size();

        set<char> st;
        multiset<char> mst;

        int i = 0, j = 0;
        int ans = 0;

        while(j < n){
            st.insert(s[j]);
            mst.insert(s[j]);
            if(st.size() == k){
                ans = max(ans, (j-i+1));
            }

            while(st.size() > k && i <= j){
                mst.erase(mst.find(s[i]));
                if(mst.find(s[i]) == mst.end()){
                    st.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        
        return ans == 0 ? -1 : ans;
    }
};