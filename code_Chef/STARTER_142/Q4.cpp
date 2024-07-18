#include<iostream>
#include<vector>
using namespace std;

int main() {
    int t; 
    cin >> t;
    while(t--){
        int n; 
        cin >> n;
        vector<int> arr(n);
        int bitWiseOrOfAll = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            bitWiseOrOfAll |= arr[i];
        }
        
        int countContiguousOnes = 0;
        while (bitWiseOrOfAll & 1) { 
            countContiguousOnes++;
            bitWiseOrOfAll >>= 1; 
        }

        int count = 0;
        for(int i=0; i<n; i++){
            if(arr[i] >= pow(2, countContiguousOnes)){
                count++;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
