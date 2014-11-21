// CPrimes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CPrimes.h"
#include <ctime>
#include "Primes.h"
#include <sstream>
#include <climits>
using namespace std;
void genPrimes(std::vector<unsigned long long int>* primes, unsigned long long int max);

int _tmain(int argc, _TCHAR* argv[]) {
	cout << "Maximum number: " << ULLONG_MAX << endl;
	unsigned long long int a;
	unsigned long long int failed = 0;
	std::vector<unsigned long long int>* primes;
	primes = new std::vector<unsigned long long int>();
	string line;
	Primes::genPrimes(primes, 100000);
	for (unsigned long long int p : *primes) {
		cout << p << endl;
	}
	while (true) {
		cout << "Number pls; " << endl;
		while (std::getline(std::cin, line)) {
			if (line == "exit") {
				return 0;
			}
			std::stringstream ss(line);
			if (ss >> a) {
				if (ss.eof()) {   // Success
					break;
				}
			}
			std::cout << "Error!  Type exit to quit." << std::endl;
		}
		string str;
		bool prime;
		double dT = 0;
		clock_t t;
		t = clock();
		prime = Primes::isPrime(a, &failed);
		t = clock() - t;
		if (prime)
			str = "It's prime";
		else {
			str = "Not prime, divisible by " + std::to_string(failed);
			cout << failed << endl;
		}
		cout << str << endl;
		dT = ((float)t) / CLOCKS_PER_SEC;
		string str2 = "That took " + std::to_string(dT) + " seconds";
		cout << str2 << endl;
	}
	return 0;
}

