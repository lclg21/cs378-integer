// ------------------------------
// projects/c++/integer/Integer.h
// Copyright (C) 2015
// Glenn P. Downing
// ------------------------------

#ifndef Integer_h
#define Integer_h

// --------
// includes
// --------

#include <cassert>   // assert
#include <iostream>  // ostream
#include <stdexcept> // invalid_argument
#include <string>    // string
#include <vector>    // vector
#include <stack>
#include <iterator>

using namespace std;
// -----------------
// shift_left_digits
// -----------------

/**
 * @param b an iterator to the beginning of an input  sequence (inclusive)
 * @param e an iterator to the end       of an input  sequence (exclusive)
 * @param x an iterator to the beginning of an output sequence (inclusive)
 * @return  an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the shift left of the input sequence into the output sequence
 * ([b, e) << n) => x
 */
template <typename II, typename FI>
FI shift_left_digits (II b, II e, int n, FI x) {
  x = copy(b, e, x);
  fill(x, x+n, 0);
  return x+n;}
  /*
  while (b != e){
    *x = *b;
    ++b;
    ++x;
  }
  while (n !=0){
    *x = 0;
    ++x;
    --n;
  }
  return x;}
 */
  

// ------------------
// shift_right_digits
// ------------------

/**
 * @param b an iterator to the beginning of an input  sequence (inclusive)
 * @param e an iterator to the end       of an input  sequence (exclusive)
 * @param x an iterator to the beginning of an output sequence (inclusive)
 * @return  an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the shift right of the input sequence into the output sequence
 * ([b, e) >> n) => x
 */
template <typename II, typename FI>
FI shift_right_digits (II b, II e, int n, FI x) {
  return copy(b, e - n, x);}

 /* int a = n;
  while(n != 0){
    *x = 0;
    ++x;
    --n;
  }
  while(b+a != e){
    *x = *b;
    ++b;
    ++x;
  }
  return x;}
  */

// -----------
// plus_digits
// -----------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the sum of the two input sequences into the output sequence
 * ([b1, e1) + [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI plus_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
  int a = 0;
  int c = 0;
  while(b1 != e1){                //Took each digit from first iterator and put it into an int
    a = (a + *b1) * 10;
    ++b1;
  }
  a /= 10;                        //divided by 10 to take away last multiplication of 10

  while(b2 != e2){                //Took each digit from second iterator and put it into an int
    c = (c + *b2) * 10;
    ++b2;
  }
  c /= 10;                        //divided by 10 to take away last multiplication of 10

  a += c;
  stack<int> mystack;
  while(a!=0){                    //push each digit onto stack because we pull them out backwards from a
    mystack.push(a%10);
    a = a/10;
  }

  while(!mystack.empty()){        //pop them off the stack to put them in the right order in the interator.
    *x=mystack.top();
    mystack.pop();
    ++x;
  }

  return x;}
// ------------
// minus_digits
// ------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the difference of the two input sequences into the output sequence
 * ([b1, e1) - [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI minus_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
  int a = 0;
  int c = 0;
  while(b1 != e1){                //Took each digit from first iterator and put it into an int
    a = (a + *b1) * 10;
    ++b1;
  }
  a /= 10;                        //divided by 10 to take away last multiplication of 10

  while(b2 != e2){                //Took each digit from second iterator and put it into an int
    c = (c + *b2) * 10;
    ++b2;
  }
  c /= 10;                        //divided by 10 to take away last multiplication of 10

  a -= c;
  
  stack<int> mystack;
  while(a!=0){                    //push each digit onto stack because we pull them out backwards from a
    mystack.push(a%10);
    a = a/10;
  }

  while(!mystack.empty()){        //pop them off the stack to put them in the right order in the interator.
    *x=mystack.top();
    mystack.pop();
    ++x;
  }
  return x;}

// -----------------
// multiplies_digits
// -----------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the product of the two input sequences into the output sequence
 * ([b1, e1) * [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI multiplies_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
  int a = 0;
  int c = 0;
  while(b1 != e1){                //Took each digit from first iterator and put it into an int
    a = (a + *b1) * 10;
    ++b1;
  }
  a /= 10;                        //divided by 10 to take away last multiplication of 10

  while(b2 != e2){                //Took each digit from second iterator and put it into an int
    c = (c + *b2) * 10;
    ++b2;
  }
  c /= 10;                        //divided by 10 to take away last multiplication of 10

  a *= c;
  
  stack<int> mystack;
  while(a!=0){                    //push each digit onto stack because we pull them out backwards from a
    mystack.push(a%10);
    a = a/10;
  }

  while(!mystack.empty()){        //pop them off the stack to put them in the right order in the interator.
    *x=mystack.top();
    mystack.pop();
    ++x;
  }
  return x;}

// --------------
// divides_digits
// --------------

/**
 * @param b  an iterator to the beginning of an input  sequence (inclusive)
 * @param e  an iterator to the end       of an input  sequence (exclusive)
 * @param b2 an iterator to the beginning of an input  sequence (inclusive)
 * @param e2 an iterator to the end       of an input  sequence (exclusive)
 * @param x  an iterator to the beginning of an output sequence (inclusive)
 * @return   an iterator to the end       of an output sequence (exclusive)
 * the sequences are of decimal digits
 * output the division of the two input sequences into the output sequence
 * ([b1, e1) / [b2, e2)) => x
 */
template <typename II1, typename II2, typename FI>
FI divides_digits (II1 b1, II1 e1, II2 b2, II2 e2, FI x) {
  int a = 0;
  int c = 0;
  while(b1 != e1){                //Took each digit from first iterator and put it into an int
    a = (a + *b1) * 10;
    ++b1;
  }
  a /= 10;                        //divided by 10 to take away last multiplication of 10

  while(b2 != e2){                //Took each digit from second iterator and put it into an int
    c = (c + *b2) * 10;
    ++b2;
  }
  c /= 10;                        //divided by 10 to take away last multiplication of 10

  if(c > a){
    *x=0;
    return x;
  }
  
  a /= c;
  
  stack<int> mystack;
  while(a!=0){                    //push each digit onto stack because we pull them out backwards from a
    mystack.push(a%10);
    a = a/10;
  }

  while(!mystack.empty()){        //pop them off the stack to put them in the right order in the interator.
    *x=mystack.top();
    mystack.pop();
    ++x;
  }
  return x;}


// -------
// Integer
// -------

template < typename T, typename C = std::vector<T> >
  class Integer {
  // -----------
  // operator ==
  // -----------

  /**
   * @param lhs is the left hand side of the operator ==
   * @param rhs is the right hand side of the operator ==
   * @return true if lhs == rhs, false otherwise

   */
  friend bool operator == (const Integer& lhs, const Integer& rhs) {
    if(&lhs != &rhs){
      return true;
    }
    else{
      return false;
    }}
    
  // -----------
  // operator !=
  // -----------

  /**
   * @param lhs is the left hand side of the operator !=
   * @param rhs is the right hand side of the operator !=
   * @return true if lhs != rhs, false otherwise
   */
  friend bool operator != (const Integer& lhs, const Integer& rhs) {
    return !(lhs == rhs);}

  // ----------
  // operator <
  // ----------

  /**
   * @param lhs is the left hand side of the operator <
   * @param rhs is the right hand side of the operator <
   * @return true if  
   */
  friend bool operator < (const Integer& lhs, const Integer& rhs) {
    return !(&lhs > &rhs);}

  // -----------
  // operator <=
  // -----------

  /**
   * <your documentation>
   */
  friend bool operator <= (const Integer& lhs, const Integer& rhs) {
    return !(rhs < lhs);}

  // ----------
  // operator >
  // ----------

  /**
   * <your documentation>
   */
  friend bool operator > (const Integer& lhs, const Integer& rhs) {
    return (rhs < lhs);}

  // -----------
  // operator >=
  // -----------

  /**
   * <your documentation>
   */
  friend bool operator >= (const Integer& lhs, const Integer& rhs) {
    return !(lhs < rhs);}

  // ----------
  // operator +
  // ----------

  /**
   * <your documentation>
   */
  friend Integer operator + (Integer lhs, const Integer& rhs) {
    return lhs += rhs;}

  // ----------
  // operator -
  // ----------

  /**
   * <your documentation>
   */
  friend Integer operator - (Integer lhs, const Integer& rhs) {
    return lhs -= rhs;}

  // ----------
  // operator *
  // ----------

  /**
   * <your documentation>
   */
  friend Integer operator * (Integer lhs, const Integer& rhs) {
    return lhs *= rhs;}

  // ----------
  // operator /
  // ----------

  /**
   * <your documentation>
   * @throws invalid_argument if (rhs == 0)
   */
  friend Integer operator / (Integer lhs, const Integer& rhs) {
    return lhs /= rhs;}

  // ----------
  // operator %
  // ----------

  /**
   * <your documentation>
   * @throws invalid_argument if (rhs <= 0)
   */
  friend Integer operator % (Integer lhs, const Integer& rhs) {
    return lhs %= rhs;}

  // -----------
  // operator <<
  // -----------

  /**
   * <your documentation>
   * @throws invalid_argument if (rhs < 0)
   */
  friend Integer operator << (Integer lhs, int rhs) {
    return lhs <<= rhs;}

  // -----------
  // operator >>
  // -----------

  /**
   * <your documentation>
   * @throws invalid_argument if (rhs < 0)
   */
  friend Integer operator >> (Integer lhs, int rhs) {
    return lhs >>= rhs;}

  // -----------
  // operator <<
  // -----------

  /**
   * <your documentation>
   */
  friend std::ostream& operator << (std::ostream& lhs, const Integer& rhs) {
    // <your code>
    return lhs << "0";}

  // ---
  // abs
  // ---

  /**
   * absolute value
   * <your documentation>
   */
  friend Integer abs (Integer x) {
    return x.abs();}

  // ---
  // pow
  // ---

  /**
   * power
   * <your documentation>
   * @throws invalid_argument if ((x == 0) && (e == 0)) || (e < 0)
   */
  friend Integer pow (Integer x, int e) {
    return x.pow(e);}

 private:
  // ----
  // data
  // ----

  C _x; // the backing container
        // <your data>

 private:
  // -----
  // valid
  // -----

  bool valid () const { // class invariant
    // <your code>
    return true;}

 public:
  // ------------
  // constructors
  // ------------

  /**
   * <your documentation>
   */
  Integer (int value) {
    // <your code>
    assert(valid());}

  /**
   * <your documentation>
   * @throws invalid_argument if value is not a valid representation of an Integer
   */
  explicit Integer (const std::string& value) {
    // <your code>
    if (!valid())
      throw std::invalid_argument("Integer::Integer()");}

  // Default copy, destructor, and copy assignment.
  // Integer (const Integer&);
  // ~Integer ();
  // Integer& operator = (const Integer&);

  // ----------
  // operator -
  // ----------

  /**
   * <your documentation>
   */
  Integer operator - () const {
    // <your code>
    return Integer(0);}

  // -----------
  // operator ++
  // -----------

  /**
   * <your documentation>
   */
  Integer& operator ++ () {
    *this += 1;
    return *this;}

  /**
   * <your documentation>
   */
  Integer operator ++ (int) {
    Integer x = *this;
    ++(*this);
    return x;}

  // -----------
  // operator --
  // -----------

  /**
   * <your documentation>
   */
  Integer& operator -- () {
    *this -= 1;
    return *this;}

  /**
   * <your documentation>
   */
  Integer operator -- (int) {
    Integer x = *this;
    --(*this);
    return x;}

  // -----------
  // operator +=
  // -----------

  /**
   * <your documentation>
   */
  Integer& operator += (const Integer& rhs) {
    // <your code>
    return *this;}

  // -----------
  // operator -=
  // -----------

  /**
   * <your documentation>
   */
  Integer& operator -= (const Integer& rhs) {
    // <your code>
    return *this;}

  // -----------
  // operator *=
  // -----------

  /**
   * <your documentation>
   */
  Integer& operator *= (const Integer& rhs) {
    // <your code>
    return *this;}

  // -----------
  // operator /=
  // -----------

  /**
   * <your documentation>
   * @throws invalid_argument if (rhs == 0)
   */
  Integer& operator /= (const Integer& rhs) {
    // <your code>
    return *this;}

  // -----------
  // operator %=
  // -----------

  /**
   * <your documentation>
   * @throws invalid_argument if (rhs <= 0)
   */
  Integer& operator %= (const Integer& rhs) {
    // <your code>
    return *this;}

  // ------------
  // operator <<=
  // ------------

  /**
   * <your documentation>
   */
  Integer& operator <<= (int n) {
    // <your code>
    return *this;}

  // ------------
  // operator >>=
  // ------------

  /**
   * <your documentation>
   */
  Integer& operator >>= (int n) {
    // <your code>
    return *this;}

  // ---
  // abs
  // ---

  /**
   * absolute value
   * <your documentation>
   */
  Integer& abs () {
    // <your code>
    return *this;}

  // ---
  // pow
  // ---

  /**
   * power
   * <your documentation>
   * @throws invalid_argument if ((this == 0) && (e == 0)) or (e < 0)
   */
  Integer& pow (int e) {
    // <your code>
    return *this;}};

#endif // Integer_h
