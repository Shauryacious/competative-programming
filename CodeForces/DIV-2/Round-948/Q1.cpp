#include<iostream>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n;
        cin>>n;

        string a;
        cin>>a;

        if(n <= 2){
            if(a == "11" || a == "1"){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
            continue;
        }


        if(a[0] == '1' && a[n-1] == '1'){
            cout<<"YES"<<endl;
        }
        else if(a[0] == '1' && a[1] == '1'){
            cout<<"YES"<<endl;
        }
        else if(a[n-1] == '1' && a[n-2] == '1'){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}