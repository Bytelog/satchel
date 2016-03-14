# Data Structures
Here lies a collection of data structures which I have implemented for learning purposes. Although I strive for efficient and correct implementations, I do not recommend using them in code of any importance. Some details of implementation:

* The APIs mostly try and mirror C++'s STL, including efficiency guarantees
* Each implementation supports only one type (usually int)
* The data structures either utilize iterators or indices, but not both
* Underlying memory is never zeroed, even when cleared
* There is no bounds checking. This may change, but I'm inclined to keep the implementation minimalistic
* Code is reused where possible. For example: stack depends on vec.
* Failures of I/O functions such as `malloc` are unhandled
* `__builtin_expect` is not used for optimization
* No care has been given to packing structs efficiently

## Building
To generate the object files, just type `make`. The results will be stored in the `target/` directory. The only thing you should need is libc and a compiler supporting C99. If you want to use something other than clang, you will need to edit the first line of the makefile.

## API
Quick reference documentation on each data structure. Each function has an implicit reference to it's own structure which has been omitted. For example, vec\_clear() should really be vec\_clear(vec \*v).

Furthormore, the \_init() and \_free() functions for each data type have been omitted from this reference.

### Vector
Files: vec.h, vec.o, common.h
```
vec:
    array: int *
    size: size_t
    count: size_t

Function
    vec_get(pos) -> int
    vec_push()
    vec_pop()
    vec_insert(pos, val)
    vec_erase(pos, val)
    vec_clear()
```

### Stack
Files: stack.h, stack.o. vec.h, vec.o, common.h
```
stack:
    array: int *
    size: size_t
    count: size_t

Function
    stack_top()
    stack_push(val)
    stack_pop()
```
