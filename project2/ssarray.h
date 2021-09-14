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
#include <algorithm> // For std::fill
#include <cassert> // For assert
#include <iterator> // For std::begin
//*********************************************************************
// template class SSArray - template class definition
//*********************************************************************

// template class SSArray
// template class holding dynamic array of client specified type.
// Invariants:
//     0 <= _size
// Requirements on Types:
//    TODO: Write requirements on types

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
     _arrayptr(new value_type[8])
    {}

    // Dctor
    ~SSArray()
    {
	delete [] _arrayptr;
    }

    // Copy Ctor
    // TODO
    SSArray(const SSArray & other)
	:_size(other.size())
	
    {
	_arrayptr=new value_type[_size];
	std::copy(other.begin(), other.end(), begin());
    }

    // Move Ctor
    // TODO
    SSArray (SSArray && other) noexcept
	:_size(0),
	 _arrayptr(nullptr)
    {
	std::swap(_size, other._size);
        std::swap(_arrayptr, other._arrayptr);
    }

    // Copy Assignement
    // TODO
    SSArray & operator=(const SSArray & rhs)
    {
	SSArray old(rhs);
	std::swap(_size, old._size);
	std::swap(_arrayptr, old._arrayptr);
	return *this;
    }

    
    // Move Assignement
    // TODO
    SSArray & operator=(SSArray && rhs) noexcept
    {
	std::swap(_size, rhs._size);
	std::swap(_arrayptr, rhs._arrayptr);
	return *this;
    }
    

    // 1-parameter Ctor
    // Ctor from size
    // paramemter must be a non-negative integer
    // not an implicity type conversion
    explicit SSArray( size_type size)
	:_size(size),
	_arrayptr(new value_type[size])
    {}

    // 2- parameter Ctor
    // size, value
    // Creates SSArray of size size with every entry with value value
    SSArray(size_type size, const value_type &value)
	:_size(size),
	 _arrayptr(new value_type[size])
    {
	std::fill(begin(), end() ,value);
	// TODO: Can i Use std::end here instead of +_size.
    }

// ***** SSArray: General public members *****
public:

    // Bracket operators-[]
    // Returns a reference to the index item
    // Pre: 0 <= index <= _size-1
    // Post: [index] = _arrayptr[index]
    value_type & operator[] (size_type index)
    {
	//assert(0 <= index && index <= _size-1);
	return _arrayptr[index];
    }

    // const version
    const value_type & operator[] (size_type index) const
    {
	//assert(0 <= index && index <= _size-1);
	return _arrayptr[index];
    }


    // size: no parameters
    // Returns size of array
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
    // Returns the address of the 
    value_type* end()
    {
	return begin() + _size;
    }
    const value_type* end() const
    {
	return begin() + _size;
    }

    
// ***** SSArray: Data members *****
private:
    value_type * _arrayptr;//=nullptr ; // TODO: see without nullptr
    size_type _size;//=0 ;

};

// Returns true if every element of each SSArray are equal
// and both are same size
template <typename ValueType>
bool operator == (const SSArray<ValueType>& lhs, const SSArray<ValueType> & rhs)
{
    return std::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template <typename ValueType>
bool operator!= (const SSArray<ValueType> & lhs, const SSArray <ValueType> & rhs)
{
    return !(lhs == rhs);
}

// Comparison operators
// From https://en.cppreference.com/w/cpp/language/operators
template <typename ValueType>
bool operator<( const SSArray<ValueType> & lhs, const SSArray<ValueType> & rhs)
{
    return std::lexicographical_compare(lhs.begin(), lhs.end(),
                                     rhs.begin(), rhs.end());;
}

template <typename ValueType>
bool operator>( const SSArray<ValueType> & lhs, const SSArray<ValueType> & rhs)
{
    return rhs < lhs;
}


template <typename ValueType>
bool operator<=( const SSArray<ValueType> & lhs, const SSArray<ValueType> & rhs)
{
    return !(lhs > rhs);
}


template <typename ValueType>
bool operator>=( const SSArray<ValueType> & lhs, const SSArray<ValueType> & rhs)
{
    return !(lhs < rhs);
}


#endif //#ifndefFILE_SSARRAY_H_INCLUDED
