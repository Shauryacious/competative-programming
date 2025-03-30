typedef long long ll;
#define ss second
#define ff first
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        ll ans = 0;
        if(!root) return (int)ans;

        queue<pair<TreeNode*, ll>> q;
        // {node, idx}
        q.push({root, 0});
        while(!q.empty()){
            ll sz = q.size();
            ll min_idx = (q.front()).ss;
            ll mn = -1, mx = -1; 
            //mn is min idx at that level
            //mx is max idx at that level
            // Width = max_idx - min_idx + 1 at a perticular level
            // max width of tree => max width among all levels

            for(ll i=0; i<sz; i++){
                auto p = q.front();
                q.pop();

                TreeNode* u = p.ff;
                ll idx = p.ss - min_idx; // to prevent overflow

                if(i==0) mn = p.ss; //first node will be at the min idx
                if(i==(sz-1)) mx = p.ss; //last node on that level will be at the max idx
                ans = max(ans, (mx-mn+1)); //maximum width

                if(u->left) q.push({u->left, (2*idx+1)});
                if(u->right) q.push({u->right, (2*idx+2)});
            }
        }

        return (int)ans;
    }
};