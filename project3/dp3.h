// dp3.h
// Uddeep Karki
// 2021-09-17
// For CS 311 Fall 2021
// Header for Project 3 functions

// Based off dp3.h  SKELETON by Dr. Glenn G. Chappell created on 2021-09-16


#ifndef FILE_DP3_H_INCLUDED
#define FILE_DP3_H_INCLUDED

#include "llnode.h"    // For LLNode
#include <cstddef>     // For std::size_t
#include <functional>  // For std::function
#include <stdexcept>   // For std::out_of_range
#include <algorithm>   // For std::unique, std::sort
#include <iterator>    // For std::distance

// lookup
// Lookup the value at index in the Linked List
// Pre:
//     head is ptr to nullptr-terminated Linked List, or nullptr for
//      empty Linked List.
// Requirements on Types:
//     ValueType must have a copy ctor and a (non-throwing) dctor.
// NOTE: The above are the requirements for LLNoce<ValueType>; no
// member function of ValueType are actually used here.
// Exections: 
//     throws out_of_range when index >= size of linked list
template <typename ValueType>
ValueType lookup(const LLNode<ValueType> * head,
                 std::size_t index)
{
    // TODO: Polish Comments
    auto p = head;                  // Iterates through list
    std::size_t currentIndex = 0 ;  // current Index in list

    while( p ) {
	if ( currentIndex == index)
	    return p->_data;
	
	p = p->_next;
	++currentIndex;
    }
    // At this point index >= size
    throw std::out_of_range("Out of range");
    
}


// Implementation in source file
void didItThrow(const std::function<void()> & ff,
                bool & threw);

// uniqueCount
// Returns the count of unique items in container
// Pre:
//     RAIter first, and last belong to the same container
// Requirements on Typesr:
//     for std::sort, RAIter must meet requirements of 
//      ValueSwappable and LegacyRandomAccessIterators
//     RAIter must meet requirements of LegacyForwardIterators
//     The dereferenced type or RAIter needs operator<, operator==, and move assignment
//      move constructor
//     Exceptions none
template <typename RAIter>
std::size_t uniqueCount(RAIter first,
                        RAIter last)
{
    std::sort(first, last);
    auto uniqueLast = std::unique(first,last);
    return std::distance(first,uniqueLast);
}


// Implementation in source file
int gcd(int a,
        int b);


#endif  //#ifndef FILE_DP3_H_INCLUDED

