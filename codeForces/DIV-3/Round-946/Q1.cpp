#include<iostream>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int x, y; cin>>x>>y;
        int s = 0;
        int d;
        bool odd = false;
        if(y%2==0){ //even
            d = y/2;
        }
        else{
            odd = true;
            d = y/2 + 1;
        }
        s+=d;

        if(odd){
                x -= s*7;
                x -= 4;
                if(x>=15){
                    if(x%15 == 0){ //
                        s += x/15;
                    }
                    else{
                        s += x/15 + 1;
                    }
                }
                else{
                    s+=1;
                }
            cout<<s<<endl;
            continue;
        }
        else{
                x -= s*7;
                if(x>=15){
                    if(x%15 == 0){ //
                        s += x/15;
                    }
                    else{
                        s += x/15 + 1;
                    }
                }
                else{
                    s+=1;
                }

            cout<<s<<endl;
            continue;
        }

        }
    }
