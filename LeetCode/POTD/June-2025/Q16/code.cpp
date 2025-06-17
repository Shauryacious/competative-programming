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
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define all(x) (x).begin(), (x).end()

class Solution {
public:
    int maximumDifference(vector<int>& a) {
        int n = a.size();
        vii pre(n, 0), suff(n, 0);
        pre[0] = a[0];
        for(ll i=1; i<n; i++){
            pre[i] = min(pre[i-1], a[i]);
        }
        suff[n-1] = a[n-1];
        for(ll i=n-2; i>=0; i--){
            suff[i] = max(suff[i+1], a[i]);
        }

        int ans = -1;
        for(ll i=0; i<n; i++){
            if(suff[i] > pre[i]){
                ans = max(ans, suff[i] - pre[i]);
            }
        }

        return ans;
    }
};