// ssarray.h
// Uddeep Karki
// Created: 2021-09-13
// Updated: 2021-09-14
//
// For CS 311 Fall 2021 Project 2
// Header for template class SSArray
// Template class holding array of client specified type.
// There is no associated source file.

#ifndef FILE_SSARRAY_H_INCLUDED
#define FILE_SSARRAY_H_INCLUDED

#include <cstddef> // For std::size_t
#include <algorithm> // For std::fill, std::equal, std::lexicographical_compare
#include <iterator> // For std::begin, std::end
//*********************************************************************
// template class SSArray - template class definition
//*********************************************************************

// template class SSArray
// A "Somewhat Smart Array Class"
// template class holding dynamic array of client specified type.
// Invariants:
//     0 <= _size
//     _arrayptr points to memory allocated with new[]: owner *this
// Requirements on Types:
//    ValueType must have operator ==
//    ValueType must have operator <
//    ValueType must have default constructor
//    ValueType must have copy assignment

template <typename ValueType>
class SSArray {

// ***** SSArray: Types *****
public:

    using size_type = std::size_t; // Unsigned type for size of array, indices
    using value_type = ValueType; // Type of item in this container


// ***** SSArray: Ctors, dctor, op= *****
public:

    // Default Ctor
    // creates a SSArray of size 8
SSArray()
    :_size(8),
     _arrayptr(new value_type[_size])
    {}

    // ***** Big Five - defined explicityly ***** //

    // Dctor
    ~SSArray()
    {
	delete [] _arrayptr;
    }

    // Copy Ctor
    // Pre:
    //     A valid SSArray object
    SSArray(const SSArray & other)
	:_size(other.size()),
	 _arrayptr(new value_type[_size])
	
    {

	std::copy(std::cbegin(other), std::cend(other), begin());
    }

    // Move Ctor
    // Pre:
    //     A valid SSArray object
    SSArray (SSArray && other) noexcept
	:_size(0),
	 _arrayptr(nullptr)
    {
	std::swap(_size, other._size);
        std::swap(_arrayptr, other._arrayptr);
    }

    // Copy Assignement
    // Pre:
    //     A valid SSArray object
    SSArray & operator=(const SSArray & rhs)
    {
	SSArray old(rhs);
	std::swap(_size, old._size);
	std::swap(_arrayptr, old._arrayptr);
	return *this;
    }

    
    // Move Assignement
    // Pre:
    //     A valid SSArray object
    SSArray & operator=(SSArray && rhs) noexcept
    {
	std::swap(_size, rhs._size);
	std::swap(_arrayptr, rhs._arrayptr);
	return *this;
    }
    

    // ***** Parameter Ctors *****//
    
    // 1-parameter Ctor
    // Ctor from size
    // not an implicity type conversion
    // Pre:
    //     size >= 0
    explicit SSArray( size_type size)
	:_size(size),
	_arrayptr(new value_type[_size])
    {}

    // 2- parameter Ctor
    // 1st parameter size is number of items in array
    // 2nd parameter value provides the entry values
    // Creates SSArray of size size with every entry with value value
    // Pre:
    //     size >= 0
    SSArray(size_type size, const value_type &value)
	:_size(size),
	 _arrayptr(new value_type[_size])
    {
	std::fill(begin(), end() , value);
    }

// ***** SSArray: General public members *****
public:

    // Bracket operators-[]
    // Returns a reference to the index item
    // Pre:
    //     0 <= index < _size
    value_type & operator[] (size_type index)
    {
	return _arrayptr[index];
    }
    const value_type & operator[] (size_type index) const
    {
	return _arrayptr[index];
    }


    // size: no parameters
    // Returns number of elements in SSArray
    size_type size() const
    {
	return _size; // TODO: Or .size() ?
    }

    // begin: no parameters
    // Returns the address of the item 0 in the array
    value_type* begin()
    {
	return _arrayptr;
    }
    const value_type* begin() const
    {
	return _arrayptr;
    }

    // end: no parameters
    // Returns the address 1 past the last element in SSArray
    value_type* end()
    {
	return begin() + size();
    }
    const value_type* end() const
    {
	return begin() + size();
    }

    
// ***** SSArray: Data members *****
private:
    size_type _size;
    value_type * _arrayptr;
  

};

// ***** Global Functions*****//

// Global operator overloads: operators ==, !=, <, >=, >, <= //

// operator==
// Returns true if every element of each SSArray are equal
// Pre: operator == must be defined for value_type
template <typename ValueType>
bool operator == (const SSArray<ValueType>& lhs, const SSArray<ValueType> & rhs)
{
    return std::equal(std::cbegin(lhs), std::cend(lhs), std::cbegin(rhs), std::cend(rhs));
}

// operator!=
// Returns true if the two SSArrays differ in any way
// Pre: operator == must be defined for ValueType
template <typename ValueType>
bool operator!= (const SSArray<ValueType> & lhs, const SSArray <ValueType> & rhs)
{
    return !(lhs == rhs);
}

// Comparison operators <, >=, >, <=
// Based off of the page https://en.cppreference.com/w/cpp/language/operators
// 

// operator <
// returns true, if for all i, lhs[i] < rhs[i]
// Pre: operator < defined for ValueType
template <typename ValueType>
bool operator<( const SSArray<ValueType> & lhs, const SSArray<ValueType> & rhs)
{
    return std::lexicographical_compare(std::cbegin(lhs), std::cend(lhs),
					std::cbegin(rhs), std::cend(rhs));
}

// operator >
// returns true if for all i , lhs[i] > rhs[i]
// Pre: operator < defined for ValueType
template <typename ValueType>
bool operator>( const SSArray<ValueType> & lhs, const SSArray<ValueType> & rhs)
{
    return rhs < lhs;
}

// operator <=
// returns true if for all i, lhs[i] <= rhs [i]
// Pre: operator < defined for ValueType
template <typename ValueType>
bool operator<=( const SSArray<ValueType> & lhs, const SSArray<ValueType> & rhs)
{
    return !(lhs > rhs);
}

// operator >=
// returns true if for all i , lhs[i] >= rhs[i]
// Pre: operator < defined for ValueType
template <typename ValueType>
bool operator>=( const SSArray<ValueType> & lhs, const SSArray<ValueType> & rhs)
{
    return !(lhs < rhs);
}


#endif //#ifndefFILE_SSARRAY_H_INCLUDED
