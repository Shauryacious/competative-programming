#include<iostream>
#include<string>
using namespace std;

int main() {
	// your code goes here
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        string p; cin>>p;
        string c; cin>>c;
        
        vector<int> v;
        
        for(int i=0; i<n; i++){
            int x;
            if(int(c[i]) - int(p[i]) >= 0){
                x = abs(int(c[i]) - int(p[i]));
            }
            else if(int(c[i]) - int(p[i]) < 0){
                x = 26 - abs(int(c[i]) - int(p[i]));
            }
            // int x = abs(int(c[i]) - int(p[i]));
            // cout<<x<<" ";
            while(1){
                if(x%3 == 0){
                    v.push_back(x/3);
                    break;
                }
                else{
                    x += 26;
                }
            }
        }
        
        for(int i=0; i<n; i++){
            cout<<v[i]<<" ";
        }
        
        cout<<endl;
    }
}
