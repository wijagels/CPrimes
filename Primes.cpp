#include "Primes.hpp"

void Primes::generate_n_primes(int64_t n) {
  for (int64_t i = 0; i < n; i++) {
    this->find_prime();
  }
}

mpz_class Primes::find_prime(void) {
  for (mpz_class p = mpz_class{primes_.back().first} + 1;; p++) {
    if (is_prime(p)) {
      primes_.push_back({p, p * p});
      return p;
    }
  }
}

bool Primes::is_prime(mpz_class p) {
  for (const auto e : primes_) {
    if (p % e.first == 0) {
      return false;
    }
    if (p > e.second) {
      return true;
    }
  }
  return true;
}
