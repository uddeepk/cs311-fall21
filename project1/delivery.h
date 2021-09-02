// delivery.h
// Uddeep Karki
// Started: 2021-09-01
// Updated:
//
// For CS 311 Fall 2021 - Project 1
// Header for class Delivery
// Delivery: product, quantity of product, month

#ifndef FILE_DELIVERY_H_INCLUDED
#define FILE_DELIVERY_H_INCLUDED

#include <string>  // For std::string
#include <ostream> // For std::ostream
#include <cassert> // For assert
// **********************************
// class Delivery - Class definition
// **********************************


// class Delivery
// Delivery: product, quantity of product, month

class Delivery {

// ***** Delivery: Friend declarations ******
    // ostream<<(ostream
    // Prints string representation of data
    friend
	std::ostream & operator<<(std::ostream & str, const Delivery & obj);
    // op==
    // Returns true if product names, quantities, and months are equal
    // Defined in source
    friend
	bool operator==(const Delivery & lhs, const  Delivery & rhs);

    
    // op!=
    // Returns false if product names, quantities or month are not same
    // Defined in source
    friend
	bool operator!=(const Delivery & lhs, const Delivery & rhs);

public:
    
    // Default ctor
    // Set string to "UNSPECIFIED"
    // Defined in source
    Delivery();

    // 3-parameter Ctor from product, quantity, and month
    // Defined in source
    Delivery(const std::string & ,int ,int );


// ***** Delivery: General public *****
public:

    // *** getters ***

    // getProduct
    // Returns product
    // Function defined in source
    std::string getProduct() const;

    // getName
    // Return product name using getProduct
    // Function
    std::string getName() const;
    
    // getQuantity
    // Returns the quantity of the product
    // Function defined in source
    int getQuantity() const;

    // get Month
    // Returns the calendar month (1-12)
    // Function defined in source
    int getMonth() const;

    // *** setters ***

    // setProduct
    // Set product to given name
    // Function defined in source
    void setProduct(const std::string & product);

    // setName
    // Set product to given name using setProduct
    // Function defined in source
    void setName(const std::string & profuct);
    
    // setQuantity
    // Set Quantity to given number
    // Function defined in source
    void setQuantity(int quantity);

    // set Month
    // Set month to given number
    // Function defined in source
    void setMonth(int month);

    // *** more general public functions ***

    // empty
    // Returns true if quantity zero otherwise false
    // Function defined in source
    bool empty() const;

    // toString
    // Returns string representation of data
    // Function defined in source
    std::string toString() const;

    
// ****** Delivery: General public operators ******
public:

    // op++[pre]
    // Increment quantity by 1
    // Defined in Source
    Delivery & operator++();

    // op++[post]
    // Increment quantity by 1
    // Defined in source
    Delivery operator++([[maybe_unused]] int dummy);

    //op--[pre]
    // Decrease quantity by 1 if its not 0
    // Defined in source
    Delivery & operator--();

    // op--[post]
    // Decrease quantity by 1 if its not 0
    // Defined in source
    Delivery operator--([[maybe_unused]] int dummy);
    

// ****** Delivery: Data members ********
private:
    
    std::string _product; // Name of product
    int _quantity; // Quantity of the product
    int _month; // Calendar month (1-12)

};

#endif //#ifndef FILE_DELIVERY_H_INCLUDED
