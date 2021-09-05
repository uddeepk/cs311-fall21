// delivery.cpp
// Uddeep Karki
// Started: 2021-09-01
// Updated: 2021-09-02
//
// For CS 311 Fall 2021 - Project 1
// Source for class Delivery
// Delivery: product, quantity of product, month
// Based off of Dr. Glenn G. Chappell's timeofday.cpp.

#include "delivery.h" // For class Delivery
#include <vector> // For vector
#include <cassert> // For assert

//*********************************************************************
// class Delivery - Definitions of member functions
// ********************************************************************

// Default ctor definition
Delivery::Delivery()
{
    setProduct("UNSPECIFIED");
    setQuantity(0);
    setMonth(1);
}

// 3-param ctor definition
Delivery::Delivery(const std::string & product, int quantity, int month)
{
    assert( quantity >= 0 && 1 <= month && month <= 12);

    setProduct(product);
    setQuantity(quantity);
    setMonth(month);
}
// Delivery::getProduct
std::string Delivery::getName() const
{
    assert(_quantity >= 0 && 1 <= _month && _month <= 12);
    return  _product;
}

// Delivery::getQuantity
int Delivery::getQuantity() const
{
    assert(_quantity >= 0 && 1 <= _month && _month <= 12);
    
    return _quantity;
}

// Delivery::getMonth
int Delivery::getMonth() const
{
    assert(_quantity >= 0 && 1 <= _month && _month <= 12);

    return _month;
}

// Delivery::setProduct
void Delivery::setName(const std::string & product)
{
    _product = product;
}

// Delivery::setQuantity
void Delivery::setQuantity(int quantity)
{
    assert(quantity >= 0);
    
    _quantity = quantity;
}

// Delivery::setMonth
// Set month to a given number
void Delivery::setMonth(int month)
{
    assert(1 <= month && month <= 12);
   

    _month = month;
}

// Delivery::empty
bool Delivery::empty() const
{
    assert( _quantity >= 0 && 1 <= _month && _month <= 12);
    return _quantity == 0;
}

// Delivery::toString
std::string Delivery::toString() const
{
    assert( _quantity >= 0 && 1 <= _month && _month <= 12);
    std::vector <std::string> months {"Jan", "Feb", "Mar", "Apr", "May",
	"Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    std::string myStr = getProduct() + " ("+ std::to_string( getQuantity()) + "), " + months[getMonth()-1];
    return myStr;
}

// ****** Delivery: operator definitions ******

// global operators

// op==
bool operator==(const Delivery & lhs, const Delivery & rhs)
{
    assert( lhs.getQuantity() >= 0 && 1 <= lhs.getMonth() && lhs.getMonth() <= 12);
    assert( rhs.getQuantity() >= 0 && 1 <= rhs.getMonth() && rhs.getMonth() <= 12);

    return lhs.getProduct() == rhs.getProduct() && lhs.getQuantity() == rhs.getQuantity() && lhs.getMonth() == rhs.getMonth();
}

// op!=
bool operator!=(const Delivery & lhs, const Delivery & rhs)
{
       assert( lhs.getQuantity() >= 0 && 1 <= lhs.getMonth() && lhs.getMonth() <= 12);
    assert( rhs.getQuantity() >= 0 && 1 <= rhs.getMonth() && rhs.getMonth() <= 12);
    return !(lhs == rhs);
}

// ostream& operator<<
std::ostream & operator<<(std::ostream & str,
			  const Delivery & obj)
{
      assert( obj.getQuantity() >= 0 && 1 <= obj.getMonth() && obj.getMonth() <= 12);
      
    str << obj.toString();
    return str;
}

// ****Delivery : public operators

// op++[pre]
Delivery & Delivery::operator++()
{
      assert( _quantity >= 0 && 1 <= _month && _month <= 12);

      ++_quantity;
      return *this;
}

// op++[post]
Delivery Delivery::operator++([[maybe_unused]] int dummy)
{
      assert( _quantity >= 0 && 1 <= _month && _month <= 12);

      auto save = *this;
      ++(*this);
      return save;
}

// op--[pre]
Delivery & Delivery::operator--()
{
      assert( _quantity >= 0 && 1 <= _month && _month <= 12);

      if(_quantity > 0 ) --_quantity;
      return *this;
}

Delivery Delivery::operator--([[maybe_unused]] int dummy)
{
      assert( _quantity >= 0 && 1 <= _month && _month <= 12);

      auto save = *this;
      --(*this);
      return save;
}
