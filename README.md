# c-basic
This Repository features C source code i wrote to learn c. Currently the most advanced program included is an
unfinished implementation of the huffman algorithm.

Some programs make use of outdated and unsafe functions such as `gets()` or `scanf()`, which **should never be used**.
That is the case, because we were teached to use some of these in programming classes. Ideally, all uses
of these unsafe functions should include a comment explaining why this is bad and also include and implemented
alternative, but that may not always be the case.

All code in this Repository was written on and for a Linux x86_64 system. It might not work on other systems.

### Note:

`scanf()` is not inherently unsafe, but must be handled very careful and isn't recommended by most, so i have
chosen to classify it as unsafe. If you know exactly what you are doing using `scanf()` seems to be acceptable.
I consider the use of `scanf()` to be bad practice.
