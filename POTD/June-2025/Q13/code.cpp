#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define vpii vector<pii>
#define pb push_back
#define MOD 1000000007
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
#define all(x) (x).begin(), (x).end()


class Solution {
public:
    int minimizeMax(vector<int>& a, int p) {
        int n = a.size();
        if(n==0 || p==0) return 0;
        sort(a.begin(), a.end());
        vector<int> v;
        for(int i=0; i<n-1; i++){
            if(a[i] == a[i+1]){
                v.pb(0);
                i++;
            }
        }
        set<int> st(all(a));
        vector<int> b(all(st)); 
        sort(b.begin(), b.end());
        n = b.size();
        for(int i=0; i<n-1; i++){
            v.pb(b[i+1] - b[i]);
        }

        sort(v.begin(), v.end());

        return v[p-1];
    }
};