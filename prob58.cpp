// Project Euler Problem: 58
// Goal: find the side length where the ratio of spiral numbers to spiral primes is less than 10%
// Author: Cooper Bell

#include <iostream>
#include <vector>
#include "sieve_of_atkin.h"
using namespace std;

int LR (int k) {
  return (k - 2)*(k - 1) + 1;
}

int LL (int k) {
  return (k - 1)*(k - 1) + 1;
}

int TL (int k) {
  return k*(k - 1) + 1;
}

int TR (int k) {
  return (k + 1)*(k - 1) + 1;
}

int main()
{
  int limit = 100000;
  vector<int> primes;
  primes = sieve_of_atkin(limit);

  int spiral_prime, spiral_num;
  spiral_prime = spiral_num = 0;

}
