// Author: Conrad Fay
// Problem: By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
//          What is the 10 001st prime number?

#include <iostream>

const long NUM = 600851475143; // num to test
const int SQRT_NUM = 5000000; // square root of NUM
bool nonPrimes[SQRT_NUM] = {0};

bool isPrime(int num) {
  if (nonPrimes[num] == 0)
    return true;
  else return false;
}

int findnthPrime(int n) {
  int numPrimes = 0;
  int index = 1;

  while (numPrimes < n) {
    index++;
    if (nonPrimes[index] == 0) {
      numPrimes++;
      std::cout << numPrimes << " prime: " << index << std::endl;
    }
  }
  return index;
}

// generate array of booleans, which will be 1 if they are non-primes
void genSievePrimes() {
  for (int p = 2; p < SQRT_NUM; p++) {
    int c = 2;
    int mul = p * c;
    while (mul < SQRT_NUM) {
      nonPrimes[mul] = 1; 
      c++;
      mul = p * c;
    }
  }
}

int main() {
  // generate prime numbers (Sieve of Eratosthenes)
  genSievePrimes();
  // check if factors of number are prime
  std::cout << findnthPrime(10001) << std::endl;
  
  return (0);
}
