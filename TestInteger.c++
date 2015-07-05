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
    vector<int>::iterator p = shift_left_digits(x.begin(), x.end(), 2, y.begin());
	const list<int>       a = {1, 2, 3, 4, 5, 6, 0, 0};
    ASSERT_TRUE(equal(a.begin(), a.end(), y.begin()));}

TEST(Integer, shift_left_digits2 ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
    vector<int>           y(4);
    vector<int>::iterator p = shift_left_digits(x.begin()+1, x.begin()+3, 2, y.begin());
	const list<int>       a = {2, 3, 0, 0};
    ASSERT_TRUE(equal(y.begin(), y.end(), a.begin()));}

TEST(Integer, shift_left_digits3 ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
    vector<int>           y(8);
    vector<int>::iterator p = shift_left_digits(x.begin()+3, x.begin()+6, 5, y.begin());
	const list<int>       a = {4, 5, 6, 0, 0, 0, 0, 0};
    ASSERT_TRUE(equal(y.begin(), y.end(), a.begin()));}

TEST(Integer, shift_left_digits4 ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
    vector<int>           y(1);
    vector<int>::iterator p = shift_left_digits(x.begin(), x.begin(), 1, y.begin());
	const list<int>       a = {0};
    ASSERT_TRUE(equal(y.begin(), y.end(), a.begin()));}

// ------------------
// shift_right_digits
// ------------------

TEST(Integer, shift_right_digits ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
    vector<int>				y(6);
    vector<int>::iterator p = shift_right_digits(x.begin(), x.end(), 2, y.begin());
	const list<int>       a = {0, 0, 1, 2, 3, 4};
    ASSERT_TRUE(equal(y.begin(), y.end(), a.begin()));}

TEST(Integer, shift_right_digits2 ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
    vector<int>           y(2);
    vector<int>::iterator p = shift_right_digits(x.begin()+1, x.begin()+3, 2, y.begin());
	const list<int>       a = {0, 0};
    ASSERT_TRUE(equal(y.begin(), y.end(), a.begin()));}

TEST(Integer, shift_right_digits3 ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
    vector<int>           y(5);
    vector<int>::iterator p = shift_right_digits(x.begin(), x.begin()+5, 3, y.begin());
	const list<int>       a = {0, 0, 0, 1, 2};
    ASSERT_TRUE(equal(y.begin(), y.end(), a.begin()));}

TEST(Integer, shift_right_digits4 ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
    vector<int>           y(1);
    vector<int>::iterator p = shift_right_digits(x.begin(), x.begin()+1, 1, y.begin());
	const list<int>       a = {0};
    ASSERT_TRUE(equal(y.begin(), y.end(), a.begin()));}


// -----------
// plus_digits
// -----------

TEST(Integer, plus_digits ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
    const vector<int>		y = {0, 0, 0, 0, 0, 0};
    vector<int>				z(6);
    vector<int>::iterator p = plus_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
	const list<int>       a = {1, 2, 3, 4, 5, 6};
    ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, plus_digits2 ) {
	const vector<int>       x = {1, 2, 3};
    const vector<int>		y = {4, 5, 6};
    vector<int>				z(3);
    vector<int>::iterator p = plus_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
	const list<int>       a = {5, 7, 9};
    ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, plus_digits3 ) {
	const vector<int>       x = {1, 2};
    const vector<int>		y = {4, 5, 6};
    vector<int>				z(3);
    vector<int>::iterator p = plus_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
	const list<int>       a = {4, 6, 8};
    ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, plus_digits4 ) {
	const vector<int>       x = {1, 2, 3};
    const vector<int>		y = {4, 5};
    vector<int>				z(3);
    vector<int>::iterator p = plus_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
	const list<int>       a = {1, 6, 8};
    ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, plus_digits5 ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
    const vector<int>		y = {4, 5};
    vector<int>				z(3);
    vector<int>::iterator p = plus_digits(x.begin()+2, x.begin()+5, y.begin(), y.end(), z.begin());
	const list<int>       a = {3, 9, 0};
    ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, plus_digits6 ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
    const vector<int>		y = {4, 5, 6, 7, 8, 9};
    vector<int>				z(3);
    vector<int>::iterator p = plus_digits(x.begin()+2, x.begin()+5, y.begin()+4, y.end(), z.begin());
	const list<int>       a = {4, 3, 4};
    ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}
// ------------
// minus_digits
// ------------

TEST(Integer, minus_digits ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
    const vector<int>		y = {0, 0, 0, 0, 0, 0};
    vector<int>				z(6);
    vector<int>::iterator p = minus_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
	const list<int>       a = {1, 2, 3, 4, 5, 6};
    ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, minus_digits2 ) {
	const vector<int>       x = {4, 5, 6};
    const vector<int>		y = {1, 2, 3};
    vector<int>				z(3);
    vector<int>::iterator p = minus_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
	const list<int>       a = {3, 3, 3};
    ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, minus_digits3 ) {
	const vector<int>       x = {4, 5, 6};
    const vector<int>		y = {1, 2};
    vector<int>				z(3);
    vector<int>::iterator p = minus_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
	const list<int>       a = {4, 4, 4};
    ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, minus_digits4 ) {
	const vector<int>       x = {1, 2, 3};
    const vector<int>		y = {4, 5};
    vector<int>				z(2);
    vector<int>::iterator p = minus_digits(x.begin(), x.end(), y.begin(), y.end(), z.begin());
	const list<int>       a = {7, 8};
    ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, minus_digits5 ) {
	const vector<int>       x = {1, 2, 3, 4, 5, 6};
    const vector<int>		y = {4, 5};
    vector<int>				z(3);
    vector<int>::iterator p = minus_digits(x.begin()+2, x.begin()+5, y.begin(), y.end(), z.begin());
	const list<int>       a = {3, 0, 0};
    ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}

TEST(Integer, minus_digits6 ) {
	const vector<int>       x = {4, 2, 3, 4, 5, 6};
    const vector<int>		y = {1, 5, 6, 7, 8, 9};
    vector<int>				z(3);
    vector<int>::iterator p = minus_digits(x.begin()+2, x.begin()+5, y.begin()+4, y.end(), z.begin());
	const list<int>       a = {2, 5, 6};
    ASSERT_TRUE(equal(z.begin(), z.end(), a.begin()));}


// -----------------
// multiplies_digits
// -----------------

TEST(Integer, multiplies_digits ) {
  ASSERT_EQ(0, 0);}


// --------------
// divides_digits
// --------------

TEST(Integer, divides_digits ) {
  ASSERT_EQ(0, 0);}


