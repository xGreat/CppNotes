/*
 * problem1.h
 *
 *  Created on: Dec 23, 2013
 *      Author: Antony Cherepanov
 */

#ifndef PROBLEM1_H_
#define PROBLEM1_H_

#include "problem.h"

// Problem 1:
//If we list all the natural numbers below 10 that are multiples of 3 or 5,
// we get 3, 5, 6 and 9. The sum of these multiples is 23.
//Find the sum of all the multiples of 3 or 5 below 1000.

class Problem1 : public Problem
{
	// == DATA ==

	// == METHODS ==
private:
	virtual void DoSolve();
};

#endif /* PROBLEM1_H_ */
