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
    int maxDiff(int num) {
        int a = num, b = num;
        vector<int> ans;
        for(int x=0; x<=9; x++) {
            for(int y=0; y<=9; y++){
                string sn = to_string(num);
                for(int i = 0; i < sn.size(); i++) {
                    if(sn[i] - '0' == x) {
                        sn[i] = y + '0';
                    }
                }
                string sa = sn;
                a = stoi(sa);

                if(a == 0) continue;    
                ans.pb(a);

                string sb = sa;
                for(int i = 0; i < sa.size(); i++) {
                    if(sb[i] - '0' == x){
                        sb[i] = y + '0';
                    }
                }

                b = stoi(sb);
                if(b == 0) continue;
                ans.pb(b);
            }
        }

        sort(all(ans));

        if(ans.size() < 2) return 0;

        return ans.back() - ans.front();
    }
};