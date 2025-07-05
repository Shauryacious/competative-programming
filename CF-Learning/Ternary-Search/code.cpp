
// Function to find element in sorted array
// arr: input array
// N: size of array
// K: element to be searche

class Solution {
  public:
    int ternarySearch(int a[], int n, int k) {
        int lo = 0, hi = n-1;
        while(lo <= hi){
            int m1 = lo + (hi - lo) / 3;
            int m2 = hi - (hi - lo) / 3;
            if(k == a[m1]) {
                return m1; // Found at m1
            } else if(k == a[m2]) {
                return m2; // Found at m2
            } else if(k < a[m1]) {
                hi = m1 - 1; // Search in left third
            } else if(k > a[m2]) {
                lo = m2 + 1; // Search in right third
            } else {
                lo = m1 + 1; // Search in middle third
                hi = m2 - 1;
            }
        }

        return -1; // Element not found
    }
};