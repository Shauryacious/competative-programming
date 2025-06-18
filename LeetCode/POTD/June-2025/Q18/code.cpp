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
#define INF 1e18


class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& a, int k) {
        int n = a.size();   
        sort(all(a));
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i=1; i<=n; i++){
            temp.push_back(a[i-1]);
            if(i % 3 == 0){
                if(temp[2] - temp[0] > k) {
                    return {};
                }
                ans.push_back(temp);
                temp.clear();
            }
        }

        if(!temp.empty()) {
            return {};
        }

        return ans;
    }
};