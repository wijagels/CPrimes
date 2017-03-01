#include <gmpxx.h>
#include <iostream>
#include "Primes.hpp"

int main() {
  Primes p{};
  p.generate_n_primes(1e2);
}
