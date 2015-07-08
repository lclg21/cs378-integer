// --------------------------------
// projects/collatz/TestInteger.c++
// Copyright (C) 2015
// Glenn P. Downing
// --------------------------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include <iostream> // cout, endl
#include <sstream>  // istringtstream, ostringstream
#include <string>   // string
#include <utility>  // pair
#include <vector>
#include <list>

#include "gtest/gtest.h"

#include "Integer.h"

using namespace std;

// -----------
// TestInteger
// -----------

// -----------------
// shift_left_digits
// -----------------

TEST(Integer, shift_left_digits ) {
  vector<int>       x = {1, 2, 3, 4, 5, 6};
  vector<int>           y(8);
  shift_left_digits(x.begin(), x.end(), 2, y.begin());
  const list<int>       a = {1, 2, 3, 4, 5, 6, 0, 0};
  ASSERT_TRUE(equal(a.begin(), a.end(), y.begin()));}

TEST(Integer, shift_left_digits2 ) {
  const vector<int>       x = {1, 2, 3, 4, 5, 6};
  vector<int>           y(4);
  shift_left_digits(x.begin()+1, x.begin()+3, 2, y.begin());
	const list<int>       a = {2, 3, 0, 0};
  ASSERT_TRUE(equal(y.begin(), y.end(), a.begin()));}

TEST(Integer, shift_left_digits3 ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
  vector<int>           y(8);
  shift_left_digits(x.begin()+3, x.begin()+6, 5, y.begin());
  const list<int>       a = {4, 5, 6, 0, 0, 0, 0, 0};
  ASSERT_TRUE(equal(y.begin(), y.end(), a.begin()));}

TEST(Integer, shift_left_digits4 ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
  vector<int>           y(1);
  shift_left_digits(x.begin(), x.begin(), 1, y.begin());
	const list<int>       a = {0};
  ASSERT_TRUE(equal(y.begin(), y.end(), a.begin()));}

// ------------------
// shift_right_digits
// ------------------

TEST(Integer, shift_right_digits ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
  vector<int>				y(4);
  shift_right_digits(x.begin(), x.end(), 2, y.begin());
	const list<int>       a = {1, 2, 3, 4};
  ASSERT_TRUE(equal(y.begin(), y.end(), a.begin()));}

TEST(Integer, shift_right_digits2 ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
  vector<int>           y(1);
  shift_right_digits(x.begin()+1, x.begin()+3, 2, y.begin());
	const list<int>       a = {0};
    
    ASSERT_TRUE(equal(y.begin(), y.end(), a.begin()));}

TEST(Integer, shift_right_digits3 ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
  vector<int>           y(2);
  shift_right_digits(x.begin(), x.begin()+5, 3, y.begin());
	const list<int>       a = {1, 2};
  ASSERT_TRUE(equal(y.begin(), y.end(), a.begin()));}

TEST(Integer, shift_right_digits4 ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
  vector<int>           y(1);
  shift_right_digits(x.begin(), x.begin()+1, 1, y.begin());
	const list<int>       a = {0};
  ASSERT_TRUE(equal(y.begin(), y.end(), a.begin()));}


// -----------
// plus_digits
// -----------

TEST(Integer, plus_digits ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
  const vector<int>		y = {0, 0, 0, 0, 0, 0};
  vector<int>				z(6);
  plus_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
	const list<int>       a = {1, 2, 3, 4, 5, 6};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, plus_digits2 ) {
	const vector<int>       x = {1, 2, 3};
  const vector<int>		y = {4, 5, 6};
  vector<int>				z(3);
  plus_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
	const list<int>       a = {5, 7, 9};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, plus_digits3 ) {
	const vector<int>       x = {1, 2};
  const vector<int>		y = {4, 5, 6};
  vector<int>				z(3);
  plus_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
	const list<int>       a = {4, 6, 8};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, plus_digits4 ) {
	const vector<int>       x = {1, 2, 3};
  const vector<int>		y = {4, 5};
  vector<int>				z(3);
  plus_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
	const list<int>       a = {1, 6, 8};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, plus_digits5 ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
  const vector<int>		y = {4, 5};
  vector<int>				z(3);
  plus_digits(x.begin()+2, x.begin()+5, y.begin(), y.end(), z.begin());
	const list<int>       a = {3, 9, 0};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, plus_digits6 ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
  const vector<int>		y = {4, 5, 6, 7, 8, 9};
  vector<int>				z(3);
  plus_digits(x.begin()+2, x.begin()+5, y.begin()+4, y.end(), z.begin());
	const list<int>       a = {4, 3, 4};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}
TEST(Integer, plus_digits7 ) {
  const vector<int>       x = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1};
  const vector<int>   y = {4, 5, 6, 7, 8, 9};
  vector<int>       z(84);
  plus_digits(x.begin(), x.end(), y.begin()+4, y.end(), z.begin());
  const list<int>       a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 9, 0};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}
// ------------
// minus_digits
// ------------

TEST(Integer, minus_digits ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
  const vector<int>		y = {0, 0, 0, 0, 0, 0};
  vector<int>				z(6);
  minus_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
	const list<int>       a = {1, 2, 3, 4, 5, 6};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, minus_digits2 ) {
	const vector<int>       x = {4, 5, 6};
  const vector<int>		y = {1, 2, 3};
  vector<int>				z(3);
  minus_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
	const list<int>       a = {3, 3, 3};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, minus_digits3 ) {
	const vector<int>       x = {4, 5, 6};
  const vector<int>		y = {1, 2};
  vector<int>				z(3);
  minus_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
	const list<int>       a = {4, 4, 4};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, minus_digits4 ) {
	const vector<int>       x = {1, 2, 3};
  const vector<int>		y = {4, 5};
  vector<int>				z(2);
  minus_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
	const list<int>       a = {7, 8};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, minus_digits5 ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
  const vector<int>		y = {4, 5};
  vector<int>				z(3);
  minus_digits(x.begin()+2, x.begin()+5, y.begin(), y.end(), z.begin());
	const list<int>       a = {3, 0, 0};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, minus_digits6 ) {
	const vector<int>       x = {4, 2, 3, 4, 5, 6};
  const vector<int>		y = {1, 5, 6, 7, 8, 9};
  vector<int>				z(3);
  minus_digits(x.begin()+2, x.begin()+5, y.begin()+4, y.end(), z.begin());
	const list<int>       a = {2, 5, 6};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}


// -----------------
// multiplies_digits
// -----------------

TEST(Integer, multiplies_digits ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
  const vector<int>		y = {0, 0, 0, 0, 0, 0};
  vector<int>				z(1);
  multiplies_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
	const list<int>       a = {0};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, multiplies_digits2 ) {
	const vector<int>       x = {1, 2, 3};
  const vector<int>		y = {4, 5, 6};
  vector<int>				z(5);
  multiplies_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
	const list<int>       a = {5, 6, 0, 8, 8};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, multiplies_digits3 ) {
	const vector<int>       x = {1, 2};
  const vector<int>		y = {4, 5, 6};
  vector<int>				z(4);
  multiplies_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
	const list<int>       a = {5, 4, 7, 2};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, multiplies_digits4 ) {
	const vector<int>       x = {1, 2, 3};
  const vector<int>		y = {4, 5};
  vector<int>				z(4);
  multiplies_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
	const list<int>       a = {5, 5, 3, 5};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, multiplies_digits5 ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
  const vector<int>		y = {4, 5};
  vector<int>				z(5);
  multiplies_digits(x.begin()+2, x.begin()+5, y.begin(), y.end(), z.begin());
	const list<int>       a = {1, 5, 5, 2, 5};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, multiplies_digits6 ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
  const vector<int>		y = {4, 5, 6, 7, 8, 9};
  vector<int>				z(5);
  multiplies_digits(x.begin()+2, x.begin()+5, y.begin()+4, y.end(), z.begin());
	const list<int>       a = {3, 0, 7, 0, 5};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}


// --------------
// divides_digits
// --------------

TEST(Integer, divides_digits ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
  const vector<int>		y = {0, 0, 0, 0, 0, 1};
  vector<int>				z(6);
  divides_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
	const list<int>       a = {1, 2, 3, 4, 5, 6};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, divides_digits2 ) {
	const vector<int>       x = {1, 2, 3};
  const vector<int>		y = {4, 5, 6};
  vector<int>				z(1);
  divides_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
	const list<int>       a = {0};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, divides_digits3 ) {
	const vector<int>       x = {4, 5, 6};
  const vector<int>		y = {4, 5, 6};
  vector<int>				z(1);
  divides_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
	const list<int>       a = {1};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, divides_digits4 ) {
	const vector<int>       x = {1, 2, 3};
  const vector<int>		y = {4, 5};
  vector<int>				z(1);
  divides_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
	const list<int>       a = {2};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, divides_digits5 ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
  const vector<int>		y = {4, 5};
  vector<int>				z(1);
  divides_digits(x.begin()+2, x.begin()+5, y.begin(), y.end(), z.begin());
	const list<int>       a = {7};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, divides_digits6 ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
  const vector<int>		y = {4, 5, 6, 7, 8, 9};
  vector<int>				z(1);
  divides_digits(x.begin()+2, x.begin()+5, y.begin()+4, y.end(), z.begin());
	const list<int>       a = {3};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}


// -----------
// operator ==
// -----------

TEST(Integer, equal_to) {
  Integer<int> x(1);
  Integer<int> y(1);
  ASSERT_TRUE(x == y);
  ASSERT_TRUE(x == 1);
  ASSERT_TRUE(1 == y);
  ASSERT_TRUE((1 == 1));}


TEST(Integer, equal_to2) {
  Integer<int> x = 123;
  Integer<int> y = 123;
  ASSERT_TRUE(x == y);
  ASSERT_TRUE(x == 123);
  ASSERT_TRUE(123 == y);
  ASSERT_FALSE((x != y));}

TEST(Integer, equal_to3) {
  Integer<int> x = 23;
  Integer<int> y = -23;
  ASSERT_FALSE(x == y);
  ASSERT_FALSE(x == -23);
  ASSERT_FALSE(-23 == x);
  ASSERT_TRUE((x != y));}

TEST(Integer, equal_to4) {
  const Integer<int> x(2300000000000);
  const Integer<int> y = -23;
  ASSERT_FALSE(y == x);
  ASSERT_FALSE(x == -23);
  ASSERT_FALSE(-23 == x);
  ASSERT_TRUE((x != y));}

TEST(Integer, equal_to5) {
  const Integer<int> x(2300000000000);
  const Integer<int> y = 12300000000000000;
  ASSERT_FALSE(y == x);
  ASSERT_FALSE(x == -23);
  ASSERT_FALSE(-23 == x);
  ASSERT_TRUE((x != y));}
/*TEST(Integer, equal_to4) {
  Integer<int> x("1");
  Integer<int> y("1");
  ASSERT_TRUE(x == y);
  ASSERT_TRUE(x == 1);
  ASSERT_TRUE(1 == y);
  ASSERT_TRUE((1 == 1));}

TEST(Integer, equal_to5) {
  const Integer<int> x("123");
  const Integer<int> y("123");
  ASSERT_TRUE(x == y);
  ASSERT_TRUE(x == 123);
  ASSERT_TRUE(123 == y);
  ASSERT_FALSE((x != y));}

TEST(Integer, equal_to6) {
  const Integer<int> x("-23");
  const Integer<int> y("-23");
  ASSERT_TRUE(x == y);
  ASSERT_TRUE(x == -23);
  ASSERT_TRUE(-23 == x);
  ASSERT_FALSE((x != y));}
// ----------
// operator <
// ----------


TEST(Integer, less_than) {
  const Integer<int> x = 5;
  const Integer<int> y = 0;
  ASSERT_TRUE(y < x);}

TEST(Integer, less_than2) {
  const Integer<int> x = -125;
  const Integer<int> y = -125;
  ASSERT_TRUE(x < y);}

TEST(Integer, less_than3) {
  const Integer<int> x = 100;
  const Integer<int> y = 100;
  ASSERT_FALSE(x < y);}

TEST(Integer, less_than4) {
  const Integer<int> x = 2000000000;
  const Integer<int> y = 100;
  ASSERT_FALSE(x < y);}


//-----------
// operator -
//-----------

TEST(Integer, negation) {
    Integer<int> a = 10;
    Integer<int> r = -10;
    a = -a;
    ASSERT_EQ(a, r);}

TEST(Integer, negation2) {
    Integer<int> a("10");
    Integer<int> r = -10;
    a = -a;
    ASSERT_EQ(a, r);}

TEST(Integer, negation3) {
    Integer<int> a = -10;
    Integer<int> r = -10;
    a = -a;
    ASSERT_EQ(r, a);}
TEST(Integer, negation4) {
    Integer<int> a("10");
    Integer<int> r("-10");
    a = -a; 
    ASSERT_EQ(a, r);
}
*/