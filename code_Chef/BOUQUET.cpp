#include<iostream>
#include<vector>
using namespace std;
int main() {
  int t; cin>>t;
  while(t--){
    vector<int> vec_col(3,0);
    vector<vector<int>> v(3, vec_col);
    int max_sum = 0;
    
    for(int row=0; row<3; row++){
      for(int col=0; col<3; col++){
        cin>>v[row][col];
        if(v[row][col] > max_sum) max_sum = v[row][col];
      }
    }


    int sumR1=0, sumR2=0, sumR3=0;
    int sumC1=0, sumC2=0, sumC3=0;

    for(int col=0; col<3; col++){
      sumR1 += v[0][col];
      sumR2 += v[1][col];
      sumR3 += v[2][col];
    }
    vector<int> sumR(3);
    sumR[0] = sumR1;
    sumR[1] = sumR2;
    sumR[2] = sumR3;


    for(int row=0; row<3; row++){
      sumC1 += v[row][0];
      sumC2 += v[row][1];
      sumC3 += v[row][2];
    }
    vector<int> sumC(3);
    sumC[0] = sumC1;
    sumC[1] = sumC2;
    sumC[2] = sumC3;


    for(int i=1; i<=3; i++){
      if((sumR[i]) > max_sum) max_sum = sumR[i];
      if((sumC[i]) > max_sum) max_sum = sumC[i];


      // if(sumR[i]%2 == 0 && (sumR[i]-1) > max_sum) max_sum = sumR[i]-1;
      // else if(sumR[i]%2 != 0 && (sumR[i]) > max_sum) max_sum = sumR[i];
      // if(sumC[i]%2 == 0 && (sumC[i]-1) > max_sum) max_sum = sumC[i]-1;
      // else if(sumC[i]%2 != 0 && (sumC[i]) > max_sum) max_sum = sumC[i];


      // if(sumC[i]%2 == 0 && max_sum < sumC[i]-1) max_sum = sumC[i]-1;
      // else max_sum = sumC[i];
      //if(sumC[i]%2 != 0 && sumC[i] > max_sum) max_sum = sumC[i];
    }
    if(max_sum == 0) {cout<<max_sum; return 0;}
    max_sum%2==0 ? cout<<max_sum-1 : cout<<max_sum;
  }
}