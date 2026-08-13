# STL Containers — `vector`, `list`, `deque`

These three matter a lot for CPP08. They all store multiple elements, but they organize those elements very differently, and that difference is the whole point.

## `std::vector`

Think: **dynamic array**.

```
┌────┬────┬────┬────┬────┐
│ 10 │ 20 │ 30 │ 40 │ 50 │
└────┴────┴────┴────┴────┘
 ↑                       ↑
begin                   end
```

Elements are stored **contiguously** in memory. That's why `numbers[3]` is so fast — the computer can calculate exactly where element 3 lives.

**Good**
- ✅ Very fast random access: `v[1000]` is O(1)
- ✅ `push_back()` is usually very fast
- ✅ Contiguous memory is cache-friendly
- ✅ Works extremely well with algorithms like `std::sort()`

**Bad**
- ❌ Inserting/removing in the middle is expensive — everything after the insertion point has to shift:
  ```
  10 20 30 40 50
  Insert 25 →
  10 20 25 30 40 50
  ```
- ❌ Growing can trigger reallocation — if the vector runs out of capacity, it allocates a bigger block and moves everything over

## `std::list`

Fundamentally different. Think of it as a **chain of nodes**:

```
┌──────┐      ┌──────┐      ┌──────┐
│  10  │ ───► │  20  │ ───► │  30  │
└──────┘      └──────┘      └──────┘
    ▲             ▲             ▲
   node          node          node
```

Each element lives in its own node, and each node knows where the next/previous node is. Elements don't need to be next to each other in memory.

**Good**
- ✅ Inserting/removing when you already have the right iterator is very cheap — you're just relinking pointers, not shifting elements:
  ```
  10 → 20 → 30
  Insert 25 between 20 and 30 →
  10 → 20 → 25 → 30
  ```
- ✅ Adding/removing at the ends is efficient

**Bad**
- ❌ No random access — `list[500]` isn't a thing; you have to walk the chain from `begin`:
  ```
  begin
   ↓
  10 → 20 → 30 → ... → 500
  ```
- ❌ More memory per element (each node carries link bookkeeping)
- ❌ Worse cache locality than a vector

## `std::deque`

The interesting middle ground. **deque = double-ended queue**.

```
        push_front
             ↓
       ┌─────────────┐
       │             │
       ▼             ▼
    [10][20][30][40][50]
                       ▲
                       │
                   push_back
```

Designed to efficiently add/remove from **both ends**:

```cpp
d.push_front(5);
d.push_back(60);
```

Both are efficient. Unlike a vector, a deque doesn't require all elements to live in one contiguous block — but unlike a list, it still gives efficient random access.

**Good**
- ✅ Fast `push_front()`
- ✅ Fast `push_back()`
- ✅ Random access: `d[500]` is efficient
- ✅ Doesn't require one giant contiguous allocation like a vector

**Bad**
- ❌ Generally less cache-friendly than a vector
- ❌ More complicated internal structure
- ❌ Inserting in the middle still isn't what you'd pick a deque for

## The big picture

Don't memorize a pile of random facts — think about what problem you're solving.

| Container | Think of it as | Best when... |
|---|---|---|
| `vector` | Dynamic array | You mostly access elements / add at the end |
| `list` | Chain of nodes | You frequently insert/remove with iterators |
| `deque` | Double-ended sequence | You need efficient ops at both ends + random access |

This is also why the STL has multiple containers instead of one "best" one:

- Need to constantly access element `#5000`? → `vector`
- Need to insert/remove frequently at a position you already have? → `list`
- Need `push_front()`, `push_back()`, and random access? → `deque`

**The whole philosophy:** choose the data structure according to the operations your program performs most often. That mindset only gets more important as CPP08 goes on.