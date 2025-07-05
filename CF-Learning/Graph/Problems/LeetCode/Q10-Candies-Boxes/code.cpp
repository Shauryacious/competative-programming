#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define pb push_back


class Solution {
    void print(set<pii, greater<pii>>& q) {
        cout<<"----------"<< endl;
        for(auto& p : q) {
            cout << "{" << p.first << ", " << p.second << "} "<< endl;
        }
    }
public:
    int maxCandies(vii& stat, vii& cnds, vvii& keys, vvii& containedBxs, vii& initBxs) {
        int n = stat.size();
        int ans = 0;
        set<pii, greater<pii>> q; // {status, index}
        for(auto& b : initBxs) {
            ii currstat = stat[b];
            q.insert({currstat, b});
        }
        vii boxfound(n, 0); // to keep track of boxes that have been found
        for(auto& b : initBxs) {
            boxfound[b] = 1; // mark the initial boxes as found
        }

        while(!q.empty()){
            auto [currstat, idx] = *q.begin();
            q.erase(q.find({currstat, idx}));
            if(currstat == 0) break; // if we reach a box with status 0, we can stop
            ans += cnds[idx];
            cnds[idx] = 0; // mark the candies as collected
            // update the status of the box
            for(auto key : keys[idx]) {
                stat[key] = 1;
                if(boxfound[key] && cnds[key]){
                    q.insert({1, key});
                }
            }

            for(auto bxs : containedBxs[idx]){
                if(boxfound[bxs]) continue; // if the box is already found, skip it
                boxfound[bxs] = 1; // mark the box as found
                if(cnds[bxs] == 0) continue; // if there are no candies in the box, skip it
                q.insert({stat[bxs], bxs});
            }

            // print(q); 
        }

        return ans;
    }
};