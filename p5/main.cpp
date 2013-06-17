// Author: Conrad Fay
// Problem: 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
//          What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

#include <iostream>

int main() {
  // iterate by 20
  bool divisible;
  for (int i = 20; ;i+=20) {
    divisible = true;
    for (int j = 1; j <= 20; j++) {
      if (i % j != 0) {
        divisible = false; 
        j = 20;
      }
    }
    if (divisible) {
      std::cout << i << std::endl;
      return (1);
    }
  }
  
  return (0);
}
