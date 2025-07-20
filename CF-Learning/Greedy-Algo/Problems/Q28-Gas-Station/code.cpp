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
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int tgas = accumulate(all(gas), 0);
        int tcost = accumulate(all(cost), 0);

        if(tgas < tcost) {
            return -1; // Not enough gas to complete the circuit
        }

        int n = gas.size();

        int stidx = 0, currgas = 0;

        for(int i = 0; i < n; i++) {
            currgas += gas[i] - cost[i];

            if(currgas < 0) {
                stidx = i + 1; // Reset starting index
                currgas = 0; // Reset current gas
            }
        }

        return stidx;
    }
};