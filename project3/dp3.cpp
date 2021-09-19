// dp3.cpp
// Uddeep Karki
// 2021-09-17
// Based off dp3.cpp  SKELETON by Dr. Glenn G. Chappell on 2021-09-16
//
// For CS 311 Fall 2021
// Source for Project 3 functions

#include "dp3.h"       // For Project 3 prototypes & templates

#include <functional>
using std::function;
#include <cassert>     // For assert

// didItThrow
// Takes a reference to a function and reference to a bool value
//  Calls the function and if function throws an exception then
//  sets bool to true and rethrows expection
// Pre:
//     ff is a function
//     threw is bool
// All exceptions are caught and rethrown
void didItThrow(const function<void()> & ff,
                bool & threw)
{
    // TODO: Write proper comments
    threw = false;
    try {
	ff();
    }
    catch (...) {
	threw = true;
	throw;
    }
}

// gcd
// takes two integers
// recursively computes gcd or integers and returns it
// Pre:
//     a, b are int such that
//     a, b >= 0 && !(a == 0 && b == 0)
// No requirements on types
// No exceptions thrown
int gcd(int a,
        int b)
{
    assert((a >= 0 && b >= 0) && !(a == 0 && b == 0));
    // Base Case:
    if (a == 0)
	return b;

    // Recursive Case:
    return gcd(b % a, a);
}

