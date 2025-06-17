# Ternary Search Cheat-Sheet

## What & Why

- **Purpose**: Find the maximum or minimum of a _unimodal_ function (one peak or one valley).
- **Use-case**: Optimization problems where binary search doesn’t apply directly.

## Time Complexity

- **Ternary Search**: $O(2\log_3 n)$ ≈ $O(\log n)$
- **Binary Search**: $O(1\log_2 n)$

## Core Algorithm (Floating-Point)

```cpp
long double ternary_search(long double l, long double r) {
    for (int i = 0; i < 100; ++i) {
        long double m1 = l + (r - l) / 3;
        long double m2 = r - (r - l) / 3;
        if (f(m1) < f(m2))  // for maximum; reverse for minimum
            l = m1;
        else
            r = m2;
    }
    return f((l + r) / 2);
}
```

## Integer Domain Variant

```cpp
int ternary_search_int(int l, int r) {
    while (r - l > 2) {
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        if (f(m1) < f(m2))
            l = m1;
        else
            r = m2;
    }
    int ans = l;
    for (int i = l + 1; i <= r; ++i)
        if (f(i) > f(ans)) ans = i;
    return ans;
}
```

## Essential Tips

1. **Verify unimodality**: Ensure the function/array has a single peak or valley.
2. **Fixed iterations**: Use a constant number (e.g., 80–120) for floating-point to bound runtime.
3. **Integer vs. float**: Use integer midpoints to avoid precision issues on discrete domains.
4. **Avoid overflow**: Compute midpoints as `l + (r - l) / 3`.
5. **Prepare a template**: Keep both variants in your snippet library for quick use.

## Example

> **Problem**: Find the maximum of $f(x) = -(x-3)^2 + 5$ on $[0, 10]$.

```cpp
long double f(long double x) { return -1*(x-3)*(x-3) + 5; }
// Call:
auto max_value = ternary_search(0.0L, 10.0L);
```

_Ready-to-use, battle-tested, and contest-approved._
