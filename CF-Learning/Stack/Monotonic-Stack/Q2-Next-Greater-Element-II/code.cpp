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
public:
    vii nextGreaterElements(vii& a) {
        ii n = a.size();
        stack<ii> st;
        vii ans(n, -1); // Initialize with -1
        // POP -> ANS -> PUSH
        for(ii i=(2*n-1); i>=0; i--){
            // POP
            while(!st.empty() && a[i%n] >= st.top()){
                st.pop();
            }

            // ANS
            if(i < n){ // Only fill ans for the first n elements
                if(!st.empty()){
                    ans[i] = st.top();
                }
                else{
                    ans[i] = -1; 
                }
            }
            // PUSH
            st.push(a[i % n]);
        }

        return ans;
    }
};