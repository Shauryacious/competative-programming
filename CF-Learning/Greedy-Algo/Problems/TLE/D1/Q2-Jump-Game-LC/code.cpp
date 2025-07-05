class Solution {
public:
    bool canJump(vector<int>& a) {
        int n = a.size();
        int maxidx = -1;

        for(int i=0; i<n; i++){
            maxidx = max(maxidx, i + a[i]);
            if(a[i] == 0 && maxidx == i){
                if(i == n-1) return true;
                return false;
            }
        }
        return true;
    }
};

// https://leetcode.com/problems/jump-game/
// https://www.youtube.com/watch?v=Tuh9xEazfVg