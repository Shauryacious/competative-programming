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
#define INF 1e9

class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();

        int bd = 0, sd = 0; // buying day, selling day
        int profit = 0;

        for(int i=0; i<n-1; i++){
            if(p[i] <= p[i+1]){ // if price is increasing
                sd = i+1; // update selling day
            } else {
                profit += (p[sd] - p[bd] > 0 ? p[sd] - p[bd] : 0); // add profit if any
                bd = i+1; // update buying day to current day
                sd = i+1; // reset selling day to current day
            }
        }

        profit += (p[sd] - p[bd] > 0 ? p[sd] - p[bd] : 0); // add profit for the last segment
        return profit; // return total profit
    }
};