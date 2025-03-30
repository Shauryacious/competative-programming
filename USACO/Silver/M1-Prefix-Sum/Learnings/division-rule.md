# Division is Not Distributive Under Modulo

## Understanding Modulo Operations

Modulo arithmetic follows certain rules:

- **Addition:** \((a + b) \mod M = ((a \mod M) + (b \mod M)) \mod M\)
- **Subtraction:** \((a - b) \mod M = ((a \mod M) - (b \mod M) + M) \mod M\)
- **Multiplication:** \((a \times b) \mod M = ((a \mod M) \times (b \mod M)) \mod M\)

However, **division is not directly distributive** under modulo.

## Why Division is Problematic

Unlike addition, subtraction, and multiplication, division requires an **inverse**. Mathematically:

\[ \frac{a}{b} \mod M \neq \left(\frac{a \mod M}{b \mod M}\right) \mod M \]

The reason is that division under modulo requires the **multiplicative inverse** of \(b\), which exists only if \(b\) and \(M\) are coprime (i.e., \(\gcd(b, M) = 1\)).

## When Can We Use Division?

If \(M\) is a **prime number**, we can use **Fermat’s Little Theorem**:

\[ b^{-1} \mod M = b^{M-2} \mod M \]

This helps in computing division as:

\[ \frac{a}{b} \mod M = a \times b^{M-2} \mod M \]

Using **modular exponentiation**, this operation can be done efficiently in \(O(\log M)\).

## Prefix Sum, Difference, and Product

- **Prefix Sum:** Efficient for range sum queries:
  \[ S[i] = (S[i-1] + a[i]) \mod M \]
- **Prefix Difference:** Works similarly using subtraction under modulo.
- **Prefix Product:** Also works efficiently:
  \[ P[i] = (P[i-1] \times a[i]) \mod M \]

However, **prefix division does not work** directly unless we compute modular inverses for each prefix product.

## Conclusion

While prefix sums, differences, and products are valid under modulo, division is not directly distributive. To handle division, we require modular inverses, which exist only when the modulus is prime or when the divisor is coprime to the modulus.
