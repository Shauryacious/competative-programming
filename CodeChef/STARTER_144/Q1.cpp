#include <iostream>
#include <vector>
#include <unordered_set>
#include <map>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long ll;

vector<ll> getFrequencyVector(const map<int, int>& freq) { 
    vector<ll> freqV; 
    for (auto f : freq) { 
        freqV.push_back(f.second); 
    } 
    return freqV; 
} 
 
ll calculateMaximumK(const vector<ll>& freqV) { 
    ll maxK = 0; 
    ll sum = 0; 
    for (ll i = 1; i <= freqV.size(); ++i) { 
        sum += freqV[i - 1]; 
        ll value = (sum / i) * i; 
        maxK = max(maxK, value); 
    } 
    return maxK; 
} 
 
void solve() { 
    ll n; cin >> n; 
 
    vector<ll> v(n); 
    map<int, int> freq; 
    for (ll i = 0; i < n; ++i) { 
        cin >> v[i]; 
        freq[v[i]]++; 
    } 
 
    vector<ll> freqV = getFrequencyVector(freq); 
    sort(freqV.begin(), freqV.end(), greater<ll>()); 
 
    ll maximumK = calculateMaximumK(freqV); 
    cout << maximumK << endl; 
} 
 
int main() { 
    int t; 
    cin >> t; 
 
    while (t--) { 
        solve(); 
    } 
 
    return 0; 
} 


// ### Problem Statement: Largest K

// You have an array \( A \) with \( N \) elements.

// Your task is to find the largest integer \( K \) such that there is a subsequence \( S \) of length \( K \) in which \( K \) is divisible by the number of distinct elements in \( S \).

// #### Input Format
// - The first line contains a single integer \( T \), the number of test cases.
// - For each test case:
//   - The first line contains a positive integer \( N \), the length of the array \( A \).
//   - The second line contains \( N \) space-separated integers, representing the elements of the array \( A \).

// #### Output Format
// - For each test case, output the largest valid \( K \).

// #### Constraints
// - \( 1 \leq T \leq 10^4 \)
// - \( 1 \leq A_i \leq N \leq 2 \cdot 10^5 \)
// - The sum of \( N \) over all test cases will not exceed \( 2 \cdot 10^5 \).

// #### Example
// **Input**
// ```
// 3
// 2
// 2 1
// 4
// 1 2 1 3
// 5
// 1 5 3 2 4
// ```

// **Output**
// ```
// 2
// 3
// 5
// ```

// #### Explanation
// - **Test case 1**: The subsequence [2, 1] has 2 distinct elements, and its length (2) is divisible by the number of distinct elements (2).
// - **Test case 2**: The subsequence [2, 1, 3] has 3 distinct elements, and its length (3) is divisible by the number of distinct elements (3).
// - **Test case 3**: The subsequence [1, 5, 3, 2, 4] has 5 distinct elements, and its length (5) is divisible by the number of distinct elements (5).

// Your goal is to determine the largest \( K \) for each test case that meets the criteria.