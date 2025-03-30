//Function to return a list containing the bottom view of the given tree.
#define ff first
#define ss second
class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        map<int, int> mp;
        queue<pair<Node*, int>> q; //{Node, line}
        q.push({root, 0});
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            Node* u = p.ff;
            int line = p.ss;
            mp[line] = u->data;
            if(u->left) q.push({u->left, line-1});
            if(u->right) q.push({u->right, line+1});
        }
        
        for(auto x : mp){
            ans.push_back(x.ss);
        }
        return ans;
    }
};