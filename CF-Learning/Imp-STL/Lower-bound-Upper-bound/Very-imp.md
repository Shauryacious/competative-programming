### **Lower Bound**

- **If present**: Points to the first occurrence of the element.
- **If absent**: Points to the first element **just greater than** the given value.

### **Upper Bound**

- **Always** (whether present or absent): Points to the first element **just greater than** the given value.

### **Key Difference**

- **Lower Bound** can return the same element if it exists, while **Upper Bound** will always skip to the next greater element.
