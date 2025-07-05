#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, d; cin >> n >> d;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int k = *max_element(a.begin(), a.end());

    int mxcnt = 0, cnt = 0;
    for(int i=0; i<n; i++){
        if(a[i] == k){
            cnt++;
        }
        else{
            cnt = 0;
        }
        mxcnt = max(mxcnt, cnt);
    }

    cout << mxcnt + d << endl;
}