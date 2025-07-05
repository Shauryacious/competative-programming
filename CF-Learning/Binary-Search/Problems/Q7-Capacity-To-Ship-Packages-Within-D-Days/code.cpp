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

// User function Template for C++

class Solution {
  public:
    int leastWeightCapacity(int a[], int n, int d) {
        // int n = a.size();

        // sort(a, a + n);

        auto f = [&](int x) -> bool {
            int sm = 0, cnt = 1;
            for(int i=0; i<n; i++){
                if(sm + a[i] > x){
                    cnt++;
                    sm = a[i];
                } else {
                    sm += a[i];
                }
            }

            return cnt <= d;
        };
        

        int l = *max_element(a, a + n);
        int r = accumulate(a, a + n, 0);
        int ans = r;

        while(l <= r){
            int m = l + ((r - l) >> 1);

            if(f(m)){
                ans = m;
                r = m - 1;
            } else {
                l = m + 1;
            }
        }

        return ans;
    }
};