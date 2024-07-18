#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    long long int t; cin>>t;
    while(t--){
        long long int n, m; cin>>n>>m;

        vector<long long int> bat(n);
        for(long long int i=0; i<n; i++){
            cin>>bat[i];
        }
        vector<long long int> ball(m);
        for(long long int i=0; i<m; i++){
            cin>>ball[i];
        }
        if(n<4 || m<4){
            cout<<-1<<endl;
            continue;
        }
        if(n+m < 11){
            cout<<-1<<endl;
            continue;
        }
        sort(bat.begin(), bat.end());
        sort(ball.begin(), ball.end());
        reverse(bat.begin(), bat.end());
        reverse(ball.begin(), ball.end());
        
        long long int maxx = 0;
        for(long long int i=0; i<=3; i++){
            maxx += bat[i];
        }
        for(long long int i=0; i<=3; i++){
            maxx += ball[i];
        }
        long long int count = 1;
        long long int i = 4;
        long long int j = 4;
        while(count<=3){
            if(i>=n) break;
            if(j>=m) break;
            if(bat[i]>ball[j]){
                maxx += bat[i];
                i++;
            }
            else{
                maxx += ball[j];
                j++;
            }
            count++;
        }
        if(i==n){
            while(count<=3){
                maxx += ball[j];
                j++;
                count++;
            }
        }
        if(j==m){
            while(count<=3){
                maxx += bat[i];
                i++;
                count++;
            }
        }
        cout<<maxx<<endl;
    }  
}
