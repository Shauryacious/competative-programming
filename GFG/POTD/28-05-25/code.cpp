#define ii int
#define vii vector<int>
#define vvii vector<vector<int>>
#define pii pair<int, int>
#define pb push_back

class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& a) {
        int n = a.size(), m = a[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(a[i][j] == 1){
                    for(int i2 = i+1; i2<n; i2++){
                        for(int j2 = j+1; j2<m; j2++){
                            if(a[i2][j] == 1 && a[i][j2] == 1 && a[i2][j2] == 1){
                                return true;
                            }
                        }
                    }
                }
            }   
        }

        return false;
    }
};