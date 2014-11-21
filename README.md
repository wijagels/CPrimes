CPrimes
=======

A C++ version of wijagels/PrimeServer

A focus on speed, and a hope to run concurrently.
The goal is to create a process that fires up, and generates primes until a specified upper bound.
Using those primes that have already been generated, it can verify numbers as prime with 100% certainty by checking the divisibility by every prime before up to (and including) its square root.

Later down the road, it will be used for a web service that provides a user-interface to the validator.
Just for fun, I'll also want to cram all the primes into a database and have a way to query that database from the website.
Big goals, but it've got to get good at C++ somehow.
