/*
 * problem10.cpp
 *
 *  Created on: Jan 5, 2014
 *      Author: Antony Cherepanov
 */

#include <iostream>
#include <vector>

#include "problem10.h"
#include "algorithms/primenumbers.h"

void Problem10::DoSolve()
{
	std::cout << "Problem 10" << std::endl;

	const long int maxPrime = 2000000;

	PrimeNumbers primeNums;
	std::vector<long int> primes = primeNums.GetPrimeNumbers(maxPrime);

	long int sum = 0;
	for ( size_t i = 0; i < primes.size(); ++i )
	{
		sum += primes[i];
	}

	std::cout << "Answer = " << sum << std::endl;
}

