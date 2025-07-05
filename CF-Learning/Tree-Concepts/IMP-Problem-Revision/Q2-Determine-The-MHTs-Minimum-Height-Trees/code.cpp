class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto e : edges){
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> deg(n, -1);
        for(int i=0; i<n; i++){
            deg[i] = adj[i].size();
        }

        queue<int> q; //queue of leafs
        for(int i=0; i<n; i++){
            if(deg[i] <= 1){
                q.push(i); //inset the leaf nodes
            }
        }

        int rem = n;
        while(rem > 2){ //based on the fact that a tree have 1 or 2 centers based on the parity of diameter
            int sz = q.size();
            rem -= sz; //take all the leaf nodes and remove them
            while(sz--){
                int u = q.front();
                q.pop();
                for(auto v : adj[u]){
                    deg[v]--;
                    if(deg[v] == 1){ //if it becomes leaf push it into the queue
                        q.push(v);
                    }
                }
            }
        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};