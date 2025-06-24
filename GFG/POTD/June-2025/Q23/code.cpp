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
    string minSum(vector<int> &a) {
        int n = a.size();
        string s1 = "", s2 = "";
        sort(a.begin(), a.end());
        for(int i=0; i<n; i++){
            if(i&1){
                s2 += to_string(a[i]);
            }
            else{
                s1 += to_string(a[i]);
            }
        }
        // cout<<s1<<" "<<s2<<endl;
        string ans = "";
        int mn = min(s1.size(), s2.size());
        int c = 0;
        int n1 = s1.length(), n2 = s2.length();
        int i = n1 - 1, j = n2 - 1;
        while(mn--){
            int x = (s1[i] - '0') + (s2[j] - '0') + c;
            c = x / 10;
            ans += to_string(x % 10);
        }

        if(s2.length() > s1.length()) swap(s1, s2);
        if(j > i) swap(i, j);

        for(; i >= 0; i--) {
            int x = (s1[i] - '0') + c;
            c = x / 10;
            ans += to_string(x % 10);
        }

        if(c > 0) ans += to_string(c);
        while(ans.size() > 1 && ans.back() == '0') {
            ans.pop_back();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};