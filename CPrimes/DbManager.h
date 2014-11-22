#pragma once
//TODO: add functionality to work with MongoDB
class DbManager {
public:
	DbManager();
	~DbManager();
	// Add a new prime into the database, return true if it was added successfully.
	bool addPrime(unsigned long long int prime);
};

