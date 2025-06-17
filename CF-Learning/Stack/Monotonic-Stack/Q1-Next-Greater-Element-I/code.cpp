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

using namespace std;

#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define vpii vector<pii>
#define pb push_back
#define MOD 1000000007
#define INF 1e18

class Solution {
    vii nge(vii& a){
        ii n = a.size();
        stack<ii> st;
        vii ans(n, -1); // Initialize with -1
        // POP -> ANS -> PUSH
        for(ii i=n-1; i>=0; i--){
            // POP
            while(!st.empty() && a[i] >= st.top()){
                st.pop();
            }

            // ANS
            if(!st.empty()){
                ans[i] = st.top();
            }
            else{
                ans[i] = -1; 
            }

            // PUSH
            st.push(a[i]);
        }

        return ans;
    }
public:
    vii nextGreaterElement(vii& a1, vii& a2) {
        ii n = a2.size();
        vii ans = nge(a2);
        unordered_map<ii, ii> mp;
        for(ii i=0; i<n; i++){
            mp[a2[i]] = ans[i];
        }

        vii res;
        for(auto x : a1){
            res.pb(mp[x]);
        }

        return res;
    }
};