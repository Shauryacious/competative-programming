#include <iostream>
#include <vector>
#include <bitset>
#include<unordered_map>
using namespace std;

int main() {
    int t; 
    cin >> t;
    while(t--){
        int n, k; 
        cin >> n >> k;
        vector<bitset<100>> v(n); // Or use array instead of vector for fixed size
        for(int i = 0; i < n; i++){
            string str;
            cin >> str;
            v[i] = bitset<100>(str); // Convert string to bitset and assign to v[i]
        }
        bool flag = true;
        unordered_map<bitset<100>> map;
        for(int i = 0; i < k; i++){
            bitset<100> x(pow(2, i));
            map[x]++;
        }
        if(flag == false) 
            cout << "NO" << endl;
        else 
            cout << "YES" << endl;
    }
    return 0;
}
