#include <bits/stdc++.h> 
vector<string> ans;

void solve(int idx, string& str, string asf, int count) {
    if (idx == str.length()) {
        // If there's a pending count, append it
        if (count > 0) {
            asf += to_string(count);
        }
        ans.push_back(asf);
        return;
    }

    // Include the current character (Take case)
    if (count > 0) {
        // Convert count to string and append it with the current character
        solve(idx + 1, str, asf + to_string(count) + str[idx], 0);
    } else {
        // No count to add, directly append the character
        solve(idx + 1, str, asf + str[idx], 0);
    }

    // Exclude the current character (Skip case)
    solve(idx + 1, str, asf, count + 1);
}

vector<string> findAbbr(string& str) {
    ans.clear(); 
    solve(0, str, "", 0); 
    sort(ans.begin(), ans.end());
    return ans;
}