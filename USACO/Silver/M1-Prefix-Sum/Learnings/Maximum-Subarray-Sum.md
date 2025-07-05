# Longest Contiguous Sum Explained

The **longest contiguous sum** in an array is the maximum sum of any contiguous subarray. This can be efficiently computed using **prefix sums**.

## Key Concept

The maximum sum of any contiguous subarray ending at index `i` is given by:

\[ \text{max sum} = \text{current prefix sum} - \text{smallest prefix sum so far} \]

where:

- The **prefix sum** at index `i` is the sum of all elements from the start of the array to `i`.
- The **smallest prefix sum so far** helps identify the minimum accumulated sum before `i`, ensuring we get the maximum possible difference.

## Example

Consider the array:

```
arr = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
```

1. Compute the prefix sum array:

```
Prefix sums: [0, -2, -1, -4, 0, -1, 1, 2, -3, 1]
```

2. Track the smallest prefix sum so far:

```
Smallest prefix sum so far: [0, -2, -2, -4, -4, -4, -4, -4, -4, -4]
```

3. Compute the maximum difference:

```
Max contiguous sum = max(prefix[i] - minsofar)
                   = 6 (subarray [4, -1, 2, 1])
```

## Explanation

- We use a **prefix sum array** to store cumulative sums.
- We keep track of the **smallest prefix sum** encountered so far.
- At each step, we compute the possible maximum contiguous sum.
- This approach runs in **O(n) time complexity** and efficiently finds the solution.

## Conclusion

Using **prefix sums**, the longest contiguous sum is simply:
\[ \text{current prefix sum} - \text{smallest prefix sum so far} \]
This method ensures an optimal and efficient solution for finding the maximum sum subarray.
