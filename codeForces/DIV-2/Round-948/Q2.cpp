#include<iostream>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        

iint x;
cin>>x;
vector<int>ans (32);
fo(i,0,31) {
int a=x&(1<<i);
ans[i]=((a>0)?1:0);
}
int i=0;
while(i<32) {
int j=i+1;
if(ans[i]==1 and j<31 and ans[j]==1) {
while(j<32 and ans[j]==1) {
j++;
}
ans [i]=-1;
for(int k=i+1;k<j; k++)ans [k]=0;
ans[j]=1;
// i=j;
}
i=j;
}
cout<<32<<endl;
fo (k, 0, 32) cout<<ans [k]<<" ";
cout<<endl;
}
}
        // int x;
        // cin>>x;

        // int pre_diff = 0;
        // int post_diff = 0;
        // int n = 1;
        // for(int i=0; i<30-1; i++){
        //     pre_diff = abs(pow(2, i) - x);
        //     post_diff = abs(pow(2, i+1) - x);
        //     if(pow(2, i+1) > x){
        //         if(pre_diff < post_diff){
        //             n = i+1;
        //             break;
        //         }
        //         else{
        //             n = i+2;
        //             break;
        //         }
        //     }
        // }

        // cout<<n<<endl;