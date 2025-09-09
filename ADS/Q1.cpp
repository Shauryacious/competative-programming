
#include<iostream>
using namespace std;

int main(){
    int prev = 0, curr = 0;
    auto f = [&](int n) -> void {
        while(n){
            curr++;
            n /= 3;
        }
    };

    for(int i=1; i <= 100; i++){
        int val1 = log(i) / log(3);
        int ans1 = ceil(val1) + 1;

        f(i);
        int ans2 = curr - prev ;
        prev = curr;

        cout<<ans1 <<"     |     "<<ans2<<endl;
    }
}


