# Understanding `parseValue()`

## 1. How do we call `parseValue()`?

Remember our function:

```cpp
bool BitcoinExchange::parseValue(const std::string &str, double &value) const
```

It has two parameters:

- `str` → what we want to validate/convert
- `value` → where we want to put the converted result

So inside `processInputFile()`:

```cpp
double amount;

if (!parseValue(value, amount))
{
    std::cout << "Error: invalid value." << std::endl;
    continue;
}
```

For example, suppose the input line is:

```
2011-09-14 | 390.57
```

After parsing:

```cpp
date = "2011-09-14";
value = "390.57";
```

Then:

```cpp
double amount;
if (!parseValue(value, amount))
```

is basically asking:

> "Hey `parseValue`, take this string `"390.57"`, check if it's valid, and if it is, put the actual numeric value into `amount`."

After the function returns:

```
value   = "390.57"       ← string
amount  = 390.57         ← double
```

That's the whole idea.

## 2. Why `double &value`?

This is where the `&` matters.

If we wrote:

```cpp
bool parseValue(const std::string &str, double value)
```

then `value` would be passed **by value**.

Imagine:

```cpp
double amount = 0;
parseValue("390.57", amount);
```

Inside the function:

```cpp
bool parseValue(const std::string &str, double value)
{
    value = 390.57;
}
```

The function would modify a **copy** of `amount`. So after the function:

```
amount = 0
```

The `390.57` would be lost.

### With `double &value`

When we write:

```cpp
double &value
```

we're saying:

> Don't give me a copy. Give me a reference to the original variable.

So:

```cpp
double amount = 0;
parseValue("390.57", amount);
```

Inside the function:

```cpp
value = 390.57;
```

`value` is actually referring to `amount`.

So:

```
Before:
amount
  ↓
  0

parseValue()
  ↓
value refers to amount
  ↓
value = 390.57

After:
amount
  ↓
  390.57
```

## 3. Why return `bool` AND modify `double &value`?

This is the really useful part.

We're returning **two** pieces of information:

- **Return value** (`true` / `false`) answers: *Was the input valid?*
- **Reference parameter** (`double &value`) gives us: *What was the converted number?*

So:

```cpp
double amount;
if (parseValue("390.57", amount))
{
    std::cout << amount << std::endl;
}
```

gives:

```
390.57
```

But:

```cpp
double amount;
if (!parseValue("hello", amount))
{
    std::cout << "Invalid value" << std::endl;
}
```

gives:

```
Invalid value
```

This is basically a way of returning two things from a function:

```
             ┌── bool ───────────────→ success/failure
parseValue ──┤
             └── double & ───────────→ converted result
```

C++ doesn't allow a normal function to directly return `bool + double` as two separate return values, so a reference parameter is one common solution.

## 4. Why not just return the `double`?

We could theoretically do:

```cpp
double parseValue(const std::string &str);
```

But then how would we tell the caller that the input was invalid?

- We could use something like `-1` to mean failure, but that's ugly because `-1` itself is a possible value we might want to reject.
- Or throw exceptions.
- Or create a custom structure.

For this exercise, `bool + reference` is simple and perfectly appropriate.

## 5. What does the `const` on the string mean?

We have:

```cpp
const std::string &str
```

This means:

> Give me the original string without copying it, but I promise not to modify it.

So if:

```cpp
std::string value = "390.57";
```

we call:

```cpp
parseValue(value, amount);
```

the function doesn't create another copy of `"390.57"`.

And because it's `const`:

```cpp
str = "hello";  // not allowed
```

Good.

## 6. What does the final `const` mean?

This:

```cpp
bool parseValue(const std::string &str, double &value) const
//              ^^^^^                                  ^^^^^
//   don't modify the input string      don't modify the BitcoinExchange object
```

has two different `const`s:

- `const std::string &str` → don't modify the input string
- `... const` (at the end) → don't modify the `BitcoinExchange` object

That second one is because `parseValue()` doesn't need to modify `_database` or anything else in the object.



# ---------------------------------------------------------------------------

# Understanding the `Node` Struct (Recursive Pairing)

Our struct is:

```cpp
struct Node
{
    int value;
    std::vector<Node> losers;

    Node(int value) : value(value), losers()
    {
    }
};
```

Think of every `Node` as a little box:

```
┌─────────────────────┐
│ value               │
│                     │
│ losers              │
│   ├── Node          │
│   ├── Node          │
│   └── Node          │
└─────────────────────┘
```

## First line

```cpp
large.losers.push_back(small);
```

Suppose we're processing:

```
3 5
```

We start with:

```
small.value = 3
large.value = 5
```

So:

```
small
┌─────────────┐
│ value = 3   │
│ losers = [] │
└─────────────┘

large
┌─────────────┐
│ value = 5   │
│ losers = [] │
└─────────────┘
```

Then:

```cpp
large.losers.push_back(small);
```

means:

> Take the entire `small` Node and put a copy of it inside `large.losers`.

Now:

```
large
┌─────────────────────┐
│ value = 5           │
│                     │
│ losers:             │
│   └── Node          │
│       value = 3     │
│       losers = []   │
└─────────────────────┘
```

So nothing happens to `large.value`. It remains:

```cpp
large.value == 5
```

We're simply putting the `small` Node inside its `losers` vector.

## Then the second line

```cpp
winners.push_back(large);
```

This takes that whole `large` Node and puts it into the `winners` vector.

So after:

```cpp
large.losers.push_back(small);
winners.push_back(large);
```

we have:

```
winners
  │
  └── Node
      value = 5
      losers
        │
        └── Node
            value = 3
            losers = []
```

So the relationship is now:

```
winners
   │
   ▼
  [5]
   │
   ▼
  [3]
```

Or simply:

```
5
└── 3
```

## Now do the next pair

For:

```
9 7
```

`7` becomes `small` and `9` becomes `large`.

After:

```cpp
large.losers.push_back(small);
winners.push_back(large);
```

we get:

```
winners
├── Node(5)
│   └── Node(3)
│
└── Node(9)
    └── Node(7)
```

Then the next two:

```
4 1
```

becomes:

```
Node(4)
└── Node(1)
```

And:

```
8 2
```

becomes:

```
Node(8)
└── Node(2)
```

So the complete `winners` vector is:

```
winners
│
├── [Node]
│    value = 5
│    losers
│      └── [Node]
│           value = 3
│
├── [Node]
│    value = 9
│    losers
│      └── [Node]
│           value = 7
│
├── [Node]
│    value = 4
│    losers
│      └── [Node]
│           value = 1
│
└── [Node]
     value = 8
     losers
       └── [Node]
            value = 2
```

Or visually:

```
5 ── 3
9 ── 7
4 ── 1
8 ── 2
```

where the arrow means: **this Node's loser vector contains that Node.**

## And THIS is why the structure is powerful

Later, when `5` itself loses to `9`, we can do:

```cpp
large.losers.push_back(small);
```

where `large = 9` and `small = 5`.

But `small` isn't just:

```
5
```

anymore. It's already:

```
5
└── 3
```

So when we put it inside `9`, we get:

```
9
├── 7
└── 5
    └── 3
```

**The entire Node gets carried along with its history.**