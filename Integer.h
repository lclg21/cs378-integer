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
std::vector<int> multiply_helper(II b1, II e1, int n) {
    using namespace std;
    vector<int> result;
    if(n == 0){
        result.push_back(0);
        return result;
    }
    int carryOver = 0;
    int temp;
    //int len = e1-b1;
    //OI endx = x+len;
    while(b1 != e1){
        temp = (*(e1-1) * n) + carryOver;
        carryOver = 0;
        if(temp >= 10){
            result.push_back(temp%10);
            carryOver = temp / 10;
        } else{
            result.push_back(temp);
        }
        //--len;
        --e1;
    }
    if(carryOver != 0){
        result.push_back(carryOver);
    }
    return result;
}

template <typename II1, typename II2, typename OI>
OI multiplies_digits (II1 b1, II1 e1, II2 b2, II2 e2, OI x) {
  /*  using namespace std;
    vector< vector<int> > cache(10);
    for(int i=0; i<10; ++i){
        vector<int> temp = multiply_helper(b1, e1, i);
        cache[i] = temp;
    }
    
   
    vector<int>::reverse_iterator productb = cache[*(e2-1)].rbegin();
    vector<int>::reverse_iterator producte = cache[*(e2-1)].rend();
    int len = (e2-b2);
    vector<int> tempCons((e1-b1) + len + 1);
    
    for(int i=1; i<len; ++i){
        --e2;
        vector<int>::reverse_iterator cb = cache[*(e2-1)].rbegin();
        vector<int>::reverse_iterator ce = cache[*(e2-1)].rend();
        vector<int> temp((e1-b1)+1+i);
        vector<int>::iterator tempe = shift_left_digits (cb, ce, i, temp.begin());      
        producte = plus_digits(productb, producte, temp.begin(), tempe, tempCons.rbegin());
        productb = tempCons.rbegin();
    }

    while(productb != producte){
        *x = *productb;
        ++x;
        ++productb;
    }
*/
  int carry = 0;
  int num = 0;
  int length1 = distance(b1, e1);
  int length2 = distance(b2, e2);
  deque<int> container;
  deque<int> extracontainer;
  deque<int>::iterator y;

 
  if (length1 == length2){
    while(b1 != e1){
      assert(b1 != e1);
      while (b2 != e2){
        num = *(e1-1) * (*(e2-1) + carry);
	num = num / 10;
        container.push_front(num);
        carry = num % 10;
	--e2;
      }
      if (carry != 0){
	container.push_front(carry);
      }
      plus_digit(container.begin(), container.end(), extracontainer.begin(), extracontainer.end(), y.begin() );
      --e1;
    }
    for (deque<int>::iterator v = x.begin(); v != x.end(); ++v){
      *x++ = *v;
    }    
  }
  else  if (length2 > length1){
    while(b2 != e2){
      assert(b2 != e2);
      while (b1 != e1){
        num = *(e2-1) * (*(e1-1) + carry);
        num = num / 10;
        container.push_front(num);
        carry = num % 10;
        --e1;
      }
      if (carry != 0){
        container.push_front(carry);
      }
      --e2;
    }
    for (deque<int>::iterator v = container.begin(); v != container.end(); ++v){
      *x++ = *v;
    }
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
      if (e%22 == 0){
	assert(e%22 == 0);
        Integer eleven = *this * *this * *this * *this * *this * *this * *this * *this * *this * *this * *this;
        Integer twtwo = eleven * eleven;
        for (int i = 0; i < e/22; ++i){
          j *= twtwo;
        }
        *this = j;
        return *this;
      }
      else if (e%21 == 0){
        assert (e%21 == 0);
        Integer ten = *this * *this * *this * *this * *this * *this * *this * *this * *this * *this;
        Integer twone = ten *ten * *this;
        for (int i = 0; i < e/21; ++i){
          j *= twone;
        }
        *this = j;
        return *this;
      }
      else if (e%20 == 0){
	assert (e%20 == 0);
        Integer ten = *this * *this * *this * *this * *this * *this * *this * *this * *this * *this;
        Integer tw = ten *ten;
        for (int i = 0; i < e/20; ++i){
          j *= tw;
        }
        *this = j;
        return *this;
      }
      else if (e%19 == 0){
	assert (e%19 == 0);
        Integer nine = *this * *this * *this * *this * *this * *this * *this * *this * *this;
        Integer nteen = nine * nine * *this;
        for (int i = 0; i < e/19; ++i){
          j *= nteen;
        }
        *this = j;
        return *this;
      }
      else if (e%18 == 0){
	assert (e%18 == 0);
        Integer nine = *this * *this * *this * *this * *this * *this * *this * *this * *this;
        Integer eteen = nine * nine;
        for (int i = 0; i < e/18; ++i){
          j *= eteen;
        }
        *this = j;
        return *this;
      }
      else if (e%17 == 0){
	assert (e%17 == 0);
        Integer eight =*this * *this * *this * *this * *this * *this * *this * *this;
        Integer seteen = eight * eight * *this;
        for (int i = 0; i < e/17; ++i){
          j *= seteen;
        }
        *this = j;
        return *this;
      }
      else if (e%16 == 0){
	assert (e%16 == 0);
        Integer eight =*this * *this * *this * *this * *this * *this * *this * *this;
        Integer sixteen = eight * eight;
        for (int i = 0; i < e/16; ++i){
          j *= sixteen;
        }
        *this = j;
        return *this;
      }
      else if (e%15 == 0){
	assert (e%15 == 0);
        Integer seven =*this * *this * *this * *this * *this * *this * *this;
        Integer fifteen = seven * seven * *this;
        for (int i = 0; i < e/15; ++i){
          j *= fifteen;
        }
        *this = j;
        return *this;
      }
      else if (e%14 == 0){
	assert (e%14 == 0);
        Integer seven =*this * *this * *this * *this * *this * *this * *this;
        Integer fourteen = seven * seven;
        for (int i = 0; i < e/14; ++i){
          j *= fourteen;
        }
        *this = j;
        return *this;
      }
      else if (e%13 == 0){
	assert (e%13 == 0);
        Integer six =*this * *this * *this * *this * *this * *this;
        Integer thteen = six * six * *this;
        for (int i = 0; i < e/13; ++i){
          j *= thteen;
        }
        *this = j;
        return *this;
      }
      else if (e%12 == 0){
	assert (e%12 == 0);
        Integer six =*this * *this * *this * *this * *this * *this;
        Integer twelve = six * six;
        for (int i = 0; i < e/12; ++i){
          j *= twelve;
        }
        *this = j;
        return *this;
      }
      else if (e%11 == 0){
	assert (e%11 == 0);
        Integer five =*this * *this * *this * *this * *this;
        Integer eleven = five * five * *this;
        for (int i = 0; i < e/11; ++i){
          j *= eleven;
        }
        *this = j;
        return *this;
      }
      else if (e%10 == 0){
	assert (e%10 == 0);
        Integer five =*this * *this * *this * *this * *this;
        Integer ten = five * five;
        for (int i = 0; i < e/10; ++i){
          j *= ten;
        }
        *this = j;
        return *this;
      }
      else if (e%9 == 0){
	assert (e%9 == 0);
        Integer four =*this * *this * *this * *this;
        Integer nine = four * four * *this;
        for (int i = 0; i < e/9; ++i){
          j *= nine;
        }
        *this = j;
        return *this;
      }
      else if (e%8 == 0){
	assert (e%8 == 0);
        Integer four =*this * *this * *this * *this;
        Integer eight = four * four;
        for (int i = 0; i < e/8; ++i){
          j *= eight;
        }
        *this = j;
        return *this;
      }
      else if (e%7 == 0){
	assert (e%7 == 0);
        Integer three =*this * *this * *this;
        Integer seven = three * three * *this;
        for (int i = 0; i < e/7; ++i){
          j *= seven;
        }
        *this = j;
        return *this;
      }
      else if (e%6 == 0){
	assert (e%6 == 0);
        Integer three =*this * *this * *this;
        Integer six = three * three;
        for (int i = 0; i < e/6; ++i){
          j *= six;
        }
        *this = j;
        return *this;
      }
      else if (e%5 == 0){
	assert (e%5 == 0);
        Integer two =*this * *this;
        Integer five = two * two * *this;
        for (int i = 0; i < e/5; ++i){
          j *= five;
        }
        *this = j;
        return *this;
      }
      else if (e%4 == 0){
	assert (e%4 == 0);
        Integer two =*this * *this;
        Integer four = two * two;
        for (int i = 0; i < e/4; ++i){
          j *= four;
        }
        *this = j;
        return *this;
      }
      else if (e%3 == 0){
	assert (e%3 == 0);
        Integer three = *this * *this * *this;
        for (int i = 0; i < e/3; ++i){
          j *= three;
        }
        *this = j;
        return *this;
      }
    else if (e%2 == 0) {
      assert (e%2 == 0);
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
