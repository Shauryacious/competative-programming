class Solution {
    int dp[10][2][6][6][21][2];
    // State : dp[idx][tight][evencnt][oddcnt][remainder][isValidNumber]
    // idx : current index in the number (number length can be 9 at max = 1e9)
    // tight : 0 or 1
    // evencnt = count of even digits at max 5
    // oddcnt = count of odd digits at max 5
    // remainder = 0 to 20 => max 20
    // isValidNumber = 0 or 1

    int f(int idx, int tight, int ecnt, int ocnt, int r, int isValidNum, string& s, int k){
        int n = s.size();
        // Prune base case
        if(ocnt > 5 || ecnt > 5) return 0;

        // Base case
        if(idx == n){
            if(ocnt == ecnt && r == 0 && isValidNum) return 1;
            return 0;
        }

        // Check if already calculated
        if(dp[idx][tight][ecnt][ocnt][r][isValidNum] != -1) return dp[idx][tight][ecnt][ocnt][r][isValidNum];

        // Get the upper limit of the digit
        int bound = tight ? s[idx] - '0' : 9;

        int ans = 0;
        for(int i=0; i<=bound; i++){
            int newTight = tight && (i == bound);
            if(isValidNum == 0){ // is not a valid num -> leading zeros
                if(i == 0){ // Continues to remain a leading zero -> invalid
                    ans += f(idx+1, newTight, ecnt, ocnt, r, 0, s, k);
                }
                else if(i&1){ // odd

                    ans += f(idx+1, newTight, ecnt, ocnt+1, (r*10 + i) % k, 1, s, k);
                }
                else{ // even
                    ans += f(idx+1, newTight, ecnt+1, ocnt, (r*10 + i) % k, 1, s, k);
                }
            }
            else{ // is a valid num
                if(i&1){ // odd
                    ans += f(idx+1, newTight, ecnt, ocnt+1, (r*10 + i) % k, 1, s, k);
                }
                else{ // even
                    ans += f(idx+1, newTight, ecnt+1, ocnt, (r*10 + i) % k, 1, s, k);
                }
            }
        }

        // Store the result
        return dp[idx][tight][ecnt][ocnt][r][isValidNum] = ans;
    }

    int check(string l, int k){
        int ecnt = 0, ocnt = 0;
        for(int i=0; i<l.size(); i++){
            int d = l[i] - '0';
            if(d&1){ // odd
                ocnt++;
            }
            else{ // even
                ecnt++;
            }
        }
        int x = stoi(l);
        int r = x % k; 
        if(ocnt == ecnt && r == 0) return 1;
        return 0;
    }
public:


    int numberOfBeautifulIntegers(int l, int r, int k) {
        // Convert l and r to string
        string L = to_string(l);
        string R = to_string(r);

        int ans = 0;

        memset(dp, -1, sizeof(dp));
        // Count of beautiful numbers in [1, r]
        ans += f(0, 1, 0, 0, 0, 0, R, k); 

        memset(dp, -1, sizeof(dp));
        // Count of beautiful numbers in [1, l]
        ans -= f(0, 1, 0, 0, 0, 0, L, k);

        // Count of beautiful numbers in [l, r]
        // Check if l is a beautiful number
        ans += check(L, k);

        return ans;
    }
};