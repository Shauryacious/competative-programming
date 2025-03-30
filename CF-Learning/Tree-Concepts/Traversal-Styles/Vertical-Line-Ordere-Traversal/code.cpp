class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp; // {line, {level, node}}
        queue<pair<TreeNode*, pair<int, int>>> q; // FIX: Changed queue to store TreeNode* properly
        q.push({root, {0, 0}}); // {node, {line, level}}
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* u = p.first;
            int line = p.second.first;
            int lvl = p.second.second;
            
            mp[line][lvl].insert(u->val); // FIX: Corrected `value` to `val`
            
            if(u->left) q.push({u->left, {line-1, lvl+1}});
            if(u->right) q.push({u->right, {line+1, lvl+1}});
        }
        
        vector<vector<int>> ans; // FIX: Changed initialization as `ans(n)` was incorrect
        
        for(auto &line : mp){ // FIX: Corrected iteration over `mp`
            vector<int> col;
            for(auto &lvl : line.second){ // FIX: Corrected iteration over `line.second`
                for(auto &value : lvl.second){ // FIX: Corrected iteration over `lvl.second`
                    col.push_back(value);
                }
            }
            ans.push_back(col);
        }
        
        return ans;
    }
};
