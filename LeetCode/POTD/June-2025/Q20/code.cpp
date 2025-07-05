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
#define pb push_back
#define MOD 1000000007
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define all(x) (x).begin(), (x).end()
#define INF 1e18

class Solution {
public:
    int maxDistance(string s, int k) {
        ii cntN = count(all(s), 'N');
        ii cntS = count(all(s), 'S');
        ii cntE = count(all(s), 'E');
        ii cntW = count(all(s), 'W');

        auto replace = [&](string str, char oc, char nc, int x) -> string {
            for(int i = 0; i < str.size() && x > 0; i++) {
                if(str[i] == oc) {
                    str[i] = nc;
                    x--;
                }
            }
            return str;
        };

        vector<int> v = {cntN, cntS, cntE, cntW};
        sort(all(v), greater<int>());
        int mx = v[0], mx2 = v[1];
        
        string ans = s;
        if(mx == cntN){ //Replace all S
            int x = min(k, cntS);
            k -= x;
            ans = replace(ans, 'S', 'N', x);
            if(k > 0){
                if(cntE >= cntW){ //Replace all W
                    x = min(k, cntW);
                    k -= x;
                    ans = replace(ans, 'W', 'E', x);
                } else { //Replace all E
                    x = min(k, cntE);
                    k -= x;
                    ans = replace(ans, 'E', 'W', x);
                }
            }
        }
        else if(mx == cntS){ //Replace all N
            int x = min(k, cntN);
            k -= x;
            ans = replace(ans, 'N', 'S', x);
            if(k > 0){
                if(cntE >= cntW){ //Replace all W
                    x = min(k, cntW);
                    k -= x;
                    ans = replace(ans, 'W', 'E', x);
                } else { //Replace all E
                    x = min(k, cntE);
                    k -= x;
                    ans = replace(ans, 'E', 'W', x);
                }
            }
        }
        else if(mx == cntE){ //Replace all W
            int x = min(k, cntW);
            k -= x;
            ans = replace(ans, 'W', 'E', x);
            if(k > 0){
                if(cntN >= cntS){ //Replace all S
                    x = min(k, cntS);
                    k -= x;
                    ans = replace(ans, 'S', 'N', x);
                } else { //Replace all N
                    x = min(k, cntN);
                    k -= x;
                    ans = replace(ans, 'N', 'S', x);
                }
            }
        }
        else{ //Replace all E
            int x = min(k, cntE);
            k -= x;
            ans = replace(ans, 'E', 'W', x);
            if(k > 0){
                if(cntN >= cntS){ //Replace all S
                    x = min(k, cntS);
                    k -= x;
                    ans = replace(ans, 'S', 'N', x);
                } else { //Replace all N
                    x = min(k, cntN);
                    k -= x;
                    ans = replace(ans, 'N', 'S', x);
                }
            }
        }

        auto calc = [&](string str) -> int {
            int mxdist = 0;
            int x = 0, y = 0;
            for(char c : str) {
                if(c == 'N') y++;
                else if(c == 'S') y--;
                else if(c == 'E') x++;
                else if(c == 'W') x--;
                mxdist = max(mxdist, abs(x) + abs(y));
            }
            return mxdist;
        };

        int maxDist1 = calc(ans);
        int maxDist2 = 0;
        string ans2 = ans;
        reverse(all(ans2));
        maxDist2 = calc(ans2);

        return max(maxDist1, maxDist2);
    }
};