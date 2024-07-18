#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int i = 0, j=0, start=1;
        int times = k;
        int count = 0;

        while(start > i) {
            bool isAlternating = true;
            while(times--){
                if(colors[j] == colors[j+1]) {
                    isAlternating = false;
                    j++;
                    if(j >= n){
                        j = 0;
                    }
                    start = j;
                    break;
                }
            }
            if(isAlternating){
                count++;
                j++;
            }
            times = k;
        }
    }
};

int main() {
    int t;
    std::cin >> t;
    while (t--) {
        int n, currentEnergy;
        std::cin >> n >> currentEnergy;
        std::vector<int> enemyEnergies(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> enemyEnergies[i];
        }

        Solution solution;
        std::cout << solution.maximumPoints(enemyEnergies, currentEnergy) << std::endl;
    }
    return 0;
}
