// CPrimes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CPrimes.h"
#include <ctime>
#include "Primes.h"
#include <sstream>
#include <climits>
#include <windows.h>
using namespace std;
void genPrimes(std::vector<unsigned long long int>* primes, unsigned long long int max);

int _tmain(int argc, _TCHAR* argv[]) {
	cout << "Maximum number: " << ULLONG_MAX << endl;
	unsigned long long int a;
	std::vector<unsigned long long int>* primes;
	primes = new std::vector<unsigned long long int>();
	string line;
	std::thread primeGen(Primes::genPrimes, primes, sqrt(ULLONG_MAX));
	while (true) {
		cout << "Number pls:" << endl;
		while (std::getline(std::cin, line)) {
			if (line == "exit") {
				goto exit;
			}
			std::stringstream ss(line);
			if (ss >> a) {
				if (ss.eof() && !a < pow(primes->back(),2)) {   // make sure we aren't over the maximum verifiable prime
					break;
				}
			}
			std::cout.imbue(std::locale(""));//puts commas into numbers for readability's sake
			std::cout << "Bad input or too large!  Type exit to quit, or try again.  Current prime is:\n"
				<< primes->back() << std::endl;
		}
		string str;
		bool prime;
		double dT = 0;
		clock_t t;
		t = clock();
		prime = Primes::isPrime(a, primes);
		t = clock() - t;
		dT = ((float)t) / CLOCKS_PER_SEC;
		if (prime)
			str = "It's prime";
		else {
			str = "Not prime";
		}
		cout << str << endl;
		string str2 = "That took " + std::to_string(dT) + " seconds";
		cout << str2 << endl;
	}
exit:
	std::cout.imbue(std::locale(""));
	std::cout << "Generated " << primes->size() << " primes, shutting down in 5 seconds..." << endl;
	Sleep(5000);
	return 0;
}