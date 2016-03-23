# Data Structures
Here lies a collection of data structures which I have implemented for learning purposes. Although I strive for efficient and correct implementations, I do not recommend using them in code of any importance. Instead, I refer you to [klib](https://github.com/attractivechaos/klib).

## Methodology
The containers mostly try and mirror C++'s STL, including efficiency guarantees. They are typed as (void \*) to allow for generic usage. This comes with a small performance penalty. This approach has been chosen because it yields the cleanest and most easily understood code.

In some instances, time complexity has been sacrificed in favor of contiguous memory, to make use of caching. On most modern machines this should provide higher performance.

Some other notes:
* The data structures either utilize iterators or indices, but not both
* Underlying memory is never zeroed, even when cleared
* There is no bounds checking.
* Failures of I/O functions such as `malloc` are unhandled (for now)
* `__builtin_expect` is not used for optimization
* No care has been given to packing structs efficiently

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
Files: vec.h, vec.o, common.h
```
vec:
    array: void **
    size: size_t
    count: size_t

Function
    vec_get(pos) -> val
    vec_push()
    vec_pop()
    vec_insert(pos, val)
    vec_erase(pos, val)
    vec_clear()
```

### Stack
Files: stack.h, common.h
```
stack:
    array: void **
    size: size_t
    count: size_t

Function
    stack_top() -> val
    stack_push(val)
    stack_pop()
```
