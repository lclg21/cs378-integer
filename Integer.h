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
#include <algorithm>
#include <stdlib.h>

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
 template <typename II1, typename II2, typename OI>
OI plus_digits (II1 b1, II1 e1, II2 b2, II2 e2, OI x) {
  int carry = 0;
  int num = 0;
  int sum = 0;
  int length1 = distance(b1, e1);
  int length2 = distance(b2, e2); 
  deque<int> container;

  // if (length1 == 1 && length2 == length2){
  //   num = *(e1 -1) + *(e2 -1);
  //   sum = num % 10;
  //   container.push_front(sum);

  // }

  if (length1 == length2){
    assert(length1 == length2);
    while(b1 != e1){
      assert(b1 != e1);
      num = *(e1-1) + *(e2-1) + carry;
      sum = num % 10;
      container.push_front(sum);
      if (num > 9){
        assert(num > 9);
        carry = 1;
      }
      else{
        carry = 0;
      }
      --e1;
      --e2;
    }

    if (carry == 1){
      assert(carry ==1);
      container.push_front(carry);
    }
    else{
      container.resize(length1);
    }

    for (deque<int>::iterator v = container.begin(); v != container.end(); ++v){
      *x++ = *v;
    }
  }
  else if (length1 > length2){
    assert(length1 > length2);
    while (b2 != e2){
      assert(b2 != e2);
      num = *(e1-1) + *(e2-1) + carry;
      sum = num % 10;
      container.push_front(sum);
      if (num > 9){
        assert(num > 9);
        carry = 1;
      }
      else{
        assert (num <= 9);
        carry = 0;
      }
      --e1;
      --e2;
    }
    while (b1 != e1){
      assert(b1 != e1);
      num = *(e1 - 1) + carry;
      sum = num % 10;
      container.push_front(sum);
      if (num > 9){
        assert(num > 9);
        carry = 1;
      }
      else {
        assert(num <= 9);
        carry = 0;
      }
      --e1;
    }
        
    if (carry == 1){
      assert(carry == 1);
      container.push_front(carry);
    }
    else{
      container.resize(length1);
    }

    for (deque<int>::iterator v = container.begin(); v != container.end(); ++v){
      *x++ = *v;
    }
  }
  else if (length2 > length1){
    assert(length2 > length1);
    while (b1 != e1){
      assert(b1 != e1);
      num = *(e1-1) + *(e2-1) + carry;
      sum = num % 10;
      container.push_front(sum);
      if (num > 9){
        assert(num > 9);
        carry = 1;
      }
      else{
        assert(num <= 9);
        carry = 0;
      }
      --e1;
      --e2;
    }
    while (b2 != e2){
      assert(b2 != e2);
      num = *(e2 - 1) + carry;
      sum = num % 10;
      container.push_front(sum);
      if (num > 9){
        assert(num > 9);
        carry = 1;
      }
      else {
        assert(num <= 9);
        carry = 0;
      }
      --e2;
    }
        
    if (carry == 1){
      assert(carry == 1);
      container.push_front(carry);
    }
    else{
      container.resize(length2);
    }

    for (deque<int>::iterator v = container.begin(); v != container.end(); ++v){
      *x++ = *v;
    }
  }
  return x;}
  

// ------------
// minus_digits
// ------------

/*
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
template <typename II1, typename II2, typename OI>
OI minus_digits (II1 b1, II1 e1, II2 b2, II2 e2, OI x) {

  //Need to remove leading 00s from the actual result
  //example 123 - 122 = 001 -> 1

  int carry = 0;
  int num = 0;
  int length1 = distance(b1, e1);
  int length2 = distance(b2, e2); 
  deque<int> container;

  if (length1 == length2){
    assert(length1 == length2);
    while(b1 != e1){
      assert(b1 != e1);
      if (*(e1 -1) < *(e2-1)){
        num = (*(e1-1) + 10) - (*(e2-1) + carry);
        container.push_front(num);
        carry = 1; 
      }
      else {
        num = *(e1 - 1) - (*(e2 - 1) + carry);
        container.push_front(num);
        carry = 0;
      }
      --e1;
      --e2;
    }

    for (deque<int>::iterator v = container.begin(); v != container.end(); ++v){
      *x++ = *v;
    }
  }
  else if (length1 > length2){
    assert(length1 > length2);
    while (b2 != e2){
      assert(b2 != e2);
      if (*(e1 -1) < *(e2-1)){
        assert(*(e1 -1) < *(e2-1));
        num = (*(e1-1) + 10) - (*(e2-1) + carry);
        container.push_front(num);
        carry = 1; 
      }
      else {
        num = *(e1 - 1) - (*(e2 - 1) + carry);
        container.push_front(num);
        carry = 0;
      }
      --e1;
      --e2;
    }
    while (b1 != e1){
        assert(b1 != e1);
        num = *(e1 - 1) - carry;
        carry = 0;
        container.push_front(num);
        --e1;
    }
    for (deque<int>::iterator v = container.begin(); v != container.end(); ++v){
      *x++ = *v;  
    }
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
 template <typename II>
 vector<int> find_multiples(II b1, II e1, int n) {
   vector<int> multiples;
   if (n == 0){
    assert(n == 0);
    multiples.push_back(0);
   }
   else{
    assert(n != 0);
    int carry = 0;
    while(b1 != e1){
      assert(b1 != e1);
      int temp = *(e1-1) * n;
      multiples.push_back(temp%10 + carry);
      if(temp>9){
        assert(temp > 9);
        carry = temp/10;
      }
      else{
        carry = 0;
      }
      --e1;
    }
   if (carry > 0){
    assert(carry > 0);
    multiples.push_back(carry);
    }
   }
   return multiples;
}
template <typename II1, typename II2, typename OI>
OI multiplies_digits (II1 b1, II1 e1, II2 b2, II2 e2, OI x) {
    vector<vector<int>> listofmultiples(10);
    int bottomlength = distance(b2, e2);
    int toplength = distance(b1, e1);
    vector<int> currenttotal(toplength+bottomlength+1);

    int i = 0;
    while(i < 10){
        assert(i < 10);
        vector<int> multipleofi = find_multiples(b1, e1, i);
        listofmultiples[i] = multipleofi;
      ++i;
  }
    
    vector<int>::reverse_iterator currentsumbeg = listofmultiples[*(e2-1)].rbegin();
    vector<int>::reverse_iterator currentsumend = listofmultiples[*(e2-1)].rend();

    --e2;
    int j = 1;
    vector<int> currentvalue(toplength+j+1);
    while(j < bottomlength){
        assert(j < bottomlength);
        vector<int>::reverse_iterator begbottom = listofmultiples[*(e2-1)].rbegin();
        vector<int>::reverse_iterator endbottom = listofmultiples[*(e2-1)].rend();
        currentvalue.resize(currentvalue.size()+1);
        vector<int>::iterator leftshifted = shift_left_digits (begbottom, endbottom, j, currentvalue.begin());      
        currentsumend = plus_digits(currentsumbeg, currentsumend, currentvalue.begin(), leftshifted, currenttotal.rbegin());
        currentsumbeg = currenttotal.rbegin();
        --e2;
        ++j;
    }
    x = copy(currentsumbeg, currentsumend, x);

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
  while(b1 != e1){
    assert(b1 != e1);                //Took each digit from first iterator and put it into an int
    a = (a + *b1) * 10;
    ++b1;
  }
  a /= 10;                        //divided by 10 to take away last multiplication of 10

  while(b2 != e2){ 
    assert(b2 != e2);               //Took each digit from second iterator and put it into an int
    c = (c + *b2) * 10;
    ++b2;
  }
  c /= 10;                        //divided by 10 to take away last multiplication of 10

  if(c > a){
    assert(c > a);
    *x=0;
    return x;
  }
  
  a /= c;
  
  stack<int> mystack;
  while(a!=0){  
    assert(a != 0);                  //push each digit onto stack because we pull them out backwards from a
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
     if(lhs._x.size() != rhs._x.size() ){
      assert(lhs._x.size() != rhs._x.size());
      return false;
    }
    if(lhs.neg != rhs.neg){
      assert(lhs.neg != rhs.neg);
      return false;
    }
    typename C::const_iterator left = lhs._x.begin();
    typename C::const_iterator right = rhs._x.begin();
    while(left != lhs._x.end()){
      assert(left != lhs._x.end());
      if(*left != *right){
        assert(*left != *right);
        return false;
      }
      ++left;
      ++right;
    }
    return true;}
    
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
   * @return true if lhs Intger is less than the rhs Integer  
   */
  friend bool operator < (const Integer& lhs, const Integer& rhs) {
    if(rhs == 0 && lhs.neg == true){
      assert(rhs == 0 && lhs.neg == true);
      return true;
    }
    if(rhs == 0 && lhs.neg ==false){
      assert(rhs == 0 && lhs.neg ==false);
      return false;
    }
    if(lhs == 0 && rhs.neg == true){
      assert(lhs == 0 && rhs.neg == true);
      return false;
    }
    if(lhs == 0 && rhs.neg == false){
      assert(lhs == 0 && rhs.neg == false);
      return true;
    }
    if(lhs.neg != rhs.neg){
      assert(lhs.neg != rhs.neg);
      if(lhs.neg == true){
        assert(lhs.neg == true);
        return true;
      }
      else{
        return false;
      }
    }
    else{
      if(lhs.neg == true){
        assert(lhs.neg == true);
        if(lhs._x.size() != rhs._x.size()){
          assert(lhs._x.size() != rhs._x.size());
          if(lhs._x.size()>rhs._x.size()){
            assert(lhs._x.size()>rhs._x.size());
            return true;
          }
          else{
            return false;
          }
        }

        typename C::const_iterator left = lhs._x.begin();
        typename C::const_iterator right = rhs._x.begin();
        typename C::const_iterator leftend = lhs._x.end();
        while(left != leftend){
          assert(left != leftend);
          if(*left < *right){
            assert(*left < *right);
            return false;
          }
          if(*right < *left){
            assert(*right < *left);
            return true;
          }
          ++left;
          ++right;
        }
      return false;}
      else{
        if(lhs._x.size() != rhs._x.size()){
          assert(lhs._x.size() != rhs._x.size());
          if(lhs._x.size()>rhs._x.size()){
            assert(lhs._x.size()>rhs._x.size());
            return false;
          }
          else{
            return true;
          }
        }

        typename C::const_iterator left = lhs._x.begin();
        typename C::const_iterator right = rhs._x.begin();
        typename C::const_iterator leftend = lhs._x.end();
        while(left != leftend){
          assert(left != leftend);
          if(*left > *right){
            assert(*left > *right);
            return false;
          }
          if(*right > *left){
            assert(*right > *left);
            return true;
          }
          ++left;
          ++right;
        }
      }
    }
    return false;}
  // -----------
  // operator <=
  // -----------

  /**
   * @param lhs is the left hand side of the operator <=
   * @param rhs is the right hand side of the operator <=
   * @return true if lhs Inteer is less than or equal to rhs Integer
   */
  friend bool operator <= (const Integer& lhs, const Integer& rhs) {
    return !(rhs < lhs);}

  // ----------
  // operator >
  // ----------

  /**
   * @param lhs is the leftvhand side of the operator >
   * @param rhs is the right hand of the operator >
   * @return true if lhs Integer is greater than the rhs Integer
   */
  friend bool operator > (const Integer& lhs, const Integer& rhs) {
    return (rhs < lhs);}

  // -----------
  // operator >=
  // -----------

  /**
   * @param lhs is the left hand side of the operator >=
   * @param rhs is the right hand side of the operator >=
   * @return true if lhs Integer is greater than or equal to rhs Integer
   */
  friend bool operator >= (const Integer& lhs, const Integer& rhs) {
    return !(lhs < rhs);}

  // ----------
  // operator +
  // ----------

  /**
   * @param lhs is the left hand side of the operator +
   * @param rhs is the right hand side of the operator +
   * @return sum between an Integer and a const Integer 
   */
  friend Integer operator + (Integer lhs, const Integer& rhs) {
    return lhs += rhs;}

  // ----------
  // operator -
  // ----------

  /**
   * @param lhs is the left hand side of the operator -
   * @param rhs is the right hand side of the operator -
   * @return difference between an Integer lhs and a const Integer rhs
   */
  friend Integer operator - (Integer lhs, const Integer& rhs) {
    return lhs -= rhs;}

  // ----------
  // operator *
  // ----------

  /**
   * @param lhs is the left hand side of the operator *
   * @param rhs is the righ hand side of the operator *
   * @return product between an Integer lhs and a const Integer rhs
   */
  friend Integer operator * (Integer lhs, const Integer& rhs) {
    return lhs *= rhs;}

  // ----------
  // operator /
  // ----------

  /**
   * @param lhs is the left hand side of the operator /
   * @param rhs is the right hand side of the operator /
   * @return  Integer, division between an Integer lhs and const Integer rhs
   * @throws invalid_argument if (rhs == 0)
   */
  friend Integer operator / (Integer lhs, const Integer& rhs) {
    return lhs /= rhs;}

  // ----------
  // operator %
  // ----------

  /**
   * @param lhs is the left hand side of the operator %
   * @param rhs is the right hand side of the operator %
   * @return Integer, modulus between an Integer lhs and a const Integer rhs 
   * @throws invalid_argument if (rhs <= 0)
   */
  friend Integer operator % (Integer lhs, const Integer& rhs) {
    return lhs %= rhs;}

  // -----------
  // operator <<
  // -----------

  /**
   * @param lhs is the left hand of the oeprator <<
   * @param rhs is the right hand side of the operator <<
   * @return shifts lhs rhs amount of places to the left
   * @throws invalid_argument if (rhs < 0)
   */
  friend Integer operator << (Integer lhs, int rhs) {
    return lhs <<= rhs;}

  // -----------
  // operator >>
  // -----------

  /**
   * @param lhs is the left hand side of the operator >>
   * @param rhs is the right hand side of the operator >>
   * @result shifts lhs rhs amount of places to the right
   * @throws invalid_argument if (rhs < 0)
   */
  friend Integer operator >> (Integer lhs, int rhs) {
    return lhs >>= rhs;}

  // -----------
  // operator <<
  // -----------

  /**
   * @param lhs ostream by reference
   * @param rhs const Integer by reference
   * @return ostream 
   */
  friend std::ostream& operator << (std::ostream& lhs, const Integer& rhs) {
    if (rhs.neg == true){
      assert(rhs.neg == true);
      lhs << "-";
    }
    typename C::const_iterator right = rhs._x.begin();
    while(right != rhs._x.end()){
      assert(right != rhs._x.end());
      lhs << *right;
      ++right;
    }
    return lhs;}

  // ---
  // abs
  // ---

  /**
   * absolute value
   * @param x Integer
   * @return absolute value of x
   */
  friend Integer abs (Integer x) {
    return x.abs();}

  // ---
  // pow
  // ---

  /**
   * power
   * @param x Integer
   * @param e int 
   * @return Integer x to the power of e
   * @throws invalid_argument if ((x == 0) && (e == 0)) || (e < 0)
   */
  friend Integer pow (Integer x, int e) {
    return x.pow(e);}

 private:
  // ----
  // data
  // ----

  C _x; // the backing container 
  bool neg; //negative flag

 private:
  // -----
  // valid
  // -----

  bool valid () const { // class invariant
    typename C::const_iterator b = _x.begin();
    typename C::const_iterator e = _x.end();
    while(b != e){
      assert(b != e);
      if((*b)>9 || (*b)<0){
        assert((*b)>9 || (*b)<0);
        return false;
      }
      ++b;
    }
    return true;}

 public:
  // ------------
  // constructors
  // ------------

  /**
   * Integer Constructor when given an int value.
   */
  Integer (int value) {
  
  if (value < 0){
    assert(value < 0);
    neg = true;
    value = -value;
  }
  else if(value == 0){
    assert(value == 0);
    neg = false;
    _x = C(1);
    _x.push_back(0);
    return;
  }
  else{
    neg = false;
  }
  int copyvalue = value;
  int numdigits = 0;
  while(copyvalue != 0){
    assert(copyvalue != 0);
    copyvalue = copyvalue/10;
    ++numdigits;
    }
  _x = C(numdigits);
  while(value != 0){
    assert(value != 0);
    _x[numdigits-1] = value%10;
    value /= 10;
    --numdigits;
  }
    assert(valid());}

  /**
   * Explicit integer constructor when given a valid string value
   * @throws invalid_argument if value is not a valid representation of an Integer
   */
  explicit Integer (const std::string& value) {
    int numdigits = 0;
    if(value[0] == '-'){
      assert(value[0] == '-');
      neg = true;
      numdigits = 1;
    }
    else{
      neg = false;
    }


      while(numdigits != value.length()){
        assert(numdigits != value.length());
        if(isdigit(value[numdigits])){
          assert(isdigit(value[numdigits]));
          _x.push_back(value[numdigits]-'0');
        }
        else{
          throw std::invalid_argument("Integer::Integer()");
        }
        ++numdigits;
      }
    
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
   * @return Integer in its negated form.
   * -1 -> 1
   */
  Integer operator - () const {
    if (*this == 0){
      assert(*this == 0);
      return *this;}
    Integer negation(*this);
    if(negation.neg == true){
      assert(negation.neg == true);
      negation.neg = false;
    }
    else{
      negation.neg = true;
    }
    return negation;
    }

  // -----------
  // operator ++
  // -----------

  /**
   * @return Integer incremented by 1 (prefix)
   * a = 1
   * ++a -> a = 2
   */
  Integer& operator ++ () {
    *this += 1;
    return *this;}

  /**
   * @return Integer incremented by 1 (postfix)
   * a = 1
   * a++ -> a = 2
   */
  Integer operator ++ (int) {
    Integer x = *this;
    ++(*this);
    return x;}

  // -----------
  // operator --
  // -----------

  /**
   * @return Integer decremented by 1 (prefix)
   * a = 2
   * --a -> a = 1
   */
  Integer& operator -- () {
    *this -= 1;
    return *this;}

  /**
   * @return Integer decremented by 1 (postfix)
   * a = 2
   * a-- -> a = 1
   */
  Integer operator -- (int) {
    Integer x = *this;
    --(*this);
    return x;}

  // -----------
  // operator +=
  // -----------

  /**
   * @return Integer lhs added with rhs and stored into lhs.
   * lhs = 1, rhs = 2
   * lhs += rhs -> lhs = 3
   */
  Integer& operator += (const Integer& rhs) {
    Integer lhs = *this;
    C container(lhs._x.size() + rhs._x.size() + 1, 0);
            
    typename C::iterator x = container.begin();
    typename C::iterator digits;
    
    if(lhs.neg == rhs.neg){
      assert(lhs.neg == rhs.neg);
      digits = plus_digits(lhs._x.begin(),lhs._x.end(),rhs._x.begin(),rhs._x.end(),x);
      this->neg = rhs.neg;
    }
    else{
      digits = minus_digits(lhs._x.begin(),lhs._x.end(),rhs._x.begin(),rhs._x.end(),x);
      if(lhs > rhs){
        assert(lhs > rhs);
        this->neg = lhs.neg;
      }
      else{
        this->neg = rhs.neg;
      }
    }
    C sum = C(x,digits);
    this->_x = sum;

    return *this;}

  // -----------
  // operator -=
  // -----------

  /**
   * @return Integer lhs subtracted with const rhs and stored into lhs.
   * lhs = 2, rhs = 1
   * lhs -= rhs -> lhs = 1
   */
  Integer& operator -= (const Integer& rhs) {
    Integer lhs = *this;
    C container(lhs._x.size() + rhs._x.size() + 1, 0);

    typename C::iterator x = container.begin();
    typename C::iterator digits;    

    if ((lhs.neg == rhs.neg)){
      assert(lhs.neg == rhs.neg);
      digits = minus_digits(lhs._x.begin(),lhs._x.end(),rhs._x.begin(),rhs._x.end(),x);
      if (lhs.neg == true && lhs < rhs){
        assert(lhs.neg == true && lhs < rhs);
        this->neg = lhs.neg;
      }
      else if (lhs.neg == false && lhs < rhs){
        assert(lhs.neg == false && lhs < rhs);
        this->neg = true;
      }
      else if (lhs.neg == true && lhs > rhs){
        assert(lhs.neg == true && lhs > rhs);
        this->neg = false;
      }
      else if (lhs.neg == false && lhs > rhs){
        assert(lhs.neg == false && lhs > rhs);
        this->neg = false;
      }
    }
    else{
      digits = plus_digits(lhs._x.begin(),lhs._x.end(),rhs._x.begin(),rhs._x.end(),x);
      this->neg = lhs.neg;

    }
    C diff = C(x, digits);
    this->_x = diff;
    return *this;}

  // -----------
  // operator *=
  // -----------

  /**
   * @return Integer lhs multiplied by const rhs and stored into lhs
   * lhs = 2, rhs = 2
   * lhs *= rhs -> lhs = 4
   */
  Integer& operator *= (const Integer& rhs) {
    Integer negative(*this);
    if(negative.neg == true && rhs.neg == true){
      assert(negative.neg == true && rhs.neg == true);
      neg = false;
    }
    if(negative.neg == true && rhs.neg == false){
      assert(negative.neg == true && rhs.neg == false);
      neg = true;
    }
    if(negative.neg == false && rhs.neg == true){
      assert(negative.neg == false && rhs.neg == true);
      neg = true;
    }
    if(negative.neg == false && rhs.neg == false){
      assert(negative.neg == false && rhs.neg == false);
      neg = false;
    }
    C container(1);
    if(_x.size() > rhs._x.size()){
      assert(_x.size() > rhs._x.size());
      container.resize(_x.size()*2);
    }
    else{
      container.resize(rhs._x.size()*2);
    }

    Integer lhs = *this;            
    typename C::iterator x = container.begin();
    typename C::iterator digits;
    digits = multiplies_digits(lhs._x.begin(),lhs._x.end(),rhs._x.begin(),rhs._x.end(),x);
     
    C product = C(x,digits);
    this->_x = product;

    return *this;}

  // -----------
  // operator /=
  // -----------

  /**
   * @return Integer lhs divided by rhs and stored into lhs
   * @throws invalid_argument if (rhs == 0)
   * lhs = 10, rhs = 2
   * lhs /= rhs -> lhs = 5
   */
  Integer& operator /= (const Integer& rhs) {
    if(rhs == 0){
      assert(rhs == 0);
      throw std::invalid_argument("Integer::Integer()");
    }
    
    Integer lhs = *this;
     C container(lhs._x.size() + rhs._x.size() + 1, 0);

    typename C::iterator x = container.begin();
    typename C::iterator digits;  

    if (lhs.neg == false && rhs.neg == false){
      digits = divides_digits(lhs._x.begin(),lhs._x.end(),rhs._x.begin(),rhs._x.end(),x);
      this->neg = false;
    }
    else if(lhs.neg == true && rhs.neg == true){
      digits = divides_digits(lhs._x.begin(),lhs._x.end(),rhs._x.begin(),rhs._x.end(),x);
      this->neg = true;
    }
    C quotient = C(x, digits);
    this->_x = quotient;
    return *this;}

  // -----------
  // operator %=
  // -----------

  /**
   * @return Integer lhs mod by const rhs and store into lhs.
   * @throws invalid_argument if (rhs <= 0)
   * lhs = 10, rhs = 3
   * lhs %= rhs -> lhs = 1
   */
  Integer& operator %= (const Integer& rhs) {
    if (rhs <= 0){
      assert(rhs <= 0);
      throw std::invalid_argument("Integer::Integer()");
    }
  //    *this = *this % &rhs;
    return *this;}

  // ------------
  // operator <<=
  // ------------

  /**
   * @return Integer lhs shifted n places to the left and stored into lhs
   * lhs = 111, n = 2
   * lhs <<= 2 -> lhs = 11100
   */
  Integer& operator <<= (int n) {
    if(n < 0){
      assert(n < 0);
      return *this>>=(-n);
    }
    else if(n==0){
      assert(n == 0);
      return *this;
    }
    else{
    Integer lhs = *this;
    _x.resize(lhs._x.size()+n);
    shift_left_digits (lhs._x.begin(), lhs._x.end(), n, _x.begin());

    return *this;}}

  // ------------
  // operator >>=
  // ------------

  /**
   * @return Integer lhs shifted n place to the right and stored into lhs.
   * lhs = 111, n = 2
   * lhs >>= 2 -> lhs = 001
   */
  Integer& operator >>= (int n) {
    if(n < 0){
      assert(n < 0);
      return *this<<=(-n);
    }
    else if(n==0){
      assert(n == 0);
      return *this;
    }
    else{
    Integer lhs = *this;
    _x.resize(lhs._x.size()-n);
    shift_right_digits (lhs._x.begin(), lhs._x.end(), n, _x.begin());

    return *this;}}

  // ---
  // abs
  // ---

  /**
   * @return absolute value of an Integer
   * lhs = -9 
   * lhs.abs() -> 9
   */
  Integer& abs () {
      neg = false;
      return *this;
    }


  // ---
  // pow
  // ---

  /**
   * power
   * @return Integer value raised to the e power.
   * @throws invalid_argument if ((this == 0) && (e == 0)) or (e < 0)
   */

  
  Integer& pow (int e) {
    if( (*this == 0) && (e == 0) ){
      assert((*this == 0) && (e == 0));
      throw std::invalid_argument("Integer::Integer()");
    }
    if (e < 0) {
      assert(e < 0);
      throw std::invalid_argument("Integer::Integer()");
    }

    if(e == 0){
      assert(e == 0);
      *this = 1;
      return *this;
    }  
    else if (e == 1){
      return *this;
    }

    Integer j = 1;
    while(e != 0){
      if (e%2 == 0) {
        for (int i = 0; i < e/2; ++i){
          j *= *this * *this;
        }
      *this = j;
      return *this;
      }
      j *= *this;
      --e;
    }
    return *this;}};


#endif // Integer_h
