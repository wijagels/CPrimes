// CPrimes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include "Primes.cpp"
using namespace std;

int _tmain(int argc, _TCHAR* argv[]) {
	int a;
	while (true) {
		cout << "Number pls; " << endl;
		cin >> a;
		string str;
		if (Primes::isPrime(a))
			str = "It's prime";
		else
			str = "Not prime";
		cout << str << endl;
	}
	return 0;
}