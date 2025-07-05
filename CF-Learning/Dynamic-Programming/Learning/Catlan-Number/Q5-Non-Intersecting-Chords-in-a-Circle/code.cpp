#define MOD 1000000007
#define ll long long

int Solution::chordCnt(int n) {
    ll dp[1001];
    memset(dp, 0, sizeof(dp));
    dp[0] = 1; // Base case: 1 way to form an empty tree
    dp[1] = 1; // Base case: 1 way to form a tree with one node

    for(int i=2; i<=n; i++){
        for(int j=1; j<=i; j++){
            dp[i] += ((dp[j-1] * dp[i-j]) % MOD); 
            dp[i] %= MOD; // Ensure we do not exceed MOD
        }
    }

    return (int)dp[n];
}

// https://www.interviewbit.com/problems/intersecting-chords-in-a-circle/