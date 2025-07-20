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
    string decodeString(string s) {
        int n = s.size();


        stack<string> eles;
        stack<int> nums;
        string ans = "";

        for(int i = 0; i < n; i++){
            
            if(s[i] == ']'){
                string curr = "";
                while(!eles.empty()){
                    if(eles.top() == "["){
                        eles.pop();
                        break;
                    }
                    curr = eles.top() + curr;
                    eles.pop();
                }
                int num = nums.top();
                nums.pop();
                string res = "";
                for(int j = 0; j < num; j++){
                    res += curr;
                }
                eles.push(res);
            }
            else if('1' <= s[i] && s[i] <= '9'){
                string nn = "";
                while(i < n && '0' <= s[i] && s[i] <= '9'){
                    nn += s[i];
                    i++;
                }
                i--;
                nums.push(stoi(nn));
            }
            else{
                eles.push(s.substr(i, 1));
            }
        }

        while(!eles.empty()){
            ans = eles.top() + ans;
            eles.pop();
        }
        return ans;
    }
};