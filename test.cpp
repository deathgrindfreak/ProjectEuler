#include <iostream>
#include <vector>
#include "sieve_of_atkin.h"
using namespace std;

int main()
{
  vector<int> primes;
  primes = sieve_of_atkin(100);

  for (vector<int>::size_type i = 0; i != primes.size(); ++i) {
    cout << primes[i] << endl;
  }
  return 0;
}
