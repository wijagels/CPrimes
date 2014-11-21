#pragma once
#include <vector>
#include <thread>
#include <iostream>
#include <string>

class Primes {
public:
	Primes();
	~Primes();
	static bool isPrime(unsigned long long int a, unsigned long long int *failed);
	static bool isPrime(unsigned long long int a, std::vector<unsigned long long int> *primes);
	static void genPrimes(std::vector<unsigned long long int>* primes, unsigned long long int max);
};