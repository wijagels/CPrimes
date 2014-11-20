// CPrimes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include "Primes.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[]) {
	int a;
	bool more = true;
	while (more) {
		cout << "Number pls; " << endl;
		cin >> a;
		string str;
		bool prime;
		double dT = 0;
		clock_t t;
		t = clock();
		prime = Primes::isPrime(a);
		t = clock() - t;
		if (prime)
			str = "It's prime";
		else
			str = "Not prime";
		cout << str << endl;
		dT = ((float)t) / CLOCKS_PER_SEC;
		string str2 = "That took " + std::to_string(dT) + " seconds";
		cout << str2 << endl;
	}
	return 0;
}