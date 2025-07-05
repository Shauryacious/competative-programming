# Calculating Interval Intersection

To find the length of the intersection between two intervals \([l1, r1]\) and \([l2, r2]\), use:

\[ ext{intersection} = \max(0, \min(r1, r2) - \max(l1, l2)) \]

### Example Calculation

For intervals \([2, 6]\) and \([4, 8]\):

```
intersection = max(0, min(6, 8) - max(2, 4))
             = max(0, 6 - 4)
             = 2
```

### Code Snippet (C++)

```cpp
int intersection(int l1, int r1, int l2, int r2) {
    return max(0, min(r1, r2) - max(l1, l2));
}
```

### Simple Diagram

```
[ 2-------6 ]
      [ 4-------8 ]
      ^----^ (Intersection: 2)
```

This method runs in **O(1) time complexity** and efficiently computes the intersection length.
