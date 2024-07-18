#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    long long maximumPoints(std::vector<int>& enemyEnergies, int currentEnergy) {
        int n = enemyEnergies.size();
        std::sort(enemyEnergies.begin(), enemyEnergies.end());

        long long points = 0;
        long long totalPoints = 0;
        int l = 0, r = n - 1;
        while (l <= r) {
            if (currentEnergy >= enemyEnergies[l]) {
                points += currentEnergy / enemyEnergies[l];
                totalPoints += currentEnergy / enemyEnergies[l];
                currentEnergy -= (currentEnergy / enemyEnergies[l]) * enemyEnergies[l];
            } else if (points >= 1) {
                currentEnergy += enemyEnergies[r];
                points--;
                r--;
            } else {
                break;
            }
        }
        return totalPoints;
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
