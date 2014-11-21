#include "stdafx.h"
#include "Primes.h"
#include <cmath>


Primes::Primes() {
}

Primes::~Primes() {
}

// Determines if parameter is a prime by the definition of a prime number.
bool Primes::isPrime(unsigned long long int a, unsigned long long int *failed) {
	if (a < 2)
		return false;
	if (a == 3 || a == 2)
		return true;
	for (size_t i = 2; i <= sqrt((double)a); i++) {
		/*string tmp = "Checking " + std::to_string(a) + " mod " + std::to_string(i);
		cout << tmp << endl; //for debugging */
		if (a % i == 0) {
			*failed = i;
			return false;
		}
	}
	return true;
}