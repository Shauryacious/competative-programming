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
    int primeSubarray(vector<int>& a, int k) {
        vii primes(50005, 1);
        for(int i=2; i*i <= 50002; i++){
            if(primes[i]){
                for(int j=i*i; j<=50002; j+=i){
                    primes[j] = 0;
                }
            }
        }

        set<ii> st;
        for(int i=2; i<=50002; i++){
            if(primes[i]){
                st.insert(i);
            }
        }

        // for(auto it : st){
        //     cout<<it<<" ";
        // }
        // cout<<endl;

        int n = a.size();
        int i = 0, j = 0;
        multiset<int> mnst;
        multiset<ii, greater<ii>> mxst;

        int ans = 0;
        int i = 0, j = 0;
        while(j < n){
            if(st.find(a[j]) != st.end()){
                mnst.insert(a[j]);
                mxst.insert(a[j]);
            }

            
        }
    }
};