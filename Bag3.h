// FILE: Bag3.h
// CLASS PROVIDED: Bag 
// CREDIT TO: Main and Savitch, Data Structures and Other Objects Using C++
//
// TYPEDEF and MEMBER CONSTANTS for the Bag class:
//   using value_type = _____
//     Bag::value_type is the data type of the items in the Bag. It may be any of
//     the C++ built-in types (int, char, etc.), or a class with a default
//     constructor, an assignment operator, and operators to
//     test for equality (x == y) and non-equality (x != y).
//
//   using size_type = _____
//     Bag::size_type is the data type of any variable that keeps track of how many items
//     are in a Bag.
//
//   static const size_type CAPACITY = _____
//     Bag::CAPACITY is the maximum number of items that a Bag can hold.
//
// CONSTRUCTOR for the Bag class:
//   Bag()
//     Postcondition: The Bag has been initialized as an empty Bag.
//
// MODIFICATION MEMBER FUNCTIONS for the Bag class:
//   size_type erase(const value_type& target);
//     Postcondition: All copies of target have been removed from the Bag.
//     The return value is the number of copies removed (which could be zero).
//
//   void erase_one(const value_type& target)
//     Postcondition: If target was in the Bag, then one copy has been removed;
//     otherwise the Bag is unchanged. A true return value indicates that one
//     copy was removed; false indicates that nothing was removed.
//
//   void insert(const value_type& entry)
//     Precondition:  size() < CAPACITY.
//     Postcondition: A new copy of entry has been added to the Bag.
//
//   Bag operator +=(const Bag& addend)
//     Precondition:  size() + addend.size() <= CAPACITY.
//     Postcondition: Each item in addend has been added to this Bag. The return
//     value is the updated Bag.
//
// CONSTANT MEMBER FUNCTIONS for the Bag class:
//   size_type size() const
//     Postcondition: The return value is the total number of items in the Bag.
//
//   size_type count(const value_type& target) const
//     Postcondition: The return value is number of times target is in the Bag.
//
// FRIEND FUNCTIONS for the Bag class:
//   std::ostream& operator<<(std::ostream& os, Bag b)
//     Precondition: os is ready to be written to.
//     Postcondition: the entries of b have been written to os, separated by spaces.
//     The return value is a reference to the ostream object os.
//
// NONMEMBER FUNCTIONS for the Bag class:
//   Bag operator +(const Bag& b1, const Bag& b2)
//     Precondition:  b1.size() + b2.size() <= Bag::CAPACITY.
//     Postcondition: The Bag returned is the union of b1 and b2.
//
// VALUE SEMANTICS for the Bag class:
//    Assignments and the copy constructor may be used with Bag objects.

#ifndef Bag3_H
#define Bag3_H
#include <iostream>
#include <cstddef>

class Bag
{
public:
    // TYPEDEFS and MEMBER CONSTANTS
    using value_type = int;
    using size_type = std::size_t; 
    // static const size_type DEFAULT_CAPACITY = 3;
    // CONSTRUCTOR
    // Bag(size_type initial_capacity = DEFAULT_CAPACITY);
    Bag();
    Bag(const Bag& source);
    ~Bag();
    // MODIFICATION MEMBER FUNCTIONS
    // void reserve(size_type new_capacity);
    // we don't need a reserve function in a linked-list based
    // bag class
    size_type erase(const value_type& target);
    bool erase_one(const value_type& target);
    void insert(const value_type& entry);
    Bag& operator+=(const Bag& addend);
    Bag& operator=(const Bag& source);
    // CONSTANT (non-modifying) MEMBER FUNCTIONS
    size_type size() const { return sz; }
    size_type count(const value_type& target) const; 
private:
    node *head_ptr;
    size_type sz;
    // NONMEMBER FRIEND FUNCTIONS
    friend std::ostream& operator<<(std::ostream& os, Bag b);
};

Bag operator+(const Bag& b1, const Bag& b2);
#endif
