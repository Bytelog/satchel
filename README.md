# Data Structures
Here lies a collection of data structures which I have implemented for learning purposes. Although I strive for efficient and correct implementations, I do not recommend using them in code of any importance. Some details of implementation:

* The APIs mostly try and mirror C++'s STL, including efficiency guarantees
* Each implementation supports only one type (usually int)
* The data structures either utilize iterators or indices, but not both
* Underlying memory is never zeroed, even when cleared
* There is no bounds checking. This may change, but I'm inclined to keep the implementation minimalistic
* Code is reused where possible. For example: stack depends on vec.
* Failures of I/O functions such as `malloc` are unhandled
* `__builtin\_expect` is not used for optimization
* No care has been given to packing structs efficiently

## Building
To generate the object files, just type `make`. The results will be stored in the `target/` directory. The only thing you should need is libc and a compiler supporting C99. If you want to use something other than clang, you may need to edit the first line of the makefile.

## API

### Vector
```
vec:
    array: int *
    size: size_t
    count: size_t

Function             Complexity      Allocation
vec_get(pos)            O(1)            None
vec_init()              O(1)            None
vec_push()              O(1)            size
vec_pop()               O(1)            None
vec_insert(pos, val)    O(n)            size
vec_erase(pos, val)     O(n)            None
vec_clear()             O(1)            None
vec_free()              O(1)            None
```
