#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin >> n >> m;

        vector<int> v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i];
        }

        sort(v.begin(), v.end());
        int j = n-1;

        int max_sum = INT_MIN;

        while(j>=0){
            int sum = 0;
            int i = j;
            int mx = v[j];
            while(i>=0){
                mx = max(mx, v[i]);
                if(sum + v[i] > m){
                    break;
                }
                sum += v[i];
                if(abs(v[i-1] - mx) <= 1){
                    i--;
                }
                else{
                    max_sum = max(max_sum, sum);
                    break;
                }
            }
            j--;
        }
        cout<<max_sum<<endl;
    }
}