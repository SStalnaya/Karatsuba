#include <boost/multiprecision/cpp_int.hpp>

boost::multiprecision::cpp_int karatsuba(boost::multiprecision::cpp_int a, boost::multiprecision::cpp_int b) {
  /*
    An implementation of the Karatsuba algorithm.
    Calculates a*b asymptotically faster than the standard algorithm.
    https://en.wikipedia.org/wiki/Karatsuba_algorithm
    This is only actually faster than the standard algorithm when a,b are both very large.
  */
  if(a == 0 || b == 0) {
    return 0;
  }
  if(a < 0) {
    if(b < 0) {
      return karatsuba(-a,-b);
    }
    return -karatsuba(-a, b);
  }
  if(b < 0) {
    return -karatsuba(a,-b);
  }
  const unsigned int m = std::min(msb(a), msb(b)) / 2;
  // find m in order to split a,b approximately down the middle
  if(m < 1605) { // magic constant is only approximately correct
    return a * b;
  }

  // write a=(a0+a1*2^m) and b=(b0+b1*2^m)
  const boost::multiprecision::cpp_int a1 = a >> m;
  const boost::multiprecision::cpp_int a0 = a - (a1 << m);
  const boost::multiprecision::cpp_int b1 = b >> m;
  const boost::multiprecision::cpp_int b0 = b - (b1 << m);

  const boost::multiprecision::cpp_int z0 = karatsuba(a0, b0);
  const boost::multiprecision::cpp_int z2 = karatsuba(a1, b1);
  const boost::multiprecision::cpp_int z1 = karatsuba(a1 + a0, b1 + b0) - z2 - z0;
  return (z2 << (2 * m)) + (z1 << m) + z0;
}
