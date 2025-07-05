#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, q;
        cin >> n >> k >> q;

        vector<long long int> a(k + 1);
        a[0] = 0;
        for (int i = 1; i <= k; i++) {
            cin >> a[i];
        }

        vector<long long int> b(k + 1);
        b[0] = 0;
        for (int i = 1; i <= k; i++) {
            cin >> b[i];
        }
        ///

        vector<double> s(k + 1);
        s[0] = 0;
        for (int i = 0; i < k; i++) {
            double dist = a[i + 1] - a[i];
            double time = b[i + 1] - b[i];

            double speed = dist / time;
            s[i + 1] = speed;
        }
        // cout<<endl<<"SPEED : ";
        // for(int i=0; i<=k; i++){
        //     cout<<s[i]<<" ";
        // }
        // cout<<endl;

        while (q--) {
            int d;
            cin >> d;
            long long int idx = 0;
            for(int i=0 ;i<=k; i++){
                if(a[i]>d){
                    idx = i-1;
                    break;
                }
            }

            if (idx >= 0) {
                long long int tt = b[idx];
                double dist = d - a[idx];
                double speed = s[idx+1];
                // cout<<(dist / speed)<<endl;
                tt += static_cast<long long int>(dist / speed);
                cout<<tt<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}