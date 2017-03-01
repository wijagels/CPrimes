#include <gmpxx.h>
#include <initializer_list>
#include <list>
#include <utility>

class Primes {
 public:
  Primes() : Primes{2} {}
  Primes(std::initializer_list<mpz_class> seed) {
    for (auto e : seed) {
      primes_.push_back({e, e * e});
    }
  }
  void generate_n_primes(int64_t);
  mpz_class find_prime(void);
  bool is_prime(mpz_class);

  /* Cache the square so we only compute it once */
  std::list<std::pair<mpz_class, mpz_class>> primes_;
};
