#include<iostream>
using namespace std;
void print_hash(){
    cout<<'#'<<'#'<<endl<<'.'<<'.';
}
void print_dot(){
    cout<<'.'<<'.'<<endl<<'#'<<'#';
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;
        cin>>n;
        char arr_hash[2][2] = {{'#','#'},{'#','#'}};
        char arr_dot[2][2] = {{'.','.'},{'.','.'}};
        int count = n*n;
        for(int i=0; i<2n; i++){
            for(int j=0; j<2n; j++){
                if(i%2==0){
                    if(j%2==0){
                        print_hash();
                    }else{
                        print_dot();
                    }
                }
                else{
                    if(j%2==0){
                        print_dot();
                    }else{
                        print_hash();
                    }
                }
                cout<<endl;
            }
        }
    }
}