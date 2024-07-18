#include<iostream>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int x, y, z;
        cin>>x>>y>>z;
        if(x<y && y>z) cout<<"PEAK"<<endl;
        else if(x<y && y<z) cout<<"STAIR"<<endl;
        else cout<<"NONE"<<endl;
    }
}