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
  const int a[] = {1, 2, 3};
  const int b[] = {1, 2, 3, 0, 0, 0};
  int x[10];
  const int* p = shift_left_digits(a, a + 3, 3, x);
  ASSERT_EQ(4, p - x);}


// ------------------
// shift_right_digits
// ------------------

TEST(Integer, shift_right_digits ) {
  ASSERT_EQ(0, 0);}


// -----------
// plus_digits
// -----------

TEST(Integer, plus_digits ) {
  ASSERT_EQ(0, 0);}


// ------------
// minus_digits
// ------------

TEST(Integer, minus_digits ) {
  ASSERT_EQ(0, 0);}




