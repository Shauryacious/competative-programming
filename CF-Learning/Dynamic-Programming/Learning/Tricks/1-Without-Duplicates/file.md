# Subsets Without Duplicates Algorithm

> **Prerequisite:** Sort the array first to ensure duplicates are adjacent.

## Actions

1. **Include** the current element and recurse to the next index.
2. **Skip duplicates:** advance past all identical elements, then recurse.
3. **Exclude** the current element (move one step) and recurse.

## C++ Implementation

```cpp
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& a) {
        int n = a.size();

        sort(a.begin(), a.end());

        vvii ans;

        auto f = [&](int i, vii& v, auto&& f) -> void {
            if (i == n) {
                ans.pb(v);
                return;
            }

            // Include the current element
            v.pb(a[i]);
            f(i + 1, v, f);
            v.pop_back();

            // Skip duplicates
            while (i + 1 < n && a[i] == a[i + 1]) {
                i++;
            }

            // Exclude the current element
            f(i + 1, v, f);
        };

        vii v;
        f(0, v, f);

        return ans;
    }
};
```
