// 1239. Maximum Length of a Concatenated String with Unique Characters

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int maxLength(vector<string>& arr) {
  int size = arr.size();
  int count = 0;
  for(int i=0; i<size; i++){
    for(int j=0; j<arr[i].length(); j++){
      
    }
  }
}


int main() {
  vector<string> arr(3);
  for(int i=0; i<3; i++){
    cin>>arr[i];
  }

  maxLength(arr);
}