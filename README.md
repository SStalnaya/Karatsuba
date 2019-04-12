# Karatsuba

An implementation of the Karatsuba multiplication algorithm in C++.

## Performance

Calculating 3^(2^24) by repeated squaring:

```c++
mp::cpp_int x = 3;
for(unsigned int n = 0; n != 24; ++n) {
  x = karatsuba(x,x);
}
  ```
  
  takes 12 minutes and 15 seconds on my machine, and 16 minutes and 11 seconds with the default algorithm.
