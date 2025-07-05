#define ff first
#define ss second
class Solution {
  public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root) {
        vector<int> ans;
        map<int, int> mp;
        queue<pair<Node*, int>> q; //{Node, line}
        q.push({root, 0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            Node* u = p.ff;
            int line = p.ss;
            if(mp.find(line) == mp.end()){
                mp[line] = u->data;
            }
            if(u->left) q.push({u->left, line-1});
            if(u->right) q.push({u->right, line+1});
        }
        
        for(auto x : mp){
            ans.push_back(x.ss);
        }
        return ans;
    }
};