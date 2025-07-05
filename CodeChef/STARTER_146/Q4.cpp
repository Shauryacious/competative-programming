#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
// #include <bits/stdc++.h>

using namespace std;

// Speed
#define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

// Macros
#define rep(i, j) for (int i = 0; i < j; i++)
#define invec(v, n) for (int i = 0; i < n; i++) cin >> v[i]

// Typedef
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;

void solve(){
    int array_size;
        cin >> array_size;
        vector<long long> numbers;
        
        for(int i = 0; i < array_size; i++) {
            long long element;
            cin >> element;
            numbers.push_back(element);
        }
    
        long long total_sum = 0;
        
        for(int i = 0; i < numbers.size(); i++) {
            total_sum += numbers[i];
        }
        
        long long result = 0;
        long long current_left_sum = 0;
        
        for(int i = 0; i < array_size; i++) {
            if(numbers[i] == 0) {
                if(current_left_sum == total_sum) {
                    result += 2;
                }
                else if(total_sum - current_left_sum == 1) {
                    result++;
                }
                else if(current_left_sum - total_sum == 1) {
                    result++;
                }
            }
            
            current_left_sum += numbers[i];
            total_sum -= numbers[i];
        }
        
        cout << result << endl;
}

int32_t main(){
    fastio();
    ll t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}




// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string>

// using namespace std;

// // Speed
// #define fastio() ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

// // Macros
// #define rep(i, j) for (int i = 0; i < j; i++)
// #define invec(v, n) for (int i = 0; i < n; i++) cin >> v[i]

// // Typedef
// typedef long long ll;
// typedef vector<int> vi;
// typedef vector<ll> vll;

// void solve(){
//     ll n; cin >> n;
//     vll a(n);
//     invec(a, n);

//     ll leadingZeros = 0;
//     for(int i = 0; i < n; i++){
//         if(a[i] == 0){
//             leadingZeros++;
//         }
//         else{
//             break;
//         }
//     }
//     ll trailingZeros = 0;
//     for(int i = n-1; i >= 0; i--){
//         if(a[i] == 0){
//             trailingZeros++;
//         }
//         else{
//             break;
//         }
//     }

//     vll b;
//     ll totalZeros = 0;
//     for(int i = 0; i < n; i++){
//         if(a[i] == 0){
//             totalZeros++;
//         }
//     }

//     ll middleZeros = totalZeros - leadingZeros - trailingZeros;
//     for(int i = 0; i < n; i++){
//         if(a[i] != 0){
//             b.push_back(a[i]);
//         }
//         else{
//             b.push_back(0);
//             while(i < n && a[i] == 0){
//                 i++;
//             }
//             i--;
//         }
//     }

//     for(int i = 0; i < b.size()-2; i++){
//         if(b[i] != 0 && b[i+1] == 0 && b[i+2] != 0){
//             ll diff = abs(b[i] - b[i+2]);
//             if(diff == 0){
//                 middleZeros *= 2;
//             }
//         }
//     }

//     cout<<middleZeros<<endl;
// }

// int32_t main(){
//     fastio();
//     ll t; cin >> t;
//     while(t--){
//         solve();
//     }
//     return 0;
// }









    // ll n; cin >> n;
    // vll a(n);
    // invec(a, n);

    // vector<ll> prefixsum(n);
    // for(int i = 0; i < n; i++){
    //     if(i == 0){
    //         prefixsum[i] = a[i];
    //     }
    //     else{
    //         prefixsum[i] = prefixsum[i-1] + a[i];
    //     }
    // }
    // // for(int i = 0; i < n; i++){
    // //     cout << prefixsum[i] << " ";
    // // }
    // // cout<<endl;

    // vector<ll> suffixsum(n);
    // for(int i = n-1; i >= 0; i--){
    //     if(i == n-1){
    //         suffixsum[i] = a[i];
    //     }
    //     else{
    //         suffixsum[i] = suffixsum[i+1] + a[i];
    //     }
    // }
    // // for(int i = 0; i < n; i++){
    // //     cout << suffixsum[i] << " ";
    // // }
    // // cout<<endl;

    // ll count = 0;
    // for(int i = 0; i < n; i++){
    //     if(a[i] == 0){
    //         // if(i != 0 && i != n-1){
    //             if(prefixsum[i-1] == suffixsum[i+1]){
    //                 count += 2;
    //             }
    //             else if(abs(prefixsum[i-1] - suffixsum[i+1]) == 1){
    //                 count++;
    //             }
    //         // }
    //     }
    // }
    // cout<<count<<endl;