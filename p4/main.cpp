// Author: Conrad Fay
// Problem: A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 99.
//          Find the largest palindrome made from the product of two 3-digit numbers. 

#include <iostream>
#include <string>
#include <sstream>

bool isPalindrome(int num) {
  std::string s;
  std::stringstream out;
  out << num;
  s = out.str();
  for (int i = 0; i < s.length(); i++) {
    if (s[i] != s[s.length() - i - 1])
      return false;
  }
  return true;
}

int main() {
  int num1;
  int num2;

  // loop through pivots
  for (int p = 999; p > 99; p--) {
    num1 = p;
    num2 = p;
    // calculate products from pivot
    //std::cout << "pivot: " << p << std::endl;
    while ((num1 > 99) && (num2 < 1000)) {
      // check if products from pivot are palindromes
      if (isPalindrome(num1 * num2)) {
        std::cout << num1 * num2 << std::endl;
        return (1);
      }
      //std::cout << num1 << " * " << num2 << " = " << num1 * num2 << std::endl;
      num1--;
      if (isPalindrome(num1 * num2)) { 
        std::cout << num1 * num2 << std::endl;
        return (1);
      }
      //std::cout << num1 << " * " << num2 << " = " << num1 * num2 << std::endl;
      num2++;
    }
  }

  return (0);
}
