#include "stdafx.h"
#include "Primes.h"
#include <cmath>


Primes::Primes() {
}

Primes::~Primes() {
}

/*Returns true if parameter a is prime by the definition of a prime number.
Sets failed to the first number that a was divisible by*/
bool Primes::isPrime(unsigned long long int a, unsigned long long int *failed) {
	if (a < 2)
		return false;
	if (a == 3 || a == 2)
		return true;
	for (size_t i = 2; i <= sqrt((double)a); i++) {
		if (a % i == 0) {
			if (*failed != NULL)
				*failed = i;
			return false;
		}
	}
	return true;
}

/*Returns true if the parameter a is divisible by any number at or under the square root of a in the vector parameter, primes.*/
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