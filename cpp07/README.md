# Why Template Implementations Are Usually in Header Files

## Normal Functions

Consider the following example:

### `Math.hpp`

```cpp
void hello();
```

### `Math.cpp`

```cpp
#include "Math.hpp"

void hello()
{
    std::cout << "Hello\n";
}
```

### `main.cpp`

```cpp
#include "Math.hpp"

int main()
{
    hello();
}
```

### What Happens?

When compiling `main.cpp`, the compiler only needs to know:

- Function name
- Return type
- Parameter types

It does **not** need the function body.

The compiler simply generates a call to `hello()`.

Later, during the linking stage, the linker finds the implementation inside `Math.cpp` and connects everything together.

So for a normal function:

```
Compiler
    ↓
Generates a call to hello()

Linker
    ↓
Finds hello() implementation
```

The implementation can safely stay inside a `.cpp` file.

---

# Templates Are Different

Consider this template:

### `Whatever.hpp`

```cpp
template <typename T>
void swap(T& a, T& b);
```

### `Whatever.cpp`

```cpp
template <typename T>
void swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}
```

### `main.cpp`

```cpp
#include "Whatever.hpp"

int main()
{
    int a = 10;
    int b = 20;

    swap(a, b);
}
```

When compiling `main.cpp`, the compiler encounters:

```cpp
swap(a, b);
```

It immediately deduces:

```cpp
T = int
```

Now the compiler must generate:

```cpp
void swap(int& a, int& b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
```

But there is a problem.

The compiler has only seen the declaration:

```cpp
template <typename T>
void swap(T&, T&);
```

It has **not** seen the implementation.

Without the implementation, it has no idea how to generate the function body.

---

# The Important Difference

A normal function is already compiled somewhere else.

A template is **not** a function.

A template is only a **blueprint** (or recipe) for generating functions.

The actual function is created only when the compiler knows the concrete type.

For example:

```cpp
swap(a, b);
```

becomes

```cpp
swap<int>(a, b);
```

and the compiler generates:

```cpp
void swap(int&, int&);
```

This process is called **template instantiation**.

---

# Why Can't the Linker Help?

The linker can only connect already compiled functions.

It **cannot generate new functions**.

For a template, the compiler must first instantiate the template.

If the compiler cannot see the template implementation, no function is generated.

Since no function exists, the linker has nothing to link.

---

# Why Templates Are Usually Implemented in Header Files

Putting the implementation inside the header ensures that every `.cpp` file including the header can see the complete template definition.

This allows the compiler to instantiate the template whenever it is used with a new type.

Without the implementation being visible during compilation, template instantiation is impossible.

---

# Summary

| Normal Function | Template |
|-----------------|----------|
| Already exists as compiled code | Only a blueprint |
| Compiler only needs the declaration | Compiler needs the complete definition |
| Linker finds the implementation | Compiler generates the implementation |
| Implementation can be in `.cpp` | Implementation is usually placed in `.hpp` |

---

# Evaluator Answer

> A normal function already exists as compiled code. The compiler only needs its declaration to generate a call to it, and the linker later finds the implementation.
>
> A template is not a real function but a blueprint for generating functions. When the compiler encounters a template with a specific type, it must instantiate it by generating a real function. To do that, it needs the complete template definition, not just its declaration. That's why template implementations are usually placed in header files.



# ----------------------------------------------------------------------------------------------------

# Understanding `new` and Initialization in C++

Before understanding the `Array` exercise, it's important to understand how `new` initializes different types.

---

## Case 1: `new int`

```cpp
int *a = new int;
```

### What happens?

- Memory for one `int` is allocated.
- The `int` is **default-initialized**.
- Since `int` is a fundamental (primitive) type, **default initialization does not initialize it**.

So:

```cpp
std::cout << *a << std::endl;
```

prints an **indeterminate value** (often called "garbage").

---

## Case 2: `new int()`

```cpp
int *a = new int();
```

Notice the parentheses.

This performs **value initialization**.

Result:

```cpp
*a == 0
```

The integer is initialized to zero.

---

## Case 3: `new std::string`

```cpp
std::string *s = new std::string;
```

Even without parentheses, this works perfectly.

Why?

Because `std::string` is a **class**.

When allocating an object of a class, C++ automatically calls its **default constructor**.

Result:

```text
""
```

An empty string is created.

---

# Why Does the Subject Mention `new int()`?

The subject suggests trying:

```cpp
int *a = new int();
std::cout << *a << std::endl;
```

The purpose of this hint is to make you realize that **initialization depends on the type**.

For a class:

```cpp
new Student;
```

automatically calls:

```cpp
Student();
```

For a built-in type like `int`, there is **no constructor**, so the initialization rules are different.

---

# Applying This to `Array<T>`

Suppose we write:

```cpp
Array<std::string> words(3);
```

Inside the constructor we'll allocate memory like this:

```cpp
_array = new T[3];
```

Since:

```cpp
T = std::string
```

the compiler generates:

```cpp
new std::string[3];
```

Each element is default-constructed.

Result:

```text
""
""
""
```

---

Now suppose we write:

```cpp
Array<Student> students(3);
```

This becomes:

```cpp
new Student[3];
```

Each `Student` object has its default constructor called.

---

Finally:

```cpp
Array<int> numbers(3);
```

becomes:

```cpp
new int[3];
```

Since `int` is a fundamental type, there is **no constructor** to call.

Each element is simply **default-initialized**, which means the values are **indeterminate** in C++98.

---

# What the Subject Is Really Trying to Say

The subject states:

> Creates an array of `n` elements initialized by default.

The important idea is **not** to manually initialize every element.

Simply allocate the array:

```cpp
_array = new T[n];
```

and let C++ initialize each element according to the rules of its type.

- If `T` is `std::string` → the default constructor is called.
- If `T` is `Student` → the default constructor is called.
- If `T` is `int` → the elements remain default-initialized (indeterminate in C++98).

You should **not** do something like:

```cpp
for (unsigned int i = 0; i < n; i++)
    _array[i] = T();
```

The language already knows how to initialize each element correctly based on `T`.

---

# Key Takeaway

When using:

```cpp
new T[n];
```

C++ automatically applies the correct initialization rules for the type `T`.

- **Class types** → the default constructor is called for every element.
- **Fundamental types** (`int`, `char`, `double`, etc.) → no constructor exists, so they are default-initialized according to the language rules.

As the programmer, you only need to allocate the array. The language takes care of initializing each element appropriately for its type.

