// Author: Conrad Fay
// Problem: The prime factors of 13195 are 5, 7, 13 and 29.
//          What is the largest prime factor of the number 600851475143 ?

#include <iostream>

const long NUM = 600851475143; // num to test
const int SQRT_NUM = 775146; // square root of NUM
bool nonPrimes[SQRT_NUM] = {0};

bool isPrime(int num) {
  if (nonPrimes[num] == 0)
    return true;
  else return false;
}

int findHighestPrimeFactor() {
  for (int i = SQRT_NUM; i > 0; i--) {
    if (NUM % i == 0)
      if (isPrime(i))
        return i;
  }
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
  std::cout << findHighestPrimeFactor() << std::endl;
  
  return (0);
}
