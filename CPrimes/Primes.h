#pragma once
class Primes {
public:
	Primes();
	~Primes();
	// Determines if parameter is a prime by the definition of a prime number.
	static bool isPrime(unsigned long long int a, unsigned long long int *failed);
};