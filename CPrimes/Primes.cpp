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
			if (*failed != NULL)
				*failed = i;
			return false;
		}
	}
	return true;
}

//Simple, yet efficient.
bool Primes::isPrime(unsigned long long int a, std::vector<unsigned long long int>* primes) {
	if (a < 2)	//2 is the first prime
		return false;
	unsigned long long int p;
	for (p = 2; p < primes->size() - 1; p++)
		if (p > sqrt(a))
			return true;
		else if (a % p == 0)
			return false;
	return true;
}

void Primes::genPrimes(std::vector<unsigned long long int>* primes, unsigned long long int max) {
	for (unsigned long long int a = 2; a <= max; a++) {
		if (Primes::isPrime(a, primes))
			primes->push_back(a);
	}
}