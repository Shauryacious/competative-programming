### Bitset in C++

In C++, `bitset` is a class in the Standard Template Library (STL) that represents a fixed-size sequence of bits (either 0 or 1). Each bit can be accessed, modified, and queried, much like elements in an array or vector. It is useful for scenarios where you need to manipulate bits directly.

The size of the `bitset` is determined at compile-time and cannot be changed dynamically. You can perform various operations on the bits, such as setting, flipping, and testing specific bits.

To use `bitset`, you need to include the `<bitset>` header.

### Basic Syntax:

```cpp
#include <bitset>
#include <iostream>
using namespace std;

int main() {
    bitset<8> b; // Create a bitset of size 8 (default initialized to 0)
    cout << b << endl;
    return 0;
}
```

In C++, `bitset` requires its size to be a **constant expression** (known at compile time). You cannot pass a runtime variable like `int n` as the size of a `bitset`. The size of a `bitset` is determined at compile time, so `bitset<n>` is invalid if `n` is a variable.

### Example:

```cpp
#include <iostream>
#include <bitset>
using namespace std;

int main() {
    int n = 8;
    bitset<n> b;  // This will cause a compilation error because n is not a constant
    return 0;
}
```

### Solution:

If you want to determine the size of your bitset dynamically at runtime, you can use other containers like `std::vector<bool>`. However, `std::bitset` is for fixed-size, compile-time constant arrays of bits.

For dynamic bit manipulation, you can do something like this using `vector<bool>`:

### Using `vector<bool>`:

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n = 8;  // Size at runtime
    vector<bool> b(n, false);  // Initialize with false (0)

    // Set some bits
    b[0] = 1;
    b[3] = 1;

    cout << "Bit 0: " << b[0] << endl;
    cout << "Bit 3: " << b[3] << endl;

    return 0;
}
```

### Output:

```
Bit 0: 1
Bit 3: 1
```

This approach gives you the flexibility of runtime sizing, but if you must use `bitset`, the size must be a compile-time constant.

---

### Alternative: Using `constexpr` for Compile-time Size

You can pass the size as a `constexpr` (compile-time constant), like this:

```cpp
#include <iostream>
#include <bitset>
using namespace std;

constexpr int n = 8;  // Compile-time constant

int main() {
    bitset<n> b("10101010");  // This works because n is a constant expression
    cout << "Bitset: " << b << endl;
    return 0;
}
```

### Output:

```
Bitset: 10101010
```

In summary:

- `bitset` size must be a compile-time constant.
- Use `vector<bool>` if you need dynamic sizing at runtime.
- You can use `constexpr` if you want to work with compile-time constants.

### Key Operations on `bitset`

Below, I'll explain various methods and operations with examples and the output for each.

---

#### 1. `operator[]` (Accessing individual bits)

You can access individual bits in a `bitset` just like you would with an array or vector using the `operator[]`.

**Code:**

```cpp
#include <bitset>
#include <iostream>
using namespace std;

int main() {
    bitset<8> b("10101010"); // Initialize bitset with binary string
    cout << "b[0] = " << b[0] << endl; // Accessing the 0th bit
    cout << "b[3] = " << b[3] << endl; // Accessing the 3rd bit
    return 0;
}
```

**Output:**

```
b[0] = 0
b[3] = 1
```

---

#### 2. `count()` (Returns the number of set bits)

The `count()` function returns the number of bits that are set to 1.

**Code:**

```cpp
#include <bitset>
#include <iostream>
using namespace std;

int main() {
    bitset<8> b("10101100"); // Initialize bitset
    cout << "Number of set bits: " << b.count() << endl;
    return 0;
}
```

**Output:**

```
Number of set bits: 4
```

---

#### 3. `size()` (Returns the size of the bitset)

The `size()` function returns the total number of bits in the bitset (i.e., the fixed size that was specified).

**Code:**

```cpp
#include <bitset>
#include <iostream>
using namespace std;

int main() {
    bitset<8> b; // Create bitset of size 8
    cout << "Size of bitset: " << b.size() << endl;
    return 0;
}
```

**Output:**

```
Size of bitset: 8
```

---

#### 4. `test()` (Checks if a specific bit is set)

The `test()` function checks whether the bit at the specified position is set (i.e., 1). If the bit is set, it returns `true`; otherwise, it returns `false`.

**Code:**

```cpp
#include <bitset>
#include <iostream>
using namespace std;

int main() {
    bitset<8> b("10011001"); // Initialize bitset
    cout << "Is bit at position 0 set? " << b.test(0) << endl;
    cout << "Is bit at position 4 set? " << b.test(4) << endl;
    return 0;
}
```

**Output:**

```
Is bit at position 0 set? 1
Is bit at position 4 set? 0
```

---

#### 5. `any()` (Checks if any bit is set)

The `any()` function checks if any of the bits in the bitset are set to 1. It returns `true` if at least one bit is set, otherwise `false`.

**Code:**

```cpp
#include <bitset>
#include <iostream>
using namespace std;

int main() {
    bitset<8> b("00000000"); // All bits are 0
    cout << "Any bit set? " << b.any() << endl;

    bitset<8> c("00010000"); // One bit is set
    cout << "Any bit set? " << c.any() << endl;
    return 0;
}
```

**Output:**

```
Any bit set? 0
Any bit set? 1
```

---

#### 6. `none()` (Checks if no bits are set)

The `none()` function returns `true` if none of the bits are set to 1, otherwise `false`.

**Code:**

```cpp
#include <bitset>
#include <iostream>
using namespace std;

int main() {
    bitset<8> b("00000000"); // All bits are 0
    cout << "No bits set? " << b.none() << endl;

    bitset<8> c("10000000"); // One bit is set
    cout << "No bits set? " << c.none() << endl;
    return 0;
}
```

**Output:**

```
No bits set? 1
No bits set? 0
```

---

#### 7. `all()` (Checks if all bits are set)

The `all()` function returns `true` if all the bits are set to 1, otherwise `false`.

**Code:**

```cpp
#include <bitset>
#include <iostream>
using namespace std;

int main() {
    bitset<8> b("11111111"); // All bits are 1
    cout << "All bits set? " << b.all() << endl;

    bitset<8> c("11101111"); // One bit is 0
    cout << "All bits set? " << c.all() << endl;
    return 0;
}
```

**Output:**

```
All bits set? 1
All bits set? 0
```

---

### Bit Manipulation Operations

---

#### 8. `set()`

- `b.set()` sets all the bits to 1.
- `b.set(position)` sets the bit at the specified position to 1.
- `b.set(position, value)` sets the bit at the specified position to the value (0 or 1).

**Code:**

```cpp
#include <bitset>
#include <iostream>
using namespace std;

int main() {
    bitset<8> b;
    cout << "Initial bitset: " << b << endl;

    b.set(); // Set all bits to 1
    cout << "After b.set(): " << b << endl;

    b.set(3); // Set the 3rd bit to 1
    cout << "After b.set(3): " << b << endl;

    b.set(3, 0); // Set the 3rd bit to 0
    cout << "After b.set(3, 0): " << b << endl;
    return 0;
}
```

**Output:**

```
Initial bitset: 00000000
After b.set(): 11111111
After b.set(3): 11111111
After b.set(3, 0): 11110111
```

---

#### 9. `reset()` or `unset()`

- `b.reset()` (or `unset()`) sets all the bits to 0.
- `b.reset(position)` resets (sets to 0) the bit at the specified position.

**Code:**

```cpp
#include <bitset>
#include <iostream>
using namespace std;

int main() {
    bitset<8> b("11110000"); // Initialize bitset
    cout << "Initial bitset: " << b << endl;

    b.reset(); // Reset all bits
    cout << "After b.reset(): " << b << endl;

    bitset<8> c("11111111");
    c.reset(4); // Reset 4th bit
    cout << "After c.reset(4): " << c << endl;
    return 0;
}
```

**Output:**

```
Initial bitset: 11110000
After b.reset(): 00000000
After c.reset(4): 11101111
```

---

#### 10. `flip()`

- `b.flip()` flips all the bits (0 becomes 1, and 1 becomes 0).
- `b.flip(position)` flips the bit at the specified position.

**Code:**

```cpp
#include <bitset>
#include <iostream>
using namespace std;

int main() {
    bitset<8> b("10101010"); // Initialize bitset
    cout << "Initial bitset: " << b << endl;

    b.flip(); // Flip all bits
    cout << "After b.flip(): " << b << endl;

    b.flip(3); // Flip the 3rd bit
    cout << "After b.flip(3): " << b << endl;
    return 0;
}
```

**Output:**

```
Initial bitset: 10101010
After b.flip(): 01010101
After b.flip(3): 01011101
```

---

This is an in-depth explanation and demonstration of how `bitset` works in C++. Each example provides a different functionality with accompanying output.
