#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> countOrderedPairs(int T, vector<pair<int, vector<int>>> testCases) {
    vector<int> results;

    for (int t = 0; t < T; ++t) {
        int N = testCases[t].first;
        vector<int> array = testCases[t].second;
        int max_val = INT_MIN;
        int count = 0;

        for (int i = 0; i < N; ++i) {
            if (array[i] <= max_val) {
                count++;
            }
            max_val = max(max_val, array[i]);
        }

        int result = count * (count + 1) / 2;
        results.push_back(result);
    }

    return results;
}

int main() {
    int T;
    cin >> T;
    vector<pair<int, vector<int>>> testCases;

    for (int t = 0; t < T; ++t) {
        int N;
        cin >> N;
        vector<int> array(N);
        for (int i = 0; i < N; ++i) {
            cin >> array[i];
        }
        testCases.push_back(make_pair(N, array));
    }

    vector<int> results = countOrderedPairs(T, testCases);

    for (int res : results) {
        cout << res << endl;
    }

    return 0;
}
