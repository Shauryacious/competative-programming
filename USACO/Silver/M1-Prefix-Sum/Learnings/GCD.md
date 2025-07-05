# GCD Trick for Maximizing GCD After One Replacement

## Key Observation

To find the maximum possible GCD after modifying one element in an array, we leverage the **prefix GCD** and **suffix GCD** concepts.

## Understanding the GCD Calculation

### How GCD Works Recursively

The GCD of multiple numbers can be computed iteratively:

- `gcd(a, b, c) = gcd(gcd(a, b), c)`
- This means that we can break the array into two parts and compute GCD separately.

### Example:

Consider the array:

```
[12, 15, 18, 24]
```

We compute:

- Prefix GCD (`F[i]`): stores GCD from start up to index `i`
- Suffix GCD (`B[i]`): stores GCD from index `i` to the end

#### Step-by-Step Calculation:

1. Compute `F[i]` (Prefix GCD):

   - `F[0] = 12`
   - `F[1] = gcd(12, 15) = 3`
   - `F[2] = gcd(3, 18) = 3`
   - `F[3] = gcd(3, 24) = 3`

   So, `F = [12, 3, 3, 3]`

2. Compute `B[i]` (Suffix GCD):

   - `B[3] = 24`
   - `B[2] = gcd(18, 24) = 6`
   - `B[1] = gcd(15, 6) = 3`
   - `B[0] = gcd(12, 3) = 3`

   So, `B = [3, 3, 6, 24]`

## Finding GCD After Removing One Element

- **Remove `A[0]` (12):** GCD of remaining `[15, 18, 24]` is `B[1] = 3`
- **Remove `A[1]` (15):** GCD of `[12, 18, 24]` is `gcd(F[0], B[2]) = gcd(12, 6) = 6`
- **Remove `A[2]` (18):** GCD of `[12, 15, 24]` is `gcd(F[1], B[3]) = gcd(3, 24) = 3`
- **Remove `A[3]` (24):** GCD of `[12, 15, 18]` is `F[2] = 3`

Thus, the trick is to efficiently compute GCD for any subarray using `F` and `B`, reducing the problem to **O(N)** complexity.

## Summary

- **Prefix GCD (`F[i]`)**: Stores GCD from the beginning up to `i`
- **Suffix GCD (`B[i]`)**: Stores GCD from `i` to the end
- **Removing an element**: GCD is calculated as `gcd(F[i-1], B[i+1])`
- **Efficient Calculation**: Reduces the need to recompute GCD for each possible removal, making it optimal.

This trick is useful for problems that require modifying one element to maximize GCD.
