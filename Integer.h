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
    int len = distance(b1,e1);
    if(len < distance(b2, e2)){
      len = distance(b2,e2);}
    OI endx = x+len;
    bool stop = false;
    int carryOver = 0;
    while(!stop){   
                if (b1 != e1 && b2 != e2){
                    //std::cout << "Normal Case" << std::endl;
                    int temp = *(e1-1) + *(e2-1) + carryOver;
                    carryOver = 0;
                    if(temp >= 10){
                        carryOver = 1;
                        temp -= 10;
                    }
                    *(x+len) = temp;
                    --e1;
                    --e2;
                    --len;
                } else if(b1 != e1){
                    //std::cout << "b1 longer Case" << std::endl;
                    int temp = *(e1-1) + carryOver;
                    carryOver = 0;
                    if(temp >= 10){
                        carryOver = 1;
                        temp -= 10;
                    }
                     *(x+len) = temp;
                    --e1;
                    --len;
                } else if(b2 != e2){
                    //std::cout << "b2 longer Case" << std::endl;
                    int temp = *(e2-1) + carryOver;
                    carryOver = 0;
                    if(temp >= 10){
                        carryOver = 1;
                        temp -= 10;
                    }
                     *(x+len) = temp;
                    --e2;
                    --len;         
                } else{
                    //std::cout << "Else Case" << std::endl;
                    if(carryOver != 0){
                        *(x+len) = carryOver;
                        carryOver = 0;
                        ++endx;
                    } else{
                        endx = shift_left_digits (x+1, endx+1, 1, x);
                        --endx;
                    }
                    stop = true;
                }
            }
            return endx;
      }

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
template <typename II1, typename II2, typename OI>
OI multiplies_digits (II1 b1, II1 e1, II2 b2, II2 e2, OI x) {
  int length1 = distance(b1,e1);
  int length2 = distance(b2,e2);
  int topshift = 0;
  int bottomshift=0;
  
  vector<int> total = {0};
  if(length1 >= length2){
   while(b2!=e2){
      while(b1 != e1){
        int temp = *(e2-1) * *(e1-1);
        vector<int> producttosum(2);
	     int i = 2;
        while(i != 0){
	       producttosum[i-1]=temp%10;
          temp /= 10;
	       --i;
        }
        vector<int> topshiftedproduct(1);
        vector<int> bottomshiftedproduct(1);
        vector<int> runningtotal(1);
        shift_left_digits(producttosum.begin(), producttosum.end(), topshift, topshiftedproduct.begin());
	shift_left_digits(topshiftedproduct.begin(), topshiftedproduct.end(), bottomshift, bottomshiftedproduct.begin());
	plus_digits(total.begin(), total.end(), bottomshiftedproduct.begin(), bottomshiftedproduct.end(), runningtotal.begin());
	copy(runningtotal.begin(), runningtotal.end(), total.begin());
        --e1;
        ++topshift;

	II1 rtb = runningtotal.begin();
	II1 rte = runningtotal.end();
	while(rtb != rte){
	cout << "running total has in it " << *rtb << endl;
	++rtb;
      }}
      --e2;
      ++bottomshift;
    }
  }
  else{
  while(b1!=e1){
      while(b2 != e2){
        int temp = *(e2-1) * *(e1-1);
        vector<int> producttosum(2);
        int i = 2;
        while(i != 0){
          producttosum[i-1]=temp%10;
          temp /= 10;
          --i;
        }
        vector<int> topshiftedproduct(1);
        vector<int> bottomshiftedproduct(1);
        vector<int> runningtotal(1);
        shift_left_digits(producttosum.begin(), producttosum.end(), topshift, topshiftedproduct.begin());
        shift_left_digits(topshiftedproduct.begin(), topshiftedproduct.end(), bottomshift, bottomshiftedproduct.begin());
        plus_digits(total.begin(), total.end(), bottomshiftedproduct.begin(), bottomshiftedproduct.end(), runningtotal.begin());
        copy(runningtotal.begin(), runningtotal.end(), total.begin());
        --e2;
        ++bottomshift;
	II1 rtb = runningtotal.begin();
	II1 rte = runningtotal.end();
	while(rtb != rte){
	cout << "running total has in it " << *rtb << endl;
	++rtb;
      }
cout<< "that was one full running total " << endl;}
      --e1;
      ++topshift;
    }
  }
  II1 beginningofx = total.begin();
  II1 endofx = total.end();
  while(beginningofx != endofx){
    cout<< *beginningofx << endl; 
	++beginningofx; }
  x = copy(total.begin(), total.end(), x);
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
     if(lhs._x.size() != rhs._x.size() ){
      return false;
    }
    if(lhs.neg != rhs.neg){
      return false;
    }
    typename C::const_iterator left = lhs._x.begin();
    typename C::const_iterator right = rhs._x.begin();
    while(left != lhs._x.end()){
      if(*left != *right){
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
      return true;
    }
    if(rhs == 0 && lhs.neg ==false){
      return false;
    }
    if(lhs == 0 && rhs.neg == true){
      return false;
    }
    if(lhs == 0 && rhs.neg == false){
      return true;
    }
    if(lhs.neg != rhs.neg){
      if(lhs.neg == true){
        return true;
      }
      else{
        return false;
      }
    }
    else{
      if(lhs.neg == true){
        if(lhs._x.size() != rhs._x.size()){
          if(lhs._x.size()>rhs._x.size()){
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
          if(*left < *right){
            return false;
          }
          if(*right < *left){
            return true;
          }
          ++left;
          ++right;
        }
      return false;}
      else{
        if(lhs._x.size() != rhs._x.size()){
          if(lhs._x.size()>rhs._x.size()){
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
          if(*left > *right){
            return false;
          }
          if(*right > *left){
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
      lhs << "-";
    }
    typename C::const_iterator right = rhs._x.begin();
    while(right != rhs._x.end()){
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
      if((*b)>9 || (*b)<0){
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
   * <your documentation>
   */
  Integer (int value) {
  
  if (value < 0){
    neg = true;
    value = -value;
  }
  else if(value == 0){
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
    copyvalue = copyvalue/10;
    ++numdigits;
    }
  _x = C(numdigits);
  while(value != 0){
    _x[numdigits-1] = value%10;
    value /= 10;
    --numdigits;
  }
    assert(valid());}

  /**
   * <your documentation>
   * @throws invalid_argument if value is not a valid representation of an Integer
   */
  explicit Integer (const std::string& value) {
    int numdigits = 0;
    if(value[0] == '-'){
      neg = true;
      numdigits = 1;
    }
    else{
      neg = false;
    }


      while(numdigits != value.length()){
        if(isdigit(value[numdigits])){
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
   * <your documentation>
   */
  Integer operator - () const {
    if (*this == 0){
      return *this;}
    Integer negation(*this);
    if(negation.neg == true){
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
    Integer lhs = *this;
    return *this;}

  // -----------
  // operator -=
  // -----------

  /**
   * <your documentation>
   */
  Integer& operator -= (const Integer& rhs) {
        // <your code>
    //*this = *this - &rhs;
    return *this;}

  // -----------
  // operator *=
  // -----------

  /**
   * <your documentation>
   */
  Integer& operator *= (const Integer& rhs) {
        // <your code>
      Integer  i = *this * &rhs;
    return i;}

  // -----------
  // operator /=
  // -----------

  /**
   * <your documentation>
   * @throws invalid_argument if (rhs == 0)
   */
  Integer& operator /= (const Integer& rhs) {
        // <your code>
    if(rhs == 0){
      throw std::invalid_argument("Integer::Integer()");
    }
  //   *this = *this / &rhs;
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
 //    *this = *this % &rhs;
    return *this;}

  // ------------
  // operator <<=
  // ------------

  /**
   * <your documentation>
   */
  Integer& operator <<= (int n) {
    // <your code>
    if(n < 0){
      return *this>>=(-n);
    }
    else if(n==0){
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
   * <your documentation>
   */
  Integer& operator >>= (int n) {
    // <your code>
    if(n < 0){
      return *this<<=(-n);
    }
    else if(n==0){
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
   * absolute value
   * <your documentation>
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
   * <your documentation>
   * @throws invalid_argument if ((this == 0) && (e == 0)) or (e < 0)
   */
  Integer& pow (int e) {
    // your code
    if( (*this == 0) && (e == 0) ){
      throw std::invalid_argument("Integer::Integer()");
    }
    if (e < 0) {
      throw std::invalid_argument("Integer::Integer()");
    }
    return *this;}};

#endif // Integer_h
