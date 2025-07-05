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
    bool validgroup(vector<int> &a, int k) {
        int n = a.size();
        if (n % k != 0) return false;

        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[a[i]]++;
        }

        while (!mp.empty()) {
            int start = mp.begin()->first;

            // Try to form a group of size k starting from 'start'
            for (int i = 0; i < k; i++) {
                int curr = start + i;
                if (mp.find(curr) == mp.end()) {
                    return false;
                }
                mp[curr]--;
                if (mp[curr] == 0) {
                    mp.erase(curr);
                }
            }
        }

        return true;
    }
};
