#include<iostream>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        long long int a, b, k; cin>>a>>b>>k;
        if(k==1){
            cout<<b-a<<endl;
            continue;
        }
        long long int count = 0;
        long long int c=b, d, c_prev;
        while(1){
            if((c/k)<a){
                count += c-a;
                break;
            }
            count++;
            c_prev = c;
            c /= k;
            d = c*k;
            count += c_prev-d;
        }
        cout<<count<<endl;
    }
}