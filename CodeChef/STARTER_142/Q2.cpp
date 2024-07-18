#include<iostream>
using namespace std;

bool isPowerOfTwo(int x) {
    if (x <= 0) return false;
    return (x & (x - 1)) == 0;
}

int nextPowerOfTwo(int x) {
    if (x <= 0) return 1;
    x--;
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;
    // x |= x >> 32;
    return x + 1;
}

int main() {
    int t; 
    cin >> t;
    while (t--) {
        int x; 
        cin >> x;
        if (isPowerOfTwo(x)) {
            cout << 0 << endl;
        } else {
            int next = nextPowerOfTwo(x);
            cout << next << endl;
        }
    }
    return 0;
}
