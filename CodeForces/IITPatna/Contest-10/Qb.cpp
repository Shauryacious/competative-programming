#include <iostream>
#include <vector>
using namespace std;


vector<int> continuedFraction(int a, int b) {
    vector<int> result;
    while (b != 0) {
        result.push_back(a / b);  
        int remainder = a % b;    
        a = b;
        b = remainder;
    }
    return result;
}

void printContinuedFraction(int a, int b) {
    vector<int> cf = continuedFraction(a, b);

    cout << cf.size()-1 << " "; 

    for (int term : cf) {
        cout << term << " ";
    }
    cout << endl;
}

int main() {
    int t ;
    cin>>t;
    while(t--){
        int a, b;
    cin >> a >> b;
    printContinuedFraction(a, b);
    }

    return 0;
}