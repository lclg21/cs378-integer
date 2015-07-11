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
  vector<int>       y(4);
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
  const vector<int>   y = {0, 0, 0, 0, 0, 0};
  vector<int>       z(6);
  plus_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
  const list<int>       a = {1, 2, 3, 4, 5, 6};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, plus_digits2 ) {
  const vector<int>       x = {1, 2, 3};
  const vector<int>   y = {4, 5, 6};
  vector<int>       z(3);
  plus_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
  const list<int>       a = {5, 7, 9};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, plus_digits3 ) {
  const vector<int>       x = {1, 2};
  const vector<int>   y = {4, 5, 6};
  vector<int>       z(3);
  plus_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
  const list<int>       a = {4, 6, 8};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, plus_digits4 ) {
  const vector<int>       x = {1, 2, 3};
  const vector<int>   y = {4, 5};
  vector<int>       z(3);
  plus_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
  const list<int>       a = {1, 6, 8};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, plus_digits5 ) {
  const vector<int>       x = {1, 2, 3, 4, 5, 6};
  const vector<int>   y = {4, 5};
  vector<int>       z(3);
  plus_digits(x.begin()+2, x.begin()+5, y.begin(), y.end(), z.begin());
  const list<int>       a = {3, 9, 0};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, plus_digits6 ) {
  const vector<int>       x = {1, 2, 3, 4, 5, 6};
  const vector<int>   y = {4, 5, 6, 7, 8, 9};
  vector<int>       z(3);
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

TEST(Integer, plus_digits8 ) {
  const vector<int>   x = {9, 9, 9};
  const vector<int>   y = {4, 5, 6};
  vector<int>       z(4);
  plus_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
  const list<int>       a = {1, 4, 5, 5};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}


// ------------
// minus_digits
// ------------

TEST(Integer, minus_digits ) {
  const vector<int>       x = {1, 2, 3, 4, 5, 6};
  const vector<int>   y = {0, 0, 0, 0, 0, 0};
  vector<int>       z(6);
  minus_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
  const list<int>       a = {1, 2, 3, 4, 5, 6};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, minus_digits2 ) {
  const vector<int>       x = {4, 5, 6};
  const vector<int>   y = {1, 2, 3};
  vector<int>       z(3);
  minus_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
  const list<int>       a = {3, 3, 3};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, minus_digits3 ) {
  const vector<int>       x = {4, 5, 6};
  const vector<int>   y = {1, 2};
  vector<int>       z(3);
  minus_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
  const list<int>       a = {4, 4, 4};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, minus_digits4 ) {
  const vector<int>       x = {1, 2, 3, 4, 5, 6};
  const vector<int>   y = {4, 5};
  vector<int>       z(3);
  minus_digits(x.begin()+2, x.begin()+5, y.begin(), y.end(), z.begin());
  const list<int>       a = {3, 0, 0};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, minus_digits5 ) {
  const vector<int>       x = {4, 2, 3, 4, 5, 6};
  const vector<int>   y = {1, 5, 6, 7, 8, 9};
  vector<int>       z(3);
  minus_digits(x.begin()+2, x.begin()+5, y.begin()+4, y.end(), z.begin());
  const list<int>       a = {2, 5, 6};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}


// -----------------
// multiplies_digits
// -----------------

  TEST(Integer, multiplies_digits ) {
  const vector<int>       x = {2, 3, 9};
  const vector<int>   y = {1, 2};
  vector<int>       z(4);
  multiplies_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
  const list<int>       a = {2, 8, 6, 8};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}
  
  TEST(Integer, multiplies_digits2 ) {
  const vector<int>       x = {1, 2, 3, 4, 5, 6};
  const vector<int>   y = {0};
  vector<int>       z(1);
  multiplies_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
  const list<int>       a = {0};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, multiplies_digits3 ) {
  const vector<int>       x = {1, 2, 3};
  const vector<int>   y = {4, 5, 6};
  vector<int>       z(5);
  multiplies_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
  const list<int>       a = {5, 6, 0, 8, 8};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, multiplies_digits4 ) {
  const vector<int>       x = {1, 2};
  const vector<int>   y = {4, 5, 6};
  vector<int>       z(4);
  multiplies_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
  const list<int>       a = {5, 4, 7, 2};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, multiplies_digits5 ) {
  const vector<int>       x = {1, 2, 3};
  const vector<int>   y = {4, 5};
  vector<int>       z(4);
  multiplies_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
  const list<int>       a = {5, 5, 3, 5};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, multiplies_digits6 ) {
  const vector<int>       x = {1, 2, 3, 4, 5, 6};
  const vector<int>   y = {4, 5};
  vector<int>       z(5);
  multiplies_digits(x.begin()+2, x.begin()+5, y.begin(), y.end(), z.begin());
  const list<int>       a = {1, 5, 5, 2, 5};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, multiplies_digits7 ) {
  const vector<int>       x = {1, 2, 3, 4, 5, 6};
  const vector<int>   y = {4, 5, 6, 7, 8, 9};
  vector<int>       z(5);
  multiplies_digits(x.begin()+2, x.begin()+5, y.begin()+4, y.end(), z.begin());
  const list<int>       a = {3, 0, 7, 0, 5};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, multiplies_digits8 ) {
  const vector<int>       x = {1, 2, 3, 4, 5, 6};
  const vector<int>   y = {4, 5};
  vector<int>       z(7);
  multiplies_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
  const list<int>       a = {5, 5, 5, 5, 5, 2, 0};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}



// --------------
// divides_digits
// --------------

TEST(Integer, divides_digits ) {
  const vector<int>       x = {1, 2, 3, 4, 5, 6};
  const vector<int>   y = {0, 0, 0, 0, 0, 1};
  vector<int>       z(6);
  divides_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
  const list<int>       a = {1, 2, 3, 4, 5, 6};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, divides_digits2 ) {
  const vector<int>       x = {1, 2, 3};
  const vector<int>   y = {4, 5, 6};
  vector<int>       z(1);
  divides_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
  const list<int>       a = {0};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, divides_digits3 ) {
  const vector<int>       x = {4, 5, 6};
  const vector<int>   y = {4, 5, 6};
  vector<int>       z(1);
  divides_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
  const list<int>       a = {1};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, divides_digits4 ) {
  const vector<int>       x = {1, 2, 3};
  const vector<int>   y = {4, 5};
  vector<int>       z(1);
  divides_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
  const list<int>       a = {2};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, divides_digits5 ) {
  const vector<int>       x = {1, 2, 3, 4, 5, 6};
  const vector<int>   y = {4, 5};
  vector<int>       z(1);
  divides_digits(x.begin()+2, x.begin()+5, y.begin(), y.end(), z.begin());
  const list<int>       a = {7};
  ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, divides_digits6 ) {
  const vector<int>       x = {1, 2, 3, 4, 5, 6};
  const vector<int>   y = {4, 5, 6, 7, 8, 9};
  vector<int>       z(1);
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

TEST(Integer, equal_to6) {
  const Integer<int> x("1");
  const Integer<int> y = 1;
  ASSERT_TRUE(x == y);
  ASSERT_FALSE(x != y);}


TEST(Integer, equal_to7) {
  const Integer<int> x ("123");
  const Integer<int> y ("123");
  ASSERT_TRUE(x == y);
  ASSERT_FALSE((x != y));}

TEST(Integer, equal_to8) {
  const Integer<int> x("-23000000000000000000000000");
  const Integer<int> y("-23000000000000000000000000");
  ASSERT_TRUE(x == y);
  ASSERT_FALSE((x != y));}

TEST(Integer, equal_to9) {
  const Integer<int> x("-23000000000000000000000000");
  const Integer<int> y("23000000000000000000000000");
  ASSERT_FALSE(x == y);
  ASSERT_TRUE(x != y);}

// ----------
// operator <
// ----------

TEST(Integer, less_than) {
  const Integer<int> x("5");
  const Integer<int> y("1");
  ASSERT_TRUE(y < x);}

TEST(Integer, less_than2) {
  const Integer<int> x = -125;
  const Integer<int> y = -125;
  ASSERT_FALSE(x < y);}

TEST(Integer, less_than3) {
  const Integer<int> x = 100;
  const Integer<int> y = 100;
  ASSERT_FALSE(x < y);}

TEST(Integer, less_than4) {
  const Integer<int> x = 2000000000;
  const Integer<int> y = 100;
  ASSERT_FALSE(x < y);}

TEST(Integer, less_than5) {
  const Integer<int> x("-5");
  const Integer<int> y("-1");
  ASSERT_FALSE(y < x);}

TEST(Integer, less_than6) {
  const Integer<int> x("-50000");
  const Integer<int> y("-1");
  ASSERT_FALSE(y < x);}

TEST(Integer, less_than7) {
  const Integer<int> x("50000");
  const Integer<int> y("1");
  ASSERT_TRUE(y < x);}

TEST(Integer, less_than8) {
  const Integer<int> x("5");
  const Integer<int> y("-1");
  ASSERT_TRUE(y < x);}

TEST(Integer, less_than9) {
  const Integer<int> x("-5");
  const Integer<int> y("1");
  ASSERT_FALSE(y < x);}

TEST(Integer, less_than10) {
  const Integer<int> x("-5");
  const Integer<int> y("0");
  ASSERT_FALSE(y < x);}

TEST(Integer, less_than11) {
  const Integer<int> x = 2000000000;
  const Integer<int> y = -100;
  ASSERT_FALSE(x < y);}

TEST(Integer, less_than12) {
  const Integer<int> x = -2000000000;
  const Integer<int> y = -100;
  ASSERT_TRUE(x < y);}

TEST(Integer, less_than13) {
  const Integer<int> x = -2000000000;
  const Integer<int> y("-100");
  ASSERT_TRUE(x < y);}


//-----------
// operator -(negation)
//-----------

TEST(Integer, negation) {
    Integer<int> a = 10;
    Integer<int> r = -10;
    a = -a;
    ASSERT_EQ(a, r);}

TEST(Integer, negation2) {
    Integer<int> a("-10");
    Integer<int> r("10");
    a = -a;
    ASSERT_EQ(a, r);}

TEST(Integer, negation3) {
    Integer<int> a = -10;
    Integer<int> r = 10;
    a = -a;
    ASSERT_EQ(r, a);}

TEST(Integer, negation4) {
    Integer<int> a("10");
    Integer<int> r("-10");
    a = -a; 
    ASSERT_EQ(a, r);
}

TEST(Integer, negation5) {
    Integer<int> a("10");
    Integer<int> r = -10;
    a = -a; 
    ASSERT_EQ(a, r);
}


//-----------
// abs
//-----------


TEST(Integer, abs1) {
    Integer<int> a = -10;
    Integer<int> r = 10;
    a = abs(a);
    ASSERT_EQ(a, r);}

TEST(Integer, abs2) {
    Integer<int> a("-10");
    Integer<int> r("10");
    a = abs(a);
    ASSERT_EQ(a, r);}

TEST(Integer, abs3) {
    Integer<int> a = 10;
    Integer<int> r = 10;
    a = abs(a);
    ASSERT_EQ(a, r);}

TEST(Integer, abs4) {
    Integer<int> a("10");
    Integer<int> r("10");
    a = abs(a);
    ASSERT_EQ(a, r);}


//---------
// ostream
//---------

TEST(Integer, ostream1) {
    ostringstream w;
    Integer<int> n("0");
    w << n << endl;
    ASSERT_EQ("0\n", w.str());}

TEST(Integer, ostream2) {
    ostringstream w;
    Integer<int> n("154321");
    w << n << endl;
    ASSERT_EQ("154321\n", w.str());}

TEST(Integer, ostream3) {
    ostringstream w;
    Integer<int> n("-5000");
    w << n << endl;
    ASSERT_EQ("-5000\n", w.str());
}

TEST(Integer, ostream4) {
    ostringstream w;
    Integer<int> n("654035125304053241654032165347053035470354158054325470641");
    w << n << endl;
    ASSERT_EQ("654035125304053241654032165347053035470354158054325470641\n", w.str());
}

TEST(Integer, ostream5) {
    ostringstream w;
    Integer<int> n("-215204524605487065486704654864703543720647867086786745346540231523745312300000");
    w << n << endl;
    ASSERT_EQ("-215204524605487065486704654864703543720647867086786745346540231523745312300000\n", w.str());}

TEST(Integer, ostream6) {
    ostringstream w;
    Integer<int> n = 154321;
    w << n << endl;
    ASSERT_EQ("154321\n", w.str());}


//-------------
// operator <<=
//-------------

TEST(Integer, left_shift_equals) {
    Integer<int> a("1");
    int n = 3;
    a <<= n;
    Integer<int> b("1000");
    ASSERT_EQ(b, a);}

TEST(Integer, left_shift_equals2) {
    Integer<int> a("141540");
    int n = 50;
    a <<= n;
    Integer<int> b("14154000000000000000000000000000000000000000000000000000");
    ASSERT_EQ(b, a);}

TEST(Integer, left_shift_equals3) {
    Integer<int> a("88888888888888888888888888888888888888888888888");
    int n = -45;
    a <<= n;
    Integer<int> b("88");
    ASSERT_EQ(b, a);}

TEST(Integer, left_shift_equals4) {
    Integer<int> a("88888888888888888888888888888888888888888888888");
    int n = -45;
    a <<= n;
    Integer<int> b = 88;
    ASSERT_EQ(b, a);}

TEST(Integer, left_shift_equals5) {
    Integer<int> a = 141540;
    int n = 50;
    a <<= n;
    Integer<int> b("14154000000000000000000000000000000000000000000000000000");
    ASSERT_EQ(b, a);}


//-------------
// operator >>=
//-------------

TEST(Integer, right_shift_equals) {
    Integer<int> a("1000");
    int n = 3;
    a >>= n;
    Integer<int> b("1");
    ASSERT_EQ(b, a);}

TEST(Integer, right_shift_equals2) {
    Integer<int> a("14154000000000000000000000000000000000000000000000000000");
    int n = 50;
    a >>= n;
    Integer<int> b("141540");
    ASSERT_EQ(b, a);}

TEST(Integer, right_shift_equals3) {
    Integer<int> a("14545513");
    int n = -3;
    a >>= n;
    Integer<int> b("14545513000");
    ASSERT_EQ(b, a);}

TEST(Integer, right_shift_equals4) {
    Integer<int> a = 1000;
    int n = 3;
    a >>= n;
    Integer<int> b = 1;
    ASSERT_EQ(b, a);}

TEST(Integer, right_shift_equals5) {
    Integer<int> a = 1000;
    int n = 3;
    a >>= n;
    Integer<int> b("1");
    ASSERT_EQ(b, a);}


// -----------
// operator *=
// -----------

TEST(Integer, test_mult_eq_1) {
    Integer<int> n(12);
    n *= 5;
    Integer<int> w("60");
    ASSERT_EQ(w, n);}

TEST(Integer, test_mult_eq_2) {
    Integer<int> n1("-5000000000");
    Integer<int> n2("400000000");
    n1 *= n2;
    Integer<int> w("-2000000000000000000");
    ASSERT_EQ(w, n1);}

TEST(Integer, test_mult_eq_3) {
    Integer<int> n1(11);
    Integer<int> n2(11);
    n1 *= n2;
    Integer<int> w(121);
    ASSERT_EQ(w, n1);}


TEST(Integer, test_mult_eq_4) {
    Integer<int> a(8);
    Integer<int> b(64);
    a *= b;;
    Integer<int> w(512);
    ASSERT_EQ(w, a);}

//------------
// operator /=
//------------

// TEST(Integer, divide_equals) {
//     Integer<int> n(9);
//     n /= 3;
//     Integer<int> w("3");
//     ASSERT_EQ(w, n);}

// TEST(Integer, divide_equals2) {
//     Integer<int> n(100);
//     n /= 1;
//     Integer<int> w = 100;
//     ASSERT_EQ(w, n);}

// TEST(Integer, divide_equals3) {
//     Integer<int> n(25);
//     n /= 5;
//     Integer<int> w = 5;
//     ASSERT_EQ(w, n);}
//------------
// operator += 
//------------

TEST(Integer, plus_equals) {
    Integer<int> a(24);
    Integer<int> b(15);
    a += b;
    ASSERT_EQ(a, 39);}

TEST(Integer, plus_equals2) {
    Integer<int> a(-24);
    Integer<int> b(-15);
    a += b;
    ASSERT_EQ(a, -39);}

TEST(Integer, plus_equals3) {
    Integer<int> a(2412);
    Integer<int> b(15);
    a += b;
    ASSERT_EQ(a, 2427);}

TEST(Integer, plus_equals4) {
    Integer<int> a(24);
    Integer<int> b(1512);
    a += b;
    ASSERT_EQ(a, 1536);}

TEST(Integer, plus_equals5) {
    Integer<int> a(8);
    Integer<int> b(9);
    a += b;
    ASSERT_EQ(a, 17);}

//------------
// operator -= 
//------------

TEST(Integer, minus_equals) {
    Integer<int> a(20);
    Integer<int> b(5);
    a -= b;
    ASSERT_EQ(a, 15);}


TEST(Integer, minus_equals2) {
    Integer<int> a(-2);
    Integer<int> b(7);
    a -= b;
    ASSERT_EQ(a, -9);}

TEST(Integer, minus_equals3) {
    Integer<int> a(20);
    Integer<int> b(-10);
    a -= b;
    ASSERT_EQ(a, 30);}


//----
// pow
//----

TEST(Integer, pow) {
    Integer<int> a = 2;
    int b = 3;
    Integer<int> r = 8;
    a = a.pow(b);
    ASSERT_EQ(a, r);
}
TEST(Integer,pow2) {
   Integer<int> a = 1;
   int p = -1;
   bool got_exception = false;
   try {
       Integer<int> b = pow(a, p);
   } catch (std::invalid_argument ia) {
       got_exception = true;
   }
   ASSERT_EQ(true, got_exception);}

TEST(Integer, pow3) {
   Integer<int> a = 3;
   int b = 4;
   Integer<int> r = 81;
   a = a.pow(b);
   ASSERT_EQ(a, r);}

TEST(Integer, pow4) {
   Integer<int> a = 1000;
   int b = 0;
   Integer<int> r = 1;
   a = a.pow(b);
   ASSERT_EQ(a, r);}

TEST(Integer, pow5) {
   Integer<int> a = 2;
   int b = 2;
   Integer<int> r = 4;
   a = a.pow(b);
   ASSERT_EQ(a, r);}

TEST(Integer, pow6) {
   Integer<int> a("5");
   int b = 9;
   Integer<int> r = 1953125;
   a = a.pow(b);
   ASSERT_EQ(a, r);}

TEST(Integer, pow7) {
   Integer<int> a = 10;
   int p = 10;
   Integer<int> b = pow(a, p);
   ostringstream b_out;
   b_out << b;
   string expected = "1";
   for (int i = 0; i < p; ++i) {
       expected += "0";
   }
   ASSERT_EQ(expected, b_out.str());}

TEST(Integer, pow8) {
   Integer<int> a = 10;
   int p = 1000;
   Integer<int> b = pow(a, p);
   ostringstream b_out;
   b_out << b;
   string expected = "1";
   for (int i = 0; i < p; ++i) {
       expected += "0";
   }
   ASSERT_EQ(expected, b_out.str());}



