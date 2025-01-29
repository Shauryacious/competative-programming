// https://www.youtube.com/watch?v=6LXXAMQZztE

class Solution {
    // max subarray sum
    int kadane_algo(vector<int> v){
        int n = v.size();

        int mx = 0;
        int sum = 0;

        for(int i=0; i<n; i++){
            if(sum + v[i] >= v[i]){
                sum += v[i];
            }
            else{
                sum = v[i];
            }

            mx = max(mx, sum);
        }

        return mx;
    }
public:
    int maximumsSplicedArray(vector<int>& a, vector<int>& b) {
        int n = a.size();

        int s1 = accumulate(a.begin(), a.end(), 0);
        int s2 = accumulate(b.begin(), b.end(), 0);
        int ans = max(s1, s2);

        vector<int> diff(n);
        for(int i=0; i<n; i++){
            diff[i] = b[i] - a[i];
        }

        int s1_new = s1 + kadane_algo(diff);
        ans = max(ans, s1_new);

        for(int i=0; i<n; i++){
            diff[i] *= -1;
        }

        int s2_new = s2 + kadane_algo(diff);
        ans = max(ans, s2_new);

        return ans;
    }
};