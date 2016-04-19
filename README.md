# Data Structures
Here lies a collection of data structures which I have implemented for learning purposes. Although I strive for efficient and correct implementations, I do not recommend using them in code of any importance. Instead, I refer you to [klib](https://github.com/attractivechaos/klib).

## Methodology
The containers mostly try and mirror C++'s STL, including efficiency guarantees. They are typed as (void \*) to allow for generic usage. This comes with a small performance penalty. This approach has been chosen because it yields the cleanest and most easily understood code.

In some instances, time complexity has been sacrificed in favor of contiguous memory, to make use of caching. On most modern machines this should provide higher performance.

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
To generate the object files, just type `make`. The results will be stored in the `target/` directory. The only thing you should need is libc and a compiler supporting C99. If you want to use something other than clang, you will need to edit the first line of the makefile.

## API
Quick reference documentation on each data structure. Each function has an implicit reference to it's own structure which has been omitted. For example, vec\_clear() should really be vec\_clear(vec \*v).

Furthormore, the \_init() and \_free() functions for each data type have been omitted from this reference.

### Vector
Files: vec.h, vec.c, common.h
```
vec:
    array: void **
    count: size_t
```
Prototype | Time Complexity | Space Complexity
--- | :---: | :---:
`vec_get(pos) -> val` | O(1) | O(1)
`vec_push() -> bool` | O(1) | O(1)
`vec_pop()` | O(1) | O(1)
`vec_insert(pos, val) -> bool` | O(n) | O(1)
`vec_erase(pos, val)` | O(n) | O(1)
`vec_clear()` | O(1) | O(1)

### Stack
Files: stack.h, common.h
```
stack:
    array: void **
    count: size_t
```
Prototype | Time Complexity | Space Complexity
--- | :---: | :---:
`stack_top() -> val` | O(1) | O(1)
`stack_push(val) -> bool` | O(1) | O(1)
`stack_pop()` | O(1) | O(1)

### Queue
Files: queue.h, queue.c, common.h
```
queue:
    array: void **
```
Prototype | Time Complexity | Space Complexity
--- | :---: | :---:
`queue_front() -> val` | O(1) | O(1)
`queue_length() -> num` | O(1) | O(1)
`queue_push(val) -> bool` | O(1) | O(1)
`queue_pop(val)` | O(1) | O(1)


