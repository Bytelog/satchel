# Data Structures
[![Build Status](https://travis-ci.org/dallbee/satchel.svg?branch=master)](https://travis-ci.org/dallbee/satchel)

Here lies a collection of data structures which I have implemented for learning purposes. Although I strive for efficient and correct implementations, I do not recommend using them in code of any importance. Instead, I refer you to [klib](https://github.com/attractivechaos/klib).

## Methodology
The containers mostly try and mirror C++'s STL, including efficiency guarantees. They are typed as (void \*) to allow for generic usage. This comes with a small performance penalty.

Some other notes:
* I will be adding namespacing, once I've settled on a prefix
* The data structures either utilize iterators or indices, but not both
* Underlying memory is never zeroed, even when cleared
* There is no bounds checking (caller is responsible)
* Functions with allocation failures always return false
* No compiler builtins are utilized

### Design Goals
1. Overhead shall be kept to an absolute minimum
2. Code must be obvious
3. Optimize for typical hardware rather than theoretical performance

## Building
Satchel is meant to be a grab-bag of data structures. Just add the .h files you want to use to your project and you're good to go.

## API
**TO BE REPLACED WITH DOCS FROM READTHEDOCS.ORG**
Quick reference documentation on each data structure. Each function has an implicit reference to it's own structure which has been omitted. For example, vec\_clear() should really be vec\_clear(vec \*v).

Furthormore, the \_init() and \_free() functions for each data type have been omitted from this reference.

### Vector
Files: vec.h, common.h
```
vec:
    data: void **
    count: size_t
```
Prototype | Time Complexity | Space Complexity
--- | :---: | :---:
`vec_get(pos) -> val` | O(1) | O(1)
`vec_count() -> val` | O(1) | O(1)
`vec_push() -> bool` | O(1) | O(1)
`vec_pop()` | O(1) | O(1)
`vec_insert(pos, val) -> bool` | O(n) | O(1)
`vec_erase(pos, val)` | O(n) | O(1)
`vec_clear()` | O(1) | O(1)

### Stack
Files: stack.h, vec.h, common.h
```
stack:
    data: void **
    count: size_t
```
Prototype | Time Complexity | Space Complexity
--- | :---: | :---:
`stack_top() -> val` | O(1) | O(1)
`stack_count() -> val` | O(1) | O(1)
`stack_push(val) -> bool` | O(1) | O(1)
`stack_pop()` | O(1) | O(1)

### Queue
Files: queue.h, common.h
```
queue:
    data: void **
```
Prototype | Time Complexity | Space Complexity
--- | :---: | :---:
`queue_front() -> val` | O(1) | O(1)
`queue_length() -> num` | O(1) | O(1)
`queue_push(val) -> bool` | O(1) | O(1)
`queue_pop(val)` | O(1) | O(1)

### List
Files: list.h, common.h
```
list:
    item: list_node *
list_node:
    data: void *
    next: list_node *
list_it:
    item: list_node *
```
Prototype | Time Complexity | Space Complexity
--- | :---: | :---:
`list_front(&it)` | O(1) | O(1)
`list_get(&it)` | O(1) | O(1)
`list_next(&it)` | O(1) | O(1)
`list_next_wrap(&it)` | O(1) | O(1)
`list_init(&it) -> bool` | O(1) | O(1)
`list_insert_after(&it, val) -> bool` | O(1) | O(1)
`list_erase_after(&it)` | O(1) | O(1)
`list_push_front(val) -> bool` | O(1) | O(1)
`list_pop_front()` | O(1) | O(1)
`list_free()` | O(n) | O(1)



