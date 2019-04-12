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
  
<<<<<<< HEAD
  takes 40 seconds on my machine, and 16 minutes and 11 seconds with the default algorithm.
=======
  takes 45 seconds on my machine, and 16 minutes and 11 seconds with the default algorithm.
>>>>>>> 9e9e61b425bb2586f763e15d16f8b7781c8c5574
