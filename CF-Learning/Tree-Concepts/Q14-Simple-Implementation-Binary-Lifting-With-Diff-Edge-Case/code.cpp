// https://leetcode.com/problems/kth-ancestor-of-a-tree-node/

typedef long long ll;

class TreeAncestor {
public:
    ll LOG = 20;
    vector<vector<ll>> anc;
    
    TreeAncestor(int n, vector<int>& parent) {
        anc.resize(n, vector<ll>(LOG, -1));
        
        // Base case:
        for(ll u = 0; u < n; u++){
            anc[u][0] = parent[u];
        }
        
        for(ll k = 1; k < LOG; k++){
            for(ll u = 0; u < n; u++){
                ll mid_anc = anc[u][k-1];
                //! IMPORTANT :-
                //! if mid_anc is -1, then anc[u][k] will also be -1 
                if(mid_anc != -1) { 
                    ll kth_anc = anc[mid_anc][k-1];
                    anc[u][k] = kth_anc;
                }
                else{
                    anc[u][k] = -1;
                }
            }
        }
    }
    
    int getKthAncestor(int u, int k) {
        for(ll i = 0; i < LOG; i++){
            if(k & (1 << i)){
                u = anc[u][i];
                if(u == -1) return -1;
            }
        }
        return u;
    }
};


/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */